/**
 * @file setup_screen_gen.h
 * @brief Generated header for setup screen
 * 
 * This file is auto-generated from ui/xml/screens/setup.xml
 * Do not edit manually - use the XML to C generator script
 */

#ifndef SETUP_SCREEN_GEN_H
#define SETUP_SCREEN_GEN_H

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
 * Callback function type for settings changes
 */
typedef void (*setup_screen_save_cb_t)(void);
typedef void (*setup_screen_back_cb_t)(void);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create the setup screen
 * @param parent Parent object for the screen
 * @return Pointer to the created screen object
 */
lv_obj_t * setup_screen_create(lv_obj_t * parent);

/**
 * Set callback for save button
 * @param cb Callback function to be called when save is pressed
 */
void setup_screen_set_save_callback(setup_screen_save_cb_t cb);

/**
 * Set callback for back button
 * @param cb Callback function to be called when back is pressed
 */
void setup_screen_set_back_callback(setup_screen_back_cb_t cb);

/**
 * Update connection status display
 * @param connected true if connected, false otherwise
 */
void setup_screen_update_connection(bool connected);

/**
 * Update status message on setup screen
 * @param message Status message to display
 */
void setup_screen_update_status(const char * message);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SETUP_SCREEN_GEN_H*/
