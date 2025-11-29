/**
 * @file main.cpp
 * @brief Main application entry point for ESP32-S3 CNC Pendant UI
 * 
 * This file initializes the hardware (round touch LCD, rotary encoder)
 * and sets up LVGL for the UI. It contains no machine control logic.
 * 
 * Architecture improvements based on Knob18Meters reference:
 * - Separated hardware drivers (display, touch, encoder)
 * - Proper FreeRTOS task management for LVGL
 * - Hardware-specific abstractions
 */

#include <Arduino.h>
#include "lvgl.h"
#include "ui_api.h"
#include "display_driver.h"
#include "touch_driver.h"
#include "encoder_driver.h"

/*********************
 *      DEFINES
 *********************/
#define LVGL_TICK_PERIOD_MS    2
#define LVGL_TASK_PRIORITY     2
#define LVGL_TASK_STACK_SIZE   (4 * 1024)

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lvgl_tick_timer_cb(void);
static void lvgl_task(void *pvParameter);
static void encoder_event_handler(int32_t diff, bool button_pressed);
static void example_macro_callback(const char * macro_name);
static void example_settings_save_callback(void);
static void example_screen_change_callback(ui_screen_t screen);

/**********************
 *  STATIC VARIABLES
 **********************/
/* Timer for LVGL tick */
hw_timer_t * lvgl_tick_timer = NULL;

/* Mutex for LVGL thread safety */
static SemaphoreHandle_t lvgl_mutex = NULL;


/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void setup()
{
    Serial.begin(115200);
    Serial.println("\n\n=== ESP32-S3 CNC Pendant UI Starting ===");
    Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
    
    /* Initialize LVGL */
    lv_init();
    Serial.println("LVGL initialized");
    
    /* Create mutex for LVGL thread safety */
    lvgl_mutex = xSemaphoreCreateMutex();
    if (lvgl_mutex == NULL) {
        Serial.println("ERROR: Failed to create LVGL mutex!");
        return;
    }
    
    /* Initialize display driver */
    if (!display_driver_init()) {
        Serial.println("ERROR: Display initialization failed!");
        return;
    }
    
    /* Initialize touch driver */
    if (!touch_driver_init()) {
        Serial.println("WARNING: Touch initialization failed, continuing anyway");
    }
    
    /* Initialize rotary encoder */
    if (!encoder_driver_init()) {
        Serial.println("ERROR: Encoder initialization failed!");
        return;
    }
    
    /* Set encoder event callback */
    encoder_driver_set_callback(encoder_event_handler);
    
    /* Setup LVGL tick timer */
    lvgl_tick_timer = timerBegin(0, 80, true);
    timerAttachInterrupt(lvgl_tick_timer, &lvgl_tick_timer_cb, true);
    timerAlarmWrite(lvgl_tick_timer, LVGL_TICK_PERIOD_MS * 1000, true);
    timerAlarmEnable(lvgl_tick_timer);
    Serial.println("LVGL timer initialized");
    
    /* Initialize UI system */
    if (!ui_init()) {
        Serial.println("ERROR: UI initialization failed!");
        return;
    }
    
    /* Set up example callbacks */
    ui_set_macro_callback(example_macro_callback);
    ui_set_settings_save_callback(example_settings_save_callback);
    ui_set_screen_change_callback(example_screen_change_callback);
    
    /* Set initial status */
    ui_set_status_message("System ready");
    ui_set_connection_status(false);
    
    /* Create LVGL task */
    xTaskCreatePinnedToCore(
        lvgl_task,              /* Task function */
        "LVGL",                 /* Task name */
        LVGL_TASK_STACK_SIZE,   /* Stack size */
        NULL,                   /* Parameters */
        LVGL_TASK_PRIORITY,     /* Priority */
        NULL,                   /* Task handle */
        1                       /* Core 1 */
    );
    
    Serial.println("=== UI Initialized Successfully! ===\n");
    Serial.printf("Free heap after init: %d bytes\n", ESP.getFreeHeap());
}

void loop()
{
    /* Handle encoder input */
    encoder_driver_task();
    
    /* Example: Simulate position updates (remove in production) */
    static uint32_t last_update = 0;
    if (millis() - last_update > 1000) {
        last_update = millis();
        
        /* This is just for demonstration - in a real application,
           position data would come from the CNC controller */
        static float x = 0.0f, y = 0.0f, z = 0.0f;
        x += 0.123f;
        y += 0.456f;
        z += 0.789f;
        
        char x_str[16], y_str[16], z_str[16];
        snprintf(x_str, sizeof(x_str), "%.3f", x);
        snprintf(y_str, sizeof(y_str), "%.3f", y);
        snprintf(z_str, sizeof(z_str), "%.3f", z);
        
        ui_update_all_positions(x_str, y_str, z_str, NULL);
    }
    
    delay(5);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * LVGL tick timer callback
 */
static void IRAM_ATTR lvgl_tick_timer_cb(void)
{
    lv_tick_inc(LVGL_TICK_PERIOD_MS);
}

/**
 * LVGL task handler (runs on Core 1)
 * This task handles all LVGL operations in a thread-safe manner
 */
static void lvgl_task(void *pvParameter)
{
    Serial.println("LVGL task started on core " + String(xPortGetCoreID()));
    
    while (1) {
        /* Lock LVGL mutex */
        if (xSemaphoreTake(lvgl_mutex, portMAX_DELAY) == pdTRUE) {
            /* Handle LVGL tasks */
            lv_timer_handler();
            
            /* Release mutex */
            xSemaphoreGive(lvgl_mutex);
        }
        
        /* Delay to allow other tasks to run */
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

/**
 * Encoder event handler callback
 */
static void encoder_event_handler(int32_t diff, bool button_pressed)
{
    if (diff != 0) {
        Serial.printf("Encoder: %+d\n", diff);
        ui_encoder_input(diff);
    }
    
    if (button_pressed) {
        Serial.println("Encoder button pressed");
        ui_encoder_button_pressed();
    }
}

/**
 * Example callback for macro button presses
 */
static void example_macro_callback(const char * macro_name)
{
    Serial.print("Macro triggered: ");
    Serial.println(macro_name);
    
    /* In a real application, this would send commands to the CNC controller */
    /* For example:
     * if(strcmp(macro_name, "HOME_ALL") == 0) {
     *     cnc_controller_send_command("$H\n");
     * }
     * else if(strcmp(macro_name, "ZERO_XY") == 0) {
     *     cnc_controller_send_command("G10 L20 P0 X0 Y0\n");
     * }
     */
    
    char msg[64];
    snprintf(msg, sizeof(msg), "Executed: %s", macro_name);
    ui_set_status_message(msg);
}

/**
 * Example callback for settings save
 */
static void example_settings_save_callback(void)
{
    Serial.println("Settings saved");
    
    /* In a real application, this would save settings to EEPROM/SPIFFS */
    /* For example:
     * preferences.begin("pendant", false);
     * preferences.putUInt("jog_speed", jog_speed);
     * preferences.putUInt("feed_override", feed_override);
     * preferences.end();
     */
}

/**
 * Example callback for screen changes
 */
static void example_screen_change_callback(ui_screen_t screen)
{
    Serial.print("Screen changed to: ");
    switch(screen) {
        case UI_SCREEN_MAIN:
            Serial.println("MAIN");
            break;
        case UI_SCREEN_MACROS:
            Serial.println("MACROS");
            break;
        case UI_SCREEN_SETUP:
            Serial.println("SETUP");
            break;
    }
}
