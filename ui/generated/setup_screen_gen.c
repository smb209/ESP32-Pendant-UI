/**
 * @file setup_screen_gen.c
 * @brief Generated implementation for setup screen
 * 
 * This file is auto-generated from ui/xml/screens/setup.xml
 * Do not edit manually - use the XML to C generator script
 */

/*********************
 *      INCLUDES
 *********************/
#include "setup_screen_gen.h"
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void save_button_event_cb(lv_event_t * e);
static void back_button_event_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * setup_screen_obj = NULL;
static lv_obj_t * label_status = NULL;
static lv_obj_t * label_connection = NULL;
static setup_screen_save_cb_t save_callback = NULL;
static setup_screen_back_cb_t back_callback = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * setup_screen_create(lv_obj_t * parent)
{
    /* Create setup screen container */
    setup_screen_obj = lv_obj_create(parent);
    lv_obj_set_size(setup_screen_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_flex_flow(setup_screen_obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_bg_color(setup_screen_obj, lv_color_hex(0x1a1a1a), 0);
    lv_obj_set_style_text_color(setup_screen_obj, lv_color_hex(0xffffff), 0);
    lv_obj_clear_flag(setup_screen_obj, LV_OBJ_FLAG_SCROLLABLE);

    /* Header */
    lv_obj_t * header = lv_obj_create(setup_screen_obj);
    lv_obj_set_size(header, LV_PCT(100), 60);
    lv_obj_set_style_bg_color(header, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(header, 2, 0);
    lv_obj_set_style_border_color(header, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(header, 8, 0);
    lv_obj_set_style_pad_all(header, 12, 0);
    
    lv_obj_t * header_label = lv_label_create(header);
    lv_label_set_text(header_label, "SETTINGS");
    lv_obj_center(header_label);

    /* Settings container */
    lv_obj_t * settings_container = lv_obj_create(setup_screen_obj);
    lv_obj_set_flex_grow(settings_container, 1);
    lv_obj_set_width(settings_container, LV_PCT(100));
    lv_obj_set_style_bg_opa(settings_container, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(settings_container, 0, 0);
    lv_obj_set_style_pad_all(settings_container, 12, 0);
    lv_obj_set_flex_flow(settings_container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(settings_container, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);

    /* Jog Speed Setting */
    lv_obj_t * panel_jog_speed = lv_obj_create(settings_container);
    lv_obj_set_size(panel_jog_speed, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_jog_speed, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_jog_speed, 1, 0);
    lv_obj_set_style_border_color(panel_jog_speed, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(panel_jog_speed, 8, 0);
    lv_obj_set_style_pad_all(panel_jog_speed, 12, 0);
    lv_obj_set_style_margin_bottom(panel_jog_speed, 12, 0);
    lv_obj_set_flex_flow(panel_jog_speed, LV_FLEX_FLOW_COLUMN);
    
    lv_obj_t * label_jog_title = lv_label_create(panel_jog_speed);
    lv_label_set_text(label_jog_title, "Jog Speed");
    
    lv_obj_t * row_jog = lv_obj_create(panel_jog_speed);
    lv_obj_set_size(row_jog, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_opa(row_jog, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row_jog, 0, 0);
    lv_obj_set_flex_flow(row_jog, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(row_jog, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * slider_jog = lv_slider_create(row_jog);
    lv_obj_set_width(slider_jog, LV_PCT(70));
    lv_obj_set_style_bg_color(slider_jog, lv_color_hex(0x404040), 0);
    lv_obj_set_style_bg_color(slider_jog, lv_color_hex(0x00cc66), LV_PART_INDICATOR);
    lv_slider_set_value(slider_jog, 50, LV_ANIM_OFF);
    
    lv_obj_t * label_jog_val = lv_label_create(row_jog);
    lv_label_set_text(label_jog_val, "50%");
    lv_obj_set_style_text_color(label_jog_val, lv_color_hex(0x00cc66), 0);

    /* Feed Override Setting */
    lv_obj_t * panel_feed = lv_obj_create(settings_container);
    lv_obj_set_size(panel_feed, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_feed, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_feed, 1, 0);
    lv_obj_set_style_border_color(panel_feed, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(panel_feed, 8, 0);
    lv_obj_set_style_pad_all(panel_feed, 12, 0);
    lv_obj_set_style_margin_bottom(panel_feed, 12, 0);
    lv_obj_set_flex_flow(panel_feed, LV_FLEX_FLOW_COLUMN);
    
    lv_obj_t * label_feed_title = lv_label_create(panel_feed);
    lv_label_set_text(label_feed_title, "Feed Override");
    
    lv_obj_t * row_feed = lv_obj_create(panel_feed);
    lv_obj_set_size(row_feed, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_opa(row_feed, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row_feed, 0, 0);
    lv_obj_set_flex_flow(row_feed, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(row_feed, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * slider_feed = lv_slider_create(row_feed);
    lv_obj_set_width(slider_feed, LV_PCT(70));
    lv_obj_set_style_bg_color(slider_feed, lv_color_hex(0x404040), 0);
    lv_obj_set_style_bg_color(slider_feed, lv_color_hex(0x00cc66), LV_PART_INDICATOR);
    lv_slider_set_value(slider_feed, 100, LV_ANIM_OFF);
    
    lv_obj_t * label_feed_val = lv_label_create(row_feed);
    lv_label_set_text(label_feed_val, "100%");
    lv_obj_set_style_text_color(label_feed_val, lv_color_hex(0x00cc66), 0);

    /* Display Brightness Setting */
    lv_obj_t * panel_brightness = lv_obj_create(settings_container);
    lv_obj_set_size(panel_brightness, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_brightness, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_brightness, 1, 0);
    lv_obj_set_style_border_color(panel_brightness, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(panel_brightness, 8, 0);
    lv_obj_set_style_pad_all(panel_brightness, 12, 0);
    lv_obj_set_style_margin_bottom(panel_brightness, 12, 0);
    lv_obj_set_flex_flow(panel_brightness, LV_FLEX_FLOW_COLUMN);
    
    lv_obj_t * label_brightness_title = lv_label_create(panel_brightness);
    lv_label_set_text(label_brightness_title, "Display Brightness");
    
    lv_obj_t * row_brightness = lv_obj_create(panel_brightness);
    lv_obj_set_size(row_brightness, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_opa(row_brightness, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row_brightness, 0, 0);
    lv_obj_set_flex_flow(row_brightness, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(row_brightness, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * slider_brightness = lv_slider_create(row_brightness);
    lv_obj_set_width(slider_brightness, LV_PCT(70));
    lv_obj_set_style_bg_color(slider_brightness, lv_color_hex(0x404040), 0);
    lv_obj_set_style_bg_color(slider_brightness, lv_color_hex(0x00cc66), LV_PART_INDICATOR);
    lv_slider_set_value(slider_brightness, 80, LV_ANIM_OFF);
    
    lv_obj_t * label_brightness_val = lv_label_create(row_brightness);
    lv_label_set_text(label_brightness_val, "80%");
    lv_obj_set_style_text_color(label_brightness_val, lv_color_hex(0x00cc66), 0);

    /* Connection Status */
    lv_obj_t * panel_connection = lv_obj_create(settings_container);
    lv_obj_set_size(panel_connection, LV_PCT(90), 60);
    lv_obj_set_style_bg_color(panel_connection, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(panel_connection, 1, 0);
    lv_obj_set_style_border_color(panel_connection, lv_color_hex(0x404040), 0);
    lv_obj_set_style_radius(panel_connection, 8, 0);
    lv_obj_set_style_pad_all(panel_connection, 12, 0);
    lv_obj_set_flex_flow(panel_connection, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(panel_connection, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * label_conn_title = lv_label_create(panel_connection);
    lv_label_set_text(label_conn_title, "Connection:");
    
    label_connection = lv_label_create(panel_connection);
    lv_label_set_text(label_connection, "Disconnected");
    lv_obj_set_style_text_color(label_connection, lv_color_hex(0xff9900), 0);

    /* Footer with save and back buttons */
    lv_obj_t * footer = lv_obj_create(setup_screen_obj);
    lv_obj_set_size(footer, LV_PCT(100), 80);
    lv_obj_set_style_bg_opa(footer, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(footer, 0, 0);
    lv_obj_set_style_pad_all(footer, 12, 0);
    lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    lv_obj_t * btn_save = lv_btn_create(footer);
    lv_obj_set_size(btn_save, 120, 50);
    lv_obj_set_style_bg_color(btn_save, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_save, 8, 0);
    lv_obj_add_event_cb(btn_save, save_button_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_t * label_save = lv_label_create(btn_save);
    lv_label_set_text(label_save, "SAVE");
    lv_obj_center(label_save);
    
    lv_obj_t * btn_back = lv_btn_create(footer);
    lv_obj_set_size(btn_back, 120, 50);
    lv_obj_set_style_bg_color(btn_back, lv_color_hex(0x00cc66), 0);
    lv_obj_set_style_radius(btn_back, 8, 0);
    lv_obj_add_event_cb(btn_back, back_button_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_t * label_back = lv_label_create(btn_back);
    lv_label_set_text(label_back, "BACK");
    lv_obj_center(label_back);

    /* Status bar */
    lv_obj_t * status_bar = lv_obj_create(setup_screen_obj);
    lv_obj_set_size(status_bar, LV_PCT(100), 30);
    lv_obj_set_style_bg_color(status_bar, lv_color_hex(0x2d2d2d), 0);
    lv_obj_set_style_border_width(status_bar, 0, 0);
    
    label_status = lv_label_create(status_bar);
    lv_label_set_text(label_status, "Ready");
    lv_obj_set_style_text_color(label_status, lv_color_hex(0xcccccc), 0);
    lv_obj_center(label_status);

    return setup_screen_obj;
}

void setup_screen_set_save_callback(setup_screen_save_cb_t cb)
{
    save_callback = cb;
}

void setup_screen_set_back_callback(setup_screen_back_cb_t cb)
{
    back_callback = cb;
}

void setup_screen_update_connection(bool connected)
{
    if(label_connection != NULL) {
        if(connected) {
            lv_label_set_text(label_connection, "Connected");
            lv_obj_set_style_text_color(label_connection, lv_color_hex(0x00cc66), 0);
        } else {
            lv_label_set_text(label_connection, "Disconnected");
            lv_obj_set_style_text_color(label_connection, lv_color_hex(0xff9900), 0);
        }
    }
}

void setup_screen_update_status(const char * message)
{
    if(label_status != NULL && message != NULL) {
        lv_label_set_text(label_status, message);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void save_button_event_cb(lv_event_t * e)
{
    if(save_callback != NULL) {
        save_callback();
    }
}

static void back_button_event_cb(lv_event_t * e)
{
    if(back_callback != NULL) {
        back_callback();
    }
}
