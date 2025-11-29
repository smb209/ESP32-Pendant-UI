/**
 * @file main_screen_gen.h
 * @brief Generated header for main screen
 * 
 * This file is auto-generated from ui/xml/screens/main.xml
 * Do not edit manually - use the XML to C generator script
 */

#ifndef MAIN_SCREEN_GEN_H
#define MAIN_SCREEN_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create the main jog screen
 * @param parent Parent object for the screen
 * @return Pointer to the created screen object
 */
lv_obj_t * main_screen_create(lv_obj_t * parent);

/**
 * Update position display on main screen
 * @param x_pos X axis position string
 * @param y_pos Y axis position string
 * @param z_pos Z axis position string
 */
void main_screen_update_position(const char * x_pos, const char * y_pos, const char * z_pos);

/**
 * Update status message on main screen
 * @param message Status message to display
 */
void main_screen_update_status(const char * message);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MAIN_SCREEN_GEN_H*/
