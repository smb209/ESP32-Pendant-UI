/**
 * @file ui_api.c
 * @brief Implementation of public API for ESP32 CNC Pendant UI
 */

/*********************
 *      INCLUDES
 *********************/
#include "ui_api.h"
#include "../ui/generated/main_screen_gen.h"
#include "../ui/generated/macros_screen_gen.h"
#include "../ui/generated/setup_screen_gen.h"
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void internal_macro_callback(const char * macro_name);
static void internal_save_callback(void);
static void internal_back_callback(void);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * current_screen_obj = NULL;
static ui_screen_t current_screen = UI_SCREEN_MAIN;
static lv_disp_t * display = NULL;

/* Position strings storage */
static char pos_x_str[16] = "0.000";
static char pos_y_str[16] = "0.000";
static char pos_z_str[16] = "0.000";
static char pos_a_str[16] = "0.000";

/* Callbacks */
static ui_macro_callback_t user_macro_callback = NULL;
static ui_settings_save_callback_t user_save_callback = NULL;
static ui_screen_change_callback_t user_screen_change_callback = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

bool ui_init(void)
{
    /* LVGL initialization should be done in main.cpp */
    /* This function sets up the UI screens */
    
    display = lv_disp_get_default();
    if(display == NULL) {
        return false;
    }
    
    /* Set up callbacks for generated screens */
    macros_screen_set_callback(internal_macro_callback);
    setup_screen_set_save_callback(internal_save_callback);
    setup_screen_set_back_callback(internal_back_callback);
    
    /* Load the main screen by default */
    ui_load_screen(UI_SCREEN_MAIN);
    
    return true;
}

void ui_update(uint32_t period_ms)
{
    lv_timer_handler();
}

void ui_load_screen(ui_screen_t screen)
{
    /* Delete current screen if it exists */
    if(current_screen_obj != NULL) {
        lv_obj_del(current_screen_obj);
        current_screen_obj = NULL;
    }
    
    /* Create new screen */
    lv_obj_t * scr = lv_scr_act();
    
    switch(screen) {
        case UI_SCREEN_MAIN:
            current_screen_obj = main_screen_create(scr);
            main_screen_update_position(pos_x_str, pos_y_str, pos_z_str);
            break;
            
        case UI_SCREEN_MACROS:
            current_screen_obj = macros_screen_create(scr);
            break;
            
        case UI_SCREEN_SETUP:
            current_screen_obj = setup_screen_create(scr);
            break;
            
        default:
            /* Invalid screen, load main */
            current_screen_obj = main_screen_create(scr);
            screen = UI_SCREEN_MAIN;
            break;
    }
    
    current_screen = screen;
    
    /* Notify callback if set */
    if(user_screen_change_callback != NULL) {
        user_screen_change_callback(screen);
    }
}

ui_screen_t ui_get_current_screen(void)
{
    return current_screen;
}

void ui_update_position(ui_axis_t axis, const char * position)
{
    if(position == NULL) {
        return;
    }
    
    /* Update internal storage */
    switch(axis) {
        case UI_AXIS_X:
            strncpy(pos_x_str, position, sizeof(pos_x_str) - 1);
            pos_x_str[sizeof(pos_x_str) - 1] = '\0';
            break;
            
        case UI_AXIS_Y:
            strncpy(pos_y_str, position, sizeof(pos_y_str) - 1);
            pos_y_str[sizeof(pos_y_str) - 1] = '\0';
            break;
            
        case UI_AXIS_Z:
            strncpy(pos_z_str, position, sizeof(pos_z_str) - 1);
            pos_z_str[sizeof(pos_z_str) - 1] = '\0';
            break;
            
        case UI_AXIS_A:
            strncpy(pos_a_str, position, sizeof(pos_a_str) - 1);
            pos_a_str[sizeof(pos_a_str) - 1] = '\0';
            break;
    }
    
    /* Update display if on main screen */
    if(current_screen == UI_SCREEN_MAIN) {
        main_screen_update_position(pos_x_str, pos_y_str, pos_z_str);
    }
}

void ui_update_all_positions(const char * x_pos, const char * y_pos, 
                              const char * z_pos, const char * a_pos)
{
    if(x_pos != NULL) {
        ui_update_position(UI_AXIS_X, x_pos);
    }
    if(y_pos != NULL) {
        ui_update_position(UI_AXIS_Y, y_pos);
    }
    if(z_pos != NULL) {
        ui_update_position(UI_AXIS_Z, z_pos);
    }
    if(a_pos != NULL) {
        ui_update_position(UI_AXIS_A, a_pos);
    }
}

void ui_set_status_message(const char * message)
{
    if(message == NULL) {
        return;
    }
    
    switch(current_screen) {
        case UI_SCREEN_MAIN:
            main_screen_update_status(message);
            break;
            
        case UI_SCREEN_MACROS:
            macros_screen_update_status(message);
            break;
            
        case UI_SCREEN_SETUP:
            setup_screen_update_status(message);
            break;
    }
}

void ui_set_connection_status(bool connected)
{
    if(current_screen == UI_SCREEN_SETUP) {
        setup_screen_update_connection(connected);
    }
}

void ui_set_spindle_rpm(uint16_t rpm)
{
    /* Implementation depends on UI design */
    /* Could be added to main screen or status bar */
    (void)rpm; /* Suppress unused warning for now */
}

void ui_set_feed_override(uint8_t percentage)
{
    /* Implementation depends on UI design */
    /* Could be added to main screen or status bar */
    (void)percentage; /* Suppress unused warning for now */
}

void ui_set_macro_callback(ui_macro_callback_t cb)
{
    user_macro_callback = cb;
}

void ui_set_settings_save_callback(ui_settings_save_callback_t cb)
{
    user_save_callback = cb;
}

void ui_set_screen_change_callback(ui_screen_change_callback_t cb)
{
    user_screen_change_callback = cb;
}

void ui_encoder_input(int32_t delta)
{
    /* Implementation for rotary encoder navigation */
    /* This would typically scroll through options or adjust values */
    lv_group_t * group = lv_group_get_default();
    if(group != NULL) {
        if(delta > 0) {
            for(int i = 0; i < delta; i++) {
                lv_group_focus_next(group);
            }
        } else if(delta < 0) {
            for(int i = 0; i > delta; i--) {
                lv_group_focus_prev(group);
            }
        }
    }
}

void ui_encoder_button_pressed(void)
{
    /* Implementation for encoder button press */
    /* This would typically activate the focused item */
    lv_group_t * group = lv_group_get_default();
    if(group != NULL) {
        lv_obj_t * focused = lv_group_get_focused(group);
        if(focused != NULL) {
            lv_event_send(focused, LV_EVENT_CLICKED, NULL);
        }
    }
}

void * ui_get_lvgl_display(void)
{
    return (void *)display;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void internal_macro_callback(const char * macro_name)
{
    /* Forward to user callback if set */
    if(user_macro_callback != NULL) {
        user_macro_callback(macro_name);
    }
    
    /* Default behavior: return to main screen after macro */
    ui_load_screen(UI_SCREEN_MAIN);
}

static void internal_save_callback(void)
{
    /* Forward to user callback if set */
    if(user_save_callback != NULL) {
        user_save_callback();
    }
    
    ui_set_status_message("Settings saved");
}

static void internal_back_callback(void)
{
    /* Return to main screen */
    ui_load_screen(UI_SCREEN_MAIN);
}
