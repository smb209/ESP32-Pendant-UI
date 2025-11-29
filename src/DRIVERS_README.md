# Hardware Drivers

This directory contains hardware driver implementations for the CNC Pendant UI.

## Architecture

The driver architecture is inspired by the [Knob18Meters](https://github.com/VolosR/Knob18Meters) project and follows these principles:

1. **Separation of concerns**: Each hardware component has its own driver
2. **Hardware abstraction**: Drivers provide a clean interface to main application
3. **LVGL integration**: Drivers integrate directly with LVGL input/output system
4. **Thread safety**: Proper mutex usage for FreeRTOS task management

## Drivers

### Display Driver (`display_driver.cpp`)
- Initializes round LCD display (480x480 or configurable)
- Handles LVGL display buffer and flush callback
- Supports various display controllers (GC9A01, SH8601, etc.)
- Backlight PWM control

**Implementation required:**
- SPI/QSPI initialization for your display controller
- Display-specific initialization commands
- Flush callback to send pixels to display

### Touch Driver (`touch_driver.cpp`)
- Handles capacitive touch controller via I2C
- Supports CST816, FT6336, and similar controllers
- Debouncing and coordinate validation
- LVGL input device integration

**Implementation required:**
- I2C communication with your specific touch controller
- Touch controller initialization sequence
- Coordinate mapping for round display if needed

### Encoder Driver (`encoder_driver.cpp`)
- Rotary encoder input handling
- Button press detection with debouncing
- LVGL encoder input device integration
- Event callbacks for custom handling

**Features:**
- Quadrature encoder decoding
- Debounced button press
- LVGL group navigation support

## Hardware Configuration

Edit `include/hardware_config.h` to match your hardware:

```c
/* Display pins */
#define HW_LCD_PIN_CS        14
#define HW_LCD_PIN_SCLK      13
#define HW_LCD_PIN_MOSI      15
// ... etc

/* Touch pins */
#define HW_TOUCH_I2C_SDA     11
#define HW_TOUCH_I2C_SCL     12

/* Encoder pins */
#define HW_ENCODER_PIN_A     8
#define HW_ENCODER_PIN_B     7
#define HW_ENCODER_PIN_SW    6
```

## Board Presets

Common board configurations can be selected in `hardware_config.h`:

```c
#define HW_BOARD_SEEED_XIAO_ESP32S3_ROUND_DISPLAY
```

Add your own board preset if using custom hardware.

## Implementing Display Driver

For TFT_eSPI library:

```cpp
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

bool display_driver_init(void) {
    tft.begin();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
    
    // ... LVGL setup
    
    return true;
}

static void disp_flush_cb(...) {
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)color_p, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(disp_drv);
}
```

For ESP-IDF LCD Panel API:

```cpp
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"

// See esp_lcd_sh8601.c in Knob18Meters for complete example
```

## Implementing Touch Driver

For I2C touch controllers:

```cpp
bool touch_driver_init(void) {
    Wire.begin(HW_TOUCH_I2C_SDA, HW_TOUCH_I2C_SCL);
    Wire.setClock(400000);
    
    // Initialize touch controller
    // Read chip ID, configure settings, etc.
    
    return true;
}

static void touch_read_cb(...) {
    // Read touch points from controller
    // Example: read registers 0x00-0x06
    uint8_t data[7];
    Wire.requestFrom(addr, 7);
    
    // Parse coordinates
    uint16_t x = ((data[1] & 0x0F) << 8) | data[2];
    uint16_t y = ((data[3] & 0x0F) << 8) | data[4];
    
    // Update LVGL data
    data->point.x = x;
    data->point.y = y;
    data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
}
```

## Thread Safety

The main application uses a FreeRTOS task for LVGL updates with mutex protection:

```cpp
static SemaphoreHandle_t lvgl_mutex;

void lvgl_task(void *pvParameter) {
    while(1) {
        if(xSemaphoreTake(lvgl_mutex, portMAX_DELAY) == pdTRUE) {
            lv_timer_handler();
            xSemaphoreGive(lvgl_mutex);
        }
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
```

## Testing Drivers

1. **Display Test**: Should see LVGL screen render
2. **Touch Test**: Touch should trigger LVGL events
3. **Encoder Test**: Rotation should navigate UI, button should activate

Check serial output for driver initialization messages.

## References

- [Knob18Meters](https://github.com/VolosR/Knob18Meters) - ESP32-S3 round display reference
- [LVGL Porting Guide](https://docs.lvgl.io/master/porting/index.html)
- [ESP-IDF LCD Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/lcd.html)
- [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI)
