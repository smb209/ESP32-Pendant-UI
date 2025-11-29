/**
 * @file main_screen_gen.c
 * @brief Generated implementation for main screen
 * 
 * This file is auto-generated from ui/xml/screens/main.xml
 * Do not edit manually - use the XML to C generator script
 */

/*********************
 *      INCLUDES
 *********************/
#include "main_screen_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * main_screen_obj = NULL;
static lv_obj_t * label_pos_x = NULL;
static lv_obj_t * label_pos_y = NULL;
static lv_obj_t * label_pos_z = NULL;
static lv_obj_t * label_status = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * main_screen_create(lv_obj_t * parent)
{
    /* Create main screen container */
    main_screen_obj = lv_obj_create(parent);
    lv_obj_set_size(main_screen_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_flex_flow(main_screen_obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_bg_color(main_screen_obj, lv_color_hex(0x1a1a1a), 0);
    lv_obj_set_style_text_color(main_screen_obj, lv_color_hex(0xffffff), 0);
    lv_obj_clear_flag(main_screen_obj, LV_OBJ_FLAG_SCROLLABLE);

    /* Header */
    lv_obj_t * header = lv_obj_create(main_screen_obj);
    lv_obj_set_size(header, LV_PCT(100), 60);
    lv_obj_set_style_bg_color(header, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(header, 2, 0);
    lv_obj_set_style_border_color(header, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(header, 8, 0);
    lv_obj_set_style_pad_all(header, 12, 0);
    
    lv_obj_t * header_label = lv_label_create(header);
    lv_label_set_text(header_label, "CNC Pendant - JOG MODE");
    lv_obj_center(header_label);

    /* DRO Container */
    lv_obj_t * dro_container = lv_obj_create(main_screen_obj);
    lv_obj_set_flex_grow(dro_container, 1);
    lv_obj_set_width(dro_container, LV_PCT(100));
    lv_obj_set_style_bg_opa(dro_container, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(dro_container, 0, 0);
    lv_obj_set_style_pad_all(dro_container, 12, 0);
    lv_obj_set_flex_flow(dro_container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(dro_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);

    /* X Axis Panel */
    lv_obj_t * panel_x = lv_obj_create(dro_container);
    lv_obj_set_size(panel_x, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_x, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_x, 2, 0);
    lv_obj_set_style_border_color(panel_x, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(panel_x, 12, 0);
    lv_obj_set_style_pad_all(panel_x, 16, 0);
    
    lv_obj_t * label_x_axis = lv_label_create(panel_x);
    lv_label_set_text(label_x_axis, "X:");
    lv_obj_set_style_text_color(label_x_axis, lv_color_hex(0xcccccc), 0);
    lv_obj_align(label_x_axis, LV_ALIGN_LEFT_MID, 0, 0);
    
    label_pos_x = lv_label_create(panel_x);
    lv_label_set_text(label_pos_x, "0.000");
    lv_obj_set_style_text_color(label_pos_x, lv_color_hex(0x00cc66), 0);
    lv_obj_align(label_pos_x, LV_ALIGN_RIGHT_MID, 0, 0);

    /* Y Axis Panel */
    lv_obj_t * panel_y = lv_obj_create(dro_container);
    lv_obj_set_size(panel_y, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_y, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_y, 2, 0);
    lv_obj_set_style_border_color(panel_y, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(panel_y, 12, 0);
    lv_obj_set_style_pad_all(panel_y, 16, 0);
    lv_obj_set_style_margin_top(panel_y, 8, 0);
    
    lv_obj_t * label_y_axis = lv_label_create(panel_y);
    lv_label_set_text(label_y_axis, "Y:");
    lv_obj_set_style_text_color(label_y_axis, lv_color_hex(0xcccccc), 0);
    lv_obj_align(label_y_axis, LV_ALIGN_LEFT_MID, 0, 0);
    
    label_pos_y = lv_label_create(panel_y);
    lv_label_set_text(label_pos_y, "0.000");
    lv_obj_set_style_text_color(label_pos_y, lv_color_hex(0x00cc66), 0);
    lv_obj_align(label_pos_y, LV_ALIGN_RIGHT_MID, 0, 0);

    /* Z Axis Panel */
    lv_obj_t * panel_z = lv_obj_create(dro_container);
    lv_obj_set_size(panel_z, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_z, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_z, 2, 0);
    lv_obj_set_style_border_color(panel_z, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(panel_z, 12, 0);
    lv_obj_set_style_pad_all(panel_z, 16, 0);
    lv_obj_set_style_margin_top(panel_z, 8, 0);
    
    lv_obj_t * label_z_axis = lv_label_create(panel_z);
    lv_label_set_text(label_z_axis, "Z:");
    lv_obj_set_style_text_color(label_z_axis, lv_color_hex(0xcccccc), 0);
    lv_obj_align(label_z_axis, LV_ALIGN_LEFT_MID, 0, 0);
    
    label_pos_z = lv_label_create(panel_z);
    lv_label_set_text(label_pos_z, "0.000");
    lv_obj_set_style_text_color(label_pos_z, lv_color_hex(0x00cc66), 0);
    lv_obj_align(label_pos_z, LV_ALIGN_RIGHT_MID, 0, 0);

    /* Footer with buttons */
    lv_obj_t * footer = lv_obj_create(main_screen_obj);
    lv_obj_set_size(footer, LV_PCT(100), 80);
    lv_obj_set_style_bg_opa(footer, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(footer, 0, 0);
    lv_obj_set_style_pad_all(footer, 12, 0);
    lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * btn_zero = lv_btn_create(footer);
    lv_obj_set_size(btn_zero, 100, 50);
    lv_obj_set_style_bg_color(btn_zero, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_zero, 8, 0);
    lv_obj_t * label_zero = lv_label_create(btn_zero);
    lv_label_set_text(label_zero, "ZERO");
    lv_obj_center(label_zero);
    
    lv_obj_t * btn_macro = lv_btn_create(footer);
    lv_obj_set_size(btn_macro, 100, 50);
    lv_obj_set_style_bg_color(btn_macro, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_macro, 8, 0);
    lv_obj_t * label_macro = lv_label_create(btn_macro);
    lv_label_set_text(label_macro, "MACRO");
    lv_obj_center(label_macro);

    /* Status bar */
    lv_obj_t * status_bar = lv_obj_create(main_screen_obj);
    lv_obj_set_size(status_bar, LV_PCT(100), 30);
    lv_obj_set_style_bg_color(status_bar, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(status_bar, 0, 0);
    
    label_status = lv_label_create(status_bar);
    lv_label_set_text(label_status, "Ready");
    lv_obj_set_style_text_color(label_status, lv_color_hex(0xcccccc), 0);
    lv_obj_center(label_status);

    return main_screen_obj;
}

void main_screen_update_position(const char * x_pos, const char * y_pos, const char * z_pos)
{
    if(label_pos_x != NULL && x_pos != NULL) {
        lv_label_set_text(label_pos_x, x_pos);
    }
    if(label_pos_y != NULL && y_pos != NULL) {
        lv_label_set_text(label_pos_y, y_pos);
    }
    if(label_pos_z != NULL && z_pos != NULL) {
        lv_label_set_text(label_pos_z, z_pos);
    }
}

void main_screen_update_status(const char * message)
{
    if(label_status != NULL && message != NULL) {
        lv_label_set_text(label_status, message);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
