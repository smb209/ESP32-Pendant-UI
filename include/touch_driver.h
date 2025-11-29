/**
 * @file touch_driver.h
 * @brief Touch driver interface for capacitive touch controller
 * 
 * Supports common touch controllers like CST816, FT6336, etc.
 */

#ifndef TOUCH_DRIVER_H
#define TOUCH_DRIVER_H

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

/* I2C pins for touch controller */
#define TOUCH_I2C_SDA  11
#define TOUCH_I2C_SCL  12
#define TOUCH_I2C_INT  -1  // Optional interrupt pin

/* Touch controller I2C address */
#define TOUCH_I2C_ADDR 0x15  // Common for CST816, adjust for your controller

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the touch driver
 * @return true on success, false on failure
 */
bool touch_driver_init(void);

/**
 * Get the LVGL input device driver
 * @return Pointer to LVGL input device driver
 */
lv_indev_drv_t * touch_driver_get(void);

/**
 * Read touch point (called by LVGL)
 * @param indev_drv Input device driver
 * @param data Touch data to fill
 */
void touch_driver_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TOUCH_DRIVER_H*/
