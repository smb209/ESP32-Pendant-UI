# ESP32-S3 CNC Pendant UI

A UI-only project for ESP32-S3 based CNC pendant with round touch LCD and rotary encoder, built using PlatformIO and LVGL.

**Architecture inspired by [Knob18Meters](https://github.com/VolosR/Knob18Meters) project.**

## Project Overview

This is a **UI-only** project - it contains no machine control logic. The UI provides screens for:
- **Main Screen**: Jog controls with Digital Read Out (DRO) for axis positions
- **Macros Screen**: Quick access to common CNC macros (probe, home, zero, etc.)
- **Setup Screen**: Settings and configuration

The project uses XML-based UI definitions (similar to LVGL Editor) that can be converted to C code.

## Features

- ✅ Round 480x480 touch LCD support (configurable)
- ✅ Rotary encoder input for navigation
- ✅ Three main screens (Main/Macros/Setup)
- ✅ **Modular hardware drivers** (display, touch, encoder)
- ✅ **FreeRTOS task management** for LVGL
- ✅ **Thread-safe LVGL operations** with mutex
- ✅ XML-based UI definitions
- ✅ Public API for integration with CNC control logic
- ✅ Generated C code from XML (stub generator included)
- ✅ LVGL 8.3 based UI framework
- ✅ PlatformIO build system
- ✅ Hardware configuration presets
- ✅ No machine control logic (pure UI)

## Project Structure

```
ESP32-Pendant-UI/
├── platformio.ini          # PlatformIO configuration
├── README.md              # This file
├── .gitignore            # Git ignore rules
│
├── include/              # Header files
│   ├── lv_conf.h        # LVGL configuration
│   ├── ui_api.h         # Public UI API header
│   ├── hardware_config.h    # Hardware pin configuration
│   ├── display_driver.h     # Display driver interface
│   ├── touch_driver.h       # Touch driver interface
│   └── encoder_driver.h     # Encoder driver interface
│
├── src/                  # Source files
│   ├── main.cpp         # Main application entry point
│   ├── ui_api.c         # Public UI API implementation
│   ├── display_driver.cpp   # Display hardware driver
│   ├── touch_driver.cpp     # Touch hardware driver
│   ├── encoder_driver.cpp   # Encoder hardware driver
│   └── DRIVERS_README.md    # Driver documentation
│
├── ui/                   # UI definitions and generated code
│   ├── xml/             # XML UI definitions
│   │   ├── project.xml
│   │   ├── globals.xml
│   │   └── screens/
│   │       ├── main.xml     # Main jog/DRO screen
│   │       ├── macros.xml   # Macros screen
│   │       └── setup.xml    # Setup screen
│   │
│   └── generated/       # Generated C code from XML
│       ├── main_screen_gen.h
│       ├── main_screen_gen.c
│       ├── macros_screen_gen.h
│       ├── macros_screen_gen.c
│       ├── setup_screen_gen.h
│       └── setup_screen_gen.c
│
├── scripts/             # Build and generator scripts
│   └── xml_to_c.py     # XML to C converter (stub)
│
├── fonts/               # Custom fonts (if needed)
├── images/              # Images and icons
└── lib/                 # Additional libraries
```

## Hardware Requirements

- **MCU**: ESP32-S3 (DevKitC-1 or compatible)
- **Display**: Round touch LCD (480x480 or 240x240)
  - GC9A01 based displays
  - SH8601 AMOLED displays
  - Other SPI/QSPI round displays
- **Input**: Rotary encoder with push button
- **Optional**: Additional buttons or switches

### Tested/Compatible Boards

- ESP32-S3 DevKitC-1 (generic)
- Seeed Studio XIAO ESP32S3 with Round Display
- Waveshare RP2040-Touch-LCD-1.28 (adapted for ESP32-S3)
- Custom boards with round displays

### Pin Configuration

Edit `include/hardware_config.h` to configure pins for your hardware:

```cpp
/* Display SPI pins */
#define HW_LCD_PIN_CS        14
#define HW_LCD_PIN_SCLK      13
#define HW_LCD_PIN_MOSI      15
#define HW_LCD_PIN_DC        16
#define HW_LCD_PIN_RST       21
#define HW_LCD_PIN_BL        47

/* Touch controller I2C pins */
#define HW_TOUCH_I2C_SDA     11
#define HW_TOUCH_I2C_SCL     12

/* Rotary encoder pins */
#define HW_ENCODER_PIN_A     8
#define HW_ENCODER_PIN_B     7
#define HW_ENCODER_PIN_SW    6
```

Or use a board preset:

```cpp
#define HW_BOARD_SEEED_XIAO_ESP32S3_ROUND_DISPLAY
```

## Software Requirements

- [PlatformIO](https://platformio.org/) (VS Code extension or CLI)
- Python 3.6+ (for XML to C generator)

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/smb209/ESP32-Pendant-UI.git
cd ESP32-Pendant-UI
```

### 2. Install PlatformIO

If using VS Code:
1. Install the PlatformIO IDE extension
2. Open this project folder in VS Code

If using CLI:
```bash
pip install platformio
```

### 3. Build the Project

Using VS Code:
- Click the PlatformIO icon
- Click "Build" under Project Tasks

Using CLI:
```bash
pio run
```

### 4. Upload to ESP32-S3

Using VS Code:
- Click "Upload" under Project Tasks

Using CLI:
```bash
pio run --target upload
```

### 5. Monitor Serial Output

Using VS Code:
- Click "Monitor" under Project Tasks

Using CLI:
```bash
pio device monitor
```

## Using the Public API

The UI provides a clean public API for integration with your CNC control logic. Here's a simple example:

```cpp
#include "ui_api.h"

void setup() {
    // Initialize UI
    ui_init();
    
    // Set up callbacks
    ui_set_macro_callback(my_macro_handler);
    ui_set_settings_save_callback(my_save_handler);
}

void loop() {
    // Update UI (call regularly)
    ui_update(5);
    
    // Update position from your CNC controller
    ui_update_all_positions("123.456", "78.901", "23.456", NULL);
    
    // Update status
    ui_set_status_message("Machining...");
    ui_set_connection_status(true);
}

void my_macro_handler(const char * macro_name) {
    // Handle macro commands
    if(strcmp(macro_name, "HOME_ALL") == 0) {
        // Send home command to CNC controller
    }
}
```

### Available API Functions

See `include/ui_api.h` for complete API documentation:

- `ui_init()` - Initialize UI system
- `ui_update()` - Update UI (call in main loop)
- `ui_load_screen()` - Switch between screens
- `ui_update_position()` - Update axis position display
- `ui_set_status_message()` - Update status message
- `ui_set_connection_status()` - Update connection status
- `ui_set_macro_callback()` - Set macro button callback
- `ui_encoder_input()` - Process encoder rotation
- `ui_encoder_button_pressed()` - Process encoder button press

## Architecture

The project architecture is inspired by the [Knob18Meters](https://github.com/VolosR/Knob18Meters) project with these key improvements:

### Modular Hardware Drivers

Hardware components are separated into individual drivers:

1. **Display Driver** (`display_driver.cpp`)
   - Initializes SPI/QSPI LCD
   - LVGL buffer management
   - Display flush callback
   - Backlight control

2. **Touch Driver** (`touch_driver.cpp`)
   - I2C touch controller (CST816, FT6336, etc.)
   - Touch point reading and validation
   - LVGL input device integration

3. **Encoder Driver** (`encoder_driver.cpp`)
   - Quadrature encoder decoding
   - Button press with debouncing
   - LVGL encoder input device

See `src/DRIVERS_README.md` for detailed driver implementation guide.

### FreeRTOS Task Management

The application uses proper FreeRTOS task management:

```cpp
// LVGL runs in its own task on Core 1
xTaskCreatePinnedToCore(
    lvgl_task,              /* Task function */
    "LVGL",                 /* Name */
    4 * 1024,              /* Stack size */
    NULL,                   /* Parameters */
    2,                      /* Priority */
    NULL,                   /* Handle */
    1                       /* Core 1 */
);
```

### Thread Safety

LVGL operations are protected with mutex:

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

### Hardware Abstraction

All hardware configuration is centralized in `hardware_config.h`:
- Pin definitions
- Board presets
- LVGL settings
- System configuration

This makes it easy to adapt the project to different hardware.

## XML UI Definition Format

The UI is defined using XML files modeled after the [LVGL Editor](https://github.com/lvgl/lvgl_editor) format.

### Example Screen Definition

```xml
<screen name="main">
    <styles>
        <style name="style_panel" 
               bg_color="#secondary_bg" 
               border_width="2" 
               radius="#unit_md" />
    </styles>
    
    <view flex_flow="column" width="100%" height="100%">
        <div width="100%" height="60">
            <style name="style_panel" />
            <lv_label text="CNC Pendant" align="center" />
        </div>
    </view>
</screen>
```

### Generating C Code from XML

Use the provided script to generate C code:

```bash
python scripts/xml_to_c.py ui/xml/screens/main.xml ui/generated/
```

**Note**: The current script is a stub. For a full implementation, refer to the LVGL Editor project.

## Customization

### Adding New Screens

1. Create XML definition in `ui/xml/screens/`
2. Generate C code using `xml_to_c.py`
3. Add screen enum to `ui_api.h`
4. Add case in `ui_load_screen()` in `ui_api.c`

### Modifying Colors and Styles

Edit `ui/xml/globals.xml` to change:
- Color palette
- Spacing units
- Global styles
- Fonts

### Adding Custom Fonts

1. Place font files in `fonts/` directory
2. Define in `ui/xml/globals.xml`:
```xml
<tiny_ttf name="my_font_16" size="16" src_path="fonts/MyFont.ttf" />
```

### Adding Icons/Images

1. Place image files in `images/` directory
2. Define in `ui/xml/globals.xml`:
```xml
<file name="icon_home" src_path="images/icon_home.png" />
```

## Display Driver Integration

The project now includes modular hardware drivers. You need to implement the hardware-specific code for your display.

### For TFT_eSPI Library

Edit `src/display_driver.cpp`:

```cpp
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

bool display_driver_init(void) {
    tft.begin();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
    
    // ... LVGL setup (already in template)
    
    return true;
}

static void disp_flush_cb(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = area->x2 - area->x1 + 1;
    uint32_t h = area->y2 - area->y1 + 1;
    
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)color_p, w * h, true);
    tft.endWrite();
    
    lv_disp_flush_ready(disp);
}
```

### For ESP-IDF LCD Panel API

See `src/DRIVERS_README.md` for ESP-IDF examples similar to Knob18Meters.

### Touch Controller Integration

Edit `src/touch_driver.cpp` to implement I2C communication with your touch controller (CST816, FT6336, etc.). See `src/DRIVERS_README.md` for examples.

## Troubleshooting

### Build Errors

**Error**: `lvgl.h: No such file or directory`
- **Solution**: Clean and rebuild: `pio run -t clean && pio run`

**Error**: `lv_conf.h` not found
- **Solution**: Make sure `include/lv_conf.h` exists and `-Iinclude` is in build flags

**Error**: `display_driver.h: No such file or directory`
- **Solution**: Make sure new driver files are created and included in build

### Display Issues

**Display not working**
- Check pin configuration in `include/hardware_config.h`
- Verify SPI bus configuration
- Implement display driver in `src/display_driver.cpp`
- Check serial output for initialization messages

**Touch not responding**
- Verify I2C pins in `hardware_config.h`
- Check touch controller I2C address (0x15 for CST816)
- Implement touch driver in `src/touch_driver.cpp`
- Enable I2C scanning to detect controller

**Encoder not working**
- Check encoder pins in `hardware_config.h`
- Verify pull-up resistors on encoder pins
- Check serial output for encoder events

### Memory Issues

**Heap overflow**
- Increase `LV_MEM_SIZE` in `lv_conf.h`
- Reduce display buffer size in `display_driver.cpp`
- Enable PSRAM: `-DBOARD_HAS_PSRAM`

**Stack overflow in LVGL task**
- Increase `LVGL_TASK_STACK_SIZE` in `main.cpp`
- Check for recursive function calls in UI code

## Contributing

Contributions are welcome! Please:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## License

[Specify your license here]

## References

- **[Knob18Meters](https://github.com/VolosR/Knob18Meters)** - ESP32-S3 round display reference (architecture inspiration)
- [LVGL Documentation](https://docs.lvgl.io/)
- [LVGL Editor](https://github.com/lvgl/lvgl_editor)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [ESP32-S3 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/)
- [ESP-IDF LCD Driver](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/lcd.html)
- [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI)

### Architecture Notes

This project's hardware driver architecture is inspired by the Knob18Meters project, which demonstrates:
- Proper separation of hardware drivers
- FreeRTOS task management for LVGL
- Thread-safe LVGL operations with mutexes
- ESP-IDF LCD panel API integration
- QSPI display communication
- Professional code organization

Key improvements applied from Knob18Meters:
1. Modular driver structure (display, touch, encoder)
2. Hardware configuration centralization
3. FreeRTOS task for LVGL on dedicated core
4. Mutex protection for thread safety
5. Proper initialization sequence and error handling

## Support

For issues and questions:
- Open an issue on GitHub
- Check existing issues for solutions
- Review LVGL documentation
- See `src/DRIVERS_README.md` for driver implementation help

---

**Note**: This is a UI-only project. It does not include CNC machine control logic. You must integrate this UI with your own CNC controller implementation using the provided public API.