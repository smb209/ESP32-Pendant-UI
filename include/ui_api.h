/**
 * @file ui_api.h
 * @brief Public API for ESP32 CNC Pendant UI
 * 
 * This is the main public interface for the CNC Pendant UI.
 * Applications should only use functions from this API and not
 * directly access internal UI implementation details.
 */

#ifndef UI_API_H
#define UI_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**
 * Screen identifiers
 */
typedef enum {
    UI_SCREEN_MAIN = 0,     /**< Main jog/DRO screen */
    UI_SCREEN_MACROS,       /**< Macro commands screen */
    UI_SCREEN_SETUP,        /**< Setup/settings screen */
} ui_screen_t;

/**
 * Axis identifiers
 */
typedef enum {
    UI_AXIS_X = 0,
    UI_AXIS_Y,
    UI_AXIS_Z,
    UI_AXIS_A,
} ui_axis_t;

/**
 * Callback function types
 */
typedef void (*ui_macro_callback_t)(const char * macro_name);
typedef void (*ui_settings_save_callback_t)(void);
typedef void (*ui_screen_change_callback_t)(ui_screen_t screen);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the UI system
 * Must be called before any other UI functions
 * 
 * @return true on success, false on failure
 */
bool ui_init(void);

/**
 * Update the UI (call this in main loop)
 * Handles LVGL timer tasks and input processing
 * 
 * @param period_ms Time since last call in milliseconds
 */
void ui_update(uint32_t period_ms);

/**
 * Load and display a specific screen
 * 
 * @param screen Screen identifier to display
 */
void ui_load_screen(ui_screen_t screen);

/**
 * Get the currently displayed screen
 * 
 * @return Current screen identifier
 */
ui_screen_t ui_get_current_screen(void);

/**
 * Update axis position display (DRO - Digital Read Out)
 * 
 * @param axis Axis to update
 * @param position Position value as a formatted string (e.g., "123.456")
 */
void ui_update_position(ui_axis_t axis, const char * position);

/**
 * Update all axis positions at once
 * 
 * @param x_pos X axis position string
 * @param y_pos Y axis position string
 * @param z_pos Z axis position string
 * @param a_pos A axis position string (can be NULL if not used)
 */
void ui_update_all_positions(const char * x_pos, const char * y_pos, 
                              const char * z_pos, const char * a_pos);

/**
 * Update status message displayed on screen
 * 
 * @param message Status message to display
 */
void ui_set_status_message(const char * message);

/**
 * Update connection status
 * 
 * @param connected true if machine is connected, false otherwise
 */
void ui_set_connection_status(bool connected);

/**
 * Update spindle RPM display
 * 
 * @param rpm Current spindle RPM value
 */
void ui_set_spindle_rpm(uint16_t rpm);

/**
 * Update feed override percentage
 * 
 * @param percentage Feed override percentage (10-200)
 */
void ui_set_feed_override(uint8_t percentage);

/**
 * Set callback for macro button presses
 * The callback will receive the macro name as a string
 * 
 * @param cb Callback function
 */
void ui_set_macro_callback(ui_macro_callback_t cb);

/**
 * Set callback for settings save button
 * 
 * @param cb Callback function
 */
void ui_set_settings_save_callback(ui_settings_save_callback_t cb);

/**
 * Set callback for screen changes
 * 
 * @param cb Callback function
 */
void ui_set_screen_change_callback(ui_screen_change_callback_t cb);

/**
 * Process rotary encoder input
 * Call this when encoder is rotated
 * 
 * @param delta Change in encoder position (positive = clockwise, negative = counter-clockwise)
 */
void ui_encoder_input(int32_t delta);

/**
 * Process encoder button press
 * Call this when encoder button is pressed
 */
void ui_encoder_button_pressed(void);

/**
 * Get LVGL display object
 * For advanced use cases where direct LVGL access is needed
 * 
 * @return Pointer to LVGL display object, or NULL if not initialized
 */
void * ui_get_lvgl_display(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_API_H*/
