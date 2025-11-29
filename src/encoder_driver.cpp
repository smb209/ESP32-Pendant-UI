/**
 * @file encoder_driver.cpp
 * @brief Rotary encoder driver implementation
 * 
 * Handles rotary encoder input with debouncing and event callbacks
 */

/*********************
 *      INCLUDES
 *********************/
#include "encoder_driver.h"

/*********************
 *      DEFINES
 *********************/
#define ENCODER_DEBOUNCE_MS  50

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void encoder_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_indev_drv_t indev_drv;
static volatile int32_t encoder_count = 0;
static volatile int32_t encoder_last_count = 0;
static volatile bool button_pressed = false;
static uint32_t last_button_time = 0;
static encoder_event_cb_t event_callback = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

bool encoder_driver_init(void)
{
    Serial.println("Encoder driver: Initializing...");
    
    /* Configure encoder pins */
    pinMode(ENCODER_PIN_CLK, INPUT_PULLUP);
    pinMode(ENCODER_PIN_DT, INPUT_PULLUP);
    pinMode(ENCODER_PIN_SW, INPUT_PULLUP);
    
    /* Initialize LVGL input device driver */
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = encoder_read_cb;
    
    /* Register input device */
    lv_indev_t * encoder_indev = lv_indev_drv_register(&indev_drv);
    
    /* Create a group for encoder navigation */
    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(encoder_indev, g);
    
    Serial.println("Encoder driver: Initialized");
    return true;
}

lv_indev_drv_t * encoder_driver_get(void)
{
    return &indev_drv;
}

void encoder_driver_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    encoder_read_cb(indev_drv, data);
}

void encoder_driver_set_callback(encoder_event_cb_t cb)
{
    event_callback = cb;
}

void encoder_driver_task(void)
{
    static uint8_t last_clk = HIGH;
    
    /* Read encoder rotation */
    uint8_t clk = digitalRead(ENCODER_PIN_CLK);
    uint8_t dt = digitalRead(ENCODER_PIN_DT);
    
    if (clk != last_clk && clk == LOW) {
        if (dt == HIGH) {
            encoder_count++;
        } else {
            encoder_count--;
        }
    }
    last_clk = clk;
    
    /* Read encoder button with debouncing */
    uint8_t sw = digitalRead(ENCODER_PIN_SW);
    if (sw == LOW) {
        uint32_t now = millis();
        if (now - last_button_time > ENCODER_DEBOUNCE_MS) {
            button_pressed = true;
            last_button_time = now;
        }
    } else {
        button_pressed = false;
    }
    
    /* Call event callback if encoder state changed */
    if (event_callback != NULL) {
        int32_t diff = encoder_count - encoder_last_count;
        if (diff != 0 || button_pressed) {
            event_callback(diff, button_pressed);
            encoder_last_count = encoder_count;
        }
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Read encoder state for LVGL
 */
static void encoder_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    /* Get encoder difference */
    int32_t diff = encoder_count - encoder_last_count;
    data->enc_diff = diff;
    encoder_last_count = encoder_count;
    
    /* Get button state */
    if (button_pressed) {
        data->state = LV_INDEV_STATE_PR;
        button_pressed = false; // Clear after reading
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}
