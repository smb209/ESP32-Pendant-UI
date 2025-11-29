/**
 * @file encoder_driver.h
 * @brief Rotary encoder driver interface
 * 
 * Handles rotary encoder input for navigation
 */

#ifndef ENCODER_DRIVER_H
#define ENCODER_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include <Arduino.h>

/*********************
 *      DEFINES
 *********************/

/* Rotary encoder pins */
#define ENCODER_PIN_CLK  8   // Encoder A
#define ENCODER_PIN_DT   7   // Encoder B
#define ENCODER_PIN_SW   6   // Encoder button

/**********************
 *      TYPEDEFS
 **********************/

/**
 * Encoder event callback type
 */
typedef void (*encoder_event_cb_t)(int32_t diff, bool button_pressed);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the encoder driver
 * @return true on success, false on failure
 */
bool encoder_driver_init(void);

/**
 * Get the LVGL input device driver for encoder
 * @return Pointer to LVGL input device driver
 */
lv_indev_drv_t * encoder_driver_get(void);

/**
 * Read encoder state (called by LVGL)
 * @param indev_drv Input device driver
 * @param data Encoder data to fill
 */
void encoder_driver_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/**
 * Set callback for encoder events
 * @param cb Callback function
 */
void encoder_driver_set_callback(encoder_event_cb_t cb);

/**
 * Task to handle encoder reading
 * Should be called regularly in main loop
 */
void encoder_driver_task(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ENCODER_DRIVER_H*/
