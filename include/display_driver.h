/**
 * @file display_driver.h
 * @brief Display driver interface for round LCD
 * 
 * Hardware-specific display driver implementation.
 * This file provides the interface for various display controllers.
 */

#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

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

/* Display resolution */
#define DISPLAY_WIDTH  480
#define DISPLAY_HEIGHT 480

/* SPI pins - adjust for your hardware */
#define LCD_PIN_CS     14
#define LCD_PIN_SCLK   13
#define LCD_PIN_MOSI   15
#define LCD_PIN_DC     16
#define LCD_PIN_RST    21
#define LCD_PIN_BL     47

/* Display buffer configuration */
#define DISPLAY_BUF_HEIGHT  (DISPLAY_HEIGHT / 10)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the display driver
 * @return true on success, false on failure
 */
bool display_driver_init(void);

/**
 * Get the LVGL display driver
 * @return Pointer to LVGL display driver
 */
lv_disp_drv_t * display_driver_get(void);

/**
 * Set display brightness
 * @param brightness Brightness level 0-255
 */
void display_driver_set_brightness(uint8_t brightness);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*DISPLAY_DRIVER_H*/
