/**
 * @file macros_screen_gen.c
 * @brief Generated implementation for macros screen
 * 
 * This file is auto-generated from ui/xml/screens/macros.xml
 * Do not edit manually - use the XML to C generator script
 */

/*********************
 *      INCLUDES
 *********************/
#include "macros_screen_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void macro_button_event_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * macros_screen_obj = NULL;
static lv_obj_t * label_status = NULL;
static macros_screen_cb_t macro_callback = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * macros_screen_create(lv_obj_t * parent)
{
    /* Create macros screen container */
    macros_screen_obj = lv_obj_create(parent);
    lv_obj_set_size(macros_screen_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_flex_flow(macros_screen_obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_bg_color(macros_screen_obj, lv_color_hex(0x1a1a1a), 0);
    lv_obj_set_style_text_color(macros_screen_obj, lv_color_hex(0xffffff), 0);
    lv_obj_clear_flag(macros_screen_obj, LV_OBJ_FLAG_SCROLLABLE);

    /* Header */
    lv_obj_t * header = lv_obj_create(macros_screen_obj);
    lv_obj_set_size(header, LV_PCT(100), 60);
    lv_obj_set_style_bg_color(header, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(header, 2, 0);
    lv_obj_set_style_border_color(header, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(header, 8, 0);
    lv_obj_set_style_pad_all(header, 12, 0);
    
    lv_obj_t * header_label = lv_label_create(header);
    lv_label_set_text(header_label, "MACRO COMMANDS");
    lv_obj_center(header_label);

    /* Macro buttons container */
    lv_obj_t * macro_container = lv_obj_create(macros_screen_obj);
    lv_obj_set_flex_grow(macro_container, 1);
    lv_obj_set_width(macro_container, LV_PCT(100));
    lv_obj_set_style_bg_opa(macro_container, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(macro_container, 0, 0);
    lv_obj_set_style_pad_all(macro_container, 16, 0);
    lv_obj_set_flex_flow(macro_container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(macro_container, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    /* Row 1 */
    lv_obj_t * row1 = lv_obj_create(macro_container);
    lv_obj_set_size(row1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_opa(row1, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row1, 0, 0);
    lv_obj_set_flex_flow(row1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(row1, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * btn_probe = lv_btn_create(row1);
    lv_obj_set_size(btn_probe, 200, 80);
    lv_obj_set_style_bg_color(btn_probe, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(btn_probe, 2, 0);
    lv_obj_set_style_border_color(btn_probe, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_probe, 12, 0);
    lv_obj_set_style_bg_color(btn_probe, lv_color_hex(0x00cc66), LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_probe, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"PROBE_Z");
    lv_obj_t * label_probe = lv_label_create(btn_probe);
    lv_label_set_text(label_probe, "PROBE Z");
    lv_obj_center(label_probe);
    
    lv_obj_t * btn_home = lv_btn_create(row1);
    lv_obj_set_size(btn_home, 200, 80);
    lv_obj_set_style_bg_color(btn_home, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(btn_home, 2, 0);
    lv_obj_set_style_border_color(btn_home, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_home, 12, 0);
    lv_obj_set_style_bg_color(btn_home, lv_color_hex(0x00cc66), LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_home, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"HOME_ALL");
    lv_obj_t * label_home = lv_label_create(btn_home);
    lv_label_set_text(label_home, "HOME ALL");
    lv_obj_center(label_home);

    /* Row 2 */
    lv_obj_t * row2 = lv_obj_create(macro_container);
    lv_obj_set_size(row2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_opa(row2, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row2, 0, 0);
    lv_obj_set_flex_flow(row2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(row2, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * btn_zero_xy = lv_btn_create(row2);
    lv_obj_set_size(btn_zero_xy, 200, 80);
    lv_obj_set_style_bg_color(btn_zero_xy, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(btn_zero_xy, 2, 0);
    lv_obj_set_style_border_color(btn_zero_xy, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_zero_xy, 12, 0);
    lv_obj_set_style_bg_color(btn_zero_xy, lv_color_hex(0x00cc66), LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_zero_xy, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"ZERO_XY");
    lv_obj_t * label_zero_xy = lv_label_create(btn_zero_xy);
    lv_label_set_text(label_zero_xy, "ZERO XY");
    lv_obj_center(label_zero_xy);
    
    lv_obj_t * btn_zero_z = lv_btn_create(row2);
    lv_obj_set_size(btn_zero_z, 200, 80);
    lv_obj_set_style_bg_color(btn_zero_z, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(btn_zero_z, 2, 0);
    lv_obj_set_style_border_color(btn_zero_z, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_zero_z, 12, 0);
    lv_obj_set_style_bg_color(btn_zero_z, lv_color_hex(0x00cc66), LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_zero_z, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"ZERO_Z");
    lv_obj_t * label_zero_z = lv_label_create(btn_zero_z);
    lv_label_set_text(label_zero_z, "ZERO Z");
    lv_obj_center(label_zero_z);

    /* Row 3 */
    lv_obj_t * row3 = lv_obj_create(macro_container);
    lv_obj_set_size(row3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_opa(row3, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row3, 0, 0);
    lv_obj_set_flex_flow(row3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(row3, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * btn_goto_zero = lv_btn_create(row3);
    lv_obj_set_size(btn_goto_zero, 200, 80);
    lv_obj_set_style_bg_color(btn_goto_zero, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(btn_goto_zero, 2, 0);
    lv_obj_set_style_border_color(btn_goto_zero, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_goto_zero, 12, 0);
    lv_obj_set_style_bg_color(btn_goto_zero, lv_color_hex(0x00cc66), LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_goto_zero, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"GOTO_ZERO");
    lv_obj_t * label_goto_zero = lv_label_create(btn_goto_zero);
    lv_label_set_text(label_goto_zero, "GOTO ZERO");
    lv_obj_center(label_goto_zero);
    
    lv_obj_t * btn_unlock = lv_btn_create(row3);
    lv_obj_set_size(btn_unlock, 200, 80);
    lv_obj_set_style_bg_color(btn_unlock, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(btn_unlock, 2, 0);
    lv_obj_set_style_border_color(btn_unlock, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_unlock, 12, 0);
    lv_obj_set_style_bg_color(btn_unlock, lv_color_hex(0x00cc66), LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_unlock, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"UNLOCK");
    lv_obj_t * label_unlock = lv_label_create(btn_unlock);
    lv_label_set_text(label_unlock, "UNLOCK");
    lv_obj_center(label_unlock);

    /* Footer with back button */
    lv_obj_t * footer = lv_obj_create(macros_screen_obj);
    lv_obj_set_size(footer, LV_PCT(100), 80);
    lv_obj_set_style_bg_opa(footer, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(footer, 0, 0);
    lv_obj_set_style_pad_all(footer, 12, 0);
    lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * btn_back = lv_btn_create(footer);
    lv_obj_set_size(btn_back, 120, 50);
    lv_obj_set_style_bg_color(btn_back, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_back, 8, 0);
    lv_obj_add_event_cb(btn_back, macro_button_event_cb, LV_EVENT_CLICKED, (void*)"BACK");
    lv_obj_t * label_back = lv_label_create(btn_back);
    lv_label_set_text(label_back, "BACK");
    lv_obj_center(label_back);

    /* Status bar */
    lv_obj_t * status_bar = lv_obj_create(macros_screen_obj);
    lv_obj_set_size(status_bar, LV_PCT(100), 30);
    lv_obj_set_style_bg_color(status_bar, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(status_bar, 0, 0);
    
    label_status = lv_label_create(status_bar);
    lv_label_set_text(label_status, "Ready");
    lv_obj_set_style_text_color(label_status, lv_color_hex(0xcccccc), 0);
    lv_obj_center(label_status);

    return macros_screen_obj;
}

void macros_screen_set_callback(macros_screen_cb_t cb)
{
    macro_callback = cb;
}

void macros_screen_update_status(const char * message)
{
    if(label_status != NULL && message != NULL) {
        lv_label_set_text(label_status, message);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void macro_button_event_cb(lv_event_t * e)
{
    const char * macro_name = (const char *)lv_event_get_user_data(e);
    if(macro_callback != NULL && macro_name != NULL) {
        macro_callback(macro_name);
    }
}
