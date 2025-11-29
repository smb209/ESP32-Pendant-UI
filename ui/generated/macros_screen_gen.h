/**
 * @file macros_screen_gen.h
 * @brief Generated header for macros screen
 * 
 * This file is auto-generated from ui/xml/screens/macros.xml
 * Do not edit manually - use the XML to C generator script
 */

#ifndef MACROS_SCREEN_GEN_H
#define MACROS_SCREEN_GEN_H

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

/**
 * Callback function type for macro button events
 */
typedef void (*macros_screen_cb_t)(const char * macro_name);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create the macros screen
 * @param parent Parent object for the screen
 * @return Pointer to the created screen object
 */
lv_obj_t * macros_screen_create(lv_obj_t * parent);

/**
 * Set callback for macro button presses
 * @param cb Callback function to be called when a macro button is pressed
 */
void macros_screen_set_callback(macros_screen_cb_t cb);

/**
 * Update status message on macros screen
 * @param message Status message to display
 */
void macros_screen_update_status(const char * message);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MACROS_SCREEN_GEN_H*/
