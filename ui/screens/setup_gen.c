/**
 * @file setup_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "setup_gen.h"
#include "cnc_pendant.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * setup_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_setting_row;
    static lv_style_t style_slider;
    static lv_style_t style_slider_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_setting_row);
        lv_style_set_bg_color(&style_setting_row, SECONDARY_BG);
        lv_style_set_border_width(&style_setting_row, 1);
        lv_style_set_border_color(&style_setting_row, BORDER_COLOR);
        lv_style_set_radius(&style_setting_row, UNIT_SM);
        lv_style_set_pad_all(&style_setting_row, UNIT_MD);
        lv_style_set_width(&style_setting_row, lv_pct(90));
        lv_style_set_height(&style_setting_row, 60);
        lv_style_set_margin_bottom(&style_setting_row, UNIT_SM);

        lv_style_init(&style_slider);
        lv_style_set_bg_color(&style_slider, BORDER_COLOR);
        lv_style_set_bg_opa(&style_slider, OPA_MUTED);

        lv_style_init(&style_slider_indicator);
        lv_style_set_bg_color(&style_slider_indicator, ACCENT_COLOR);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "setup_#");
    lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_width(lv_obj_0, lv_pct(100));
    lv_obj_set_height(lv_obj_0, lv_pct(100));

    lv_obj_add_style(lv_obj_0, &style_screen_base, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_1, lv_pct(100));
    lv_obj_set_height(lv_obj_1, 60);
    lv_obj_set_style_pad_all(lv_obj_1, UNIT_MD, 0);
    lv_obj_add_style(lv_obj_1, &style_panel, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_0, "SETTINGS");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_style_flex_grow(lv_obj_2, 1, 0);
    lv_obj_set_width(lv_obj_2, lv_pct(100));
    lv_obj_set_style_pad_all(lv_obj_2, UNIT_MD, 0);
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
    lv_obj_set_style_flex_flow(lv_obj_3, LV_FLEX_FLOW_COLUMN, 0);
    lv_obj_set_width(lv_obj_3, lv_pct(100));
    lv_obj_set_style_flex_cross_place(lv_obj_3, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_margin_bottom(lv_obj_4, UNIT_MD, 0);
    lv_obj_add_style(lv_obj_4, &style_setting_row, 0);
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_4);
    lv_obj_set_style_flex_flow(lv_obj_5, LV_FLEX_FLOW_COLUMN, 0);
    lv_obj_set_width(lv_obj_5, lv_pct(100));
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_1, "Jog Speed");
    lv_obj_set_style_text_color(lv_label_1, TEXT_PRIMARY, 0);
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_5);
    lv_obj_set_style_flex_flow(lv_obj_6, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_6, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_6, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_6);
    lv_obj_set_width(lv_slider_0, lv_pct(70));
    lv_obj_set_style_bg_color(lv_slider_0, BORDER_COLOR, 0);
    lv_obj_add_style(lv_slider_0, &style_slider_indicator, LV_PART_INDICATOR);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_2, "50%");
    lv_obj_set_style_text_color(lv_label_2, ACCENT_COLOR, 0);
    
    lv_obj_t * lv_obj_7 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_margin_bottom(lv_obj_7, UNIT_MD, 0);
    lv_obj_add_style(lv_obj_7, &style_setting_row, 0);
    lv_obj_t * lv_obj_8 = lv_obj_create(lv_obj_7);
    lv_obj_set_style_flex_flow(lv_obj_8, LV_FLEX_FLOW_COLUMN, 0);
    lv_obj_set_width(lv_obj_8, lv_pct(100));
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_8);
    lv_label_set_text(lv_label_3, "Feed Override");
    lv_obj_set_style_text_color(lv_label_3, TEXT_PRIMARY, 0);
    
    lv_obj_t * lv_obj_9 = lv_obj_create(lv_obj_8);
    lv_obj_set_style_flex_flow(lv_obj_9, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_9, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_9, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_slider_1 = lv_slider_create(lv_obj_9);
    lv_obj_set_width(lv_slider_1, lv_pct(70));
    lv_obj_set_style_bg_color(lv_slider_1, BORDER_COLOR, 0);
    lv_obj_add_style(lv_slider_1, &style_slider_indicator, LV_PART_INDICATOR);
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_9);
    lv_label_set_text(lv_label_4, "100%");
    lv_obj_set_style_text_color(lv_label_4, ACCENT_COLOR, 0);
    
    lv_obj_t * lv_obj_10 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_margin_bottom(lv_obj_10, UNIT_MD, 0);
    lv_obj_add_style(lv_obj_10, &style_setting_row, 0);
    lv_obj_t * lv_obj_11 = lv_obj_create(lv_obj_10);
    lv_obj_set_style_flex_flow(lv_obj_11, LV_FLEX_FLOW_COLUMN, 0);
    lv_obj_set_width(lv_obj_11, lv_pct(100));
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_11);
    lv_label_set_text(lv_label_5, "Display Brightness");
    lv_obj_set_style_text_color(lv_label_5, TEXT_PRIMARY, 0);
    
    lv_obj_t * lv_obj_12 = lv_obj_create(lv_obj_11);
    lv_obj_set_style_flex_flow(lv_obj_12, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_12, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_12, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_slider_2 = lv_slider_create(lv_obj_12);
    lv_obj_set_width(lv_slider_2, lv_pct(70));
    lv_obj_set_style_bg_color(lv_slider_2, BORDER_COLOR, 0);
    lv_obj_add_style(lv_slider_2, &style_slider_indicator, LV_PART_INDICATOR);
    
    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_12);
    lv_label_set_text(lv_label_6, "80%");
    lv_obj_set_style_text_color(lv_label_6, ACCENT_COLOR, 0);
    
    lv_obj_t * lv_obj_13 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_margin_bottom(lv_obj_13, UNIT_MD, 0);
    lv_obj_add_style(lv_obj_13, &style_setting_row, 0);
    lv_obj_t * lv_obj_14 = lv_obj_create(lv_obj_13);
    lv_obj_set_style_flex_flow(lv_obj_14, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_14, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_14, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_14);
    lv_label_set_text(lv_label_7, "Connection:");
    lv_obj_set_style_text_color(lv_label_7, TEXT_PRIMARY, 0);
    
    lv_obj_t * lv_label_8 = lv_label_create(lv_obj_14);
    lv_label_set_text(lv_label_8, "Disconnected");
    lv_obj_set_style_text_color(lv_label_8, WARNING_COLOR, 0);
    
    lv_obj_t * lv_obj_15 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_15, lv_pct(100));
    lv_obj_set_height(lv_obj_15, 80);
    lv_obj_set_style_pad_all(lv_obj_15, UNIT_MD, 0);
    lv_obj_t * lv_obj_16 = lv_obj_create(lv_obj_15);
    lv_obj_set_style_flex_flow(lv_obj_16, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_16, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_16, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_16);
    lv_obj_set_width(lv_button_0, 120);
    lv_obj_set_height(lv_button_0, 50);
    lv_obj_add_style(lv_button_0, &style_button_primary, 0);
    lv_obj_t * lv_label_9 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_9, "SAVE");
    lv_obj_set_align(lv_label_9, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_button_1 = lv_button_create(lv_obj_16);
    lv_obj_set_width(lv_button_1, 120);
    lv_obj_set_height(lv_button_1, 50);
    lv_obj_add_style(lv_button_1, &style_button_primary, 0);
    lv_obj_t * lv_label_10 = lv_label_create(lv_button_1);
    lv_label_set_text(lv_label_10, "BACK");
    lv_obj_set_align(lv_label_10, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_17 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_17, lv_pct(100));
    lv_obj_set_height(lv_obj_17, 30);
    lv_obj_set_style_bg_color(lv_obj_17, SECONDARY_BG, 0);
    lv_obj_t * lv_label_11 = lv_label_create(lv_obj_17);
    lv_label_bind_text(lv_label_11, &status_message, NULL);
    lv_obj_set_align(lv_label_11, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(lv_label_11, TEXT_SECONDARY, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

