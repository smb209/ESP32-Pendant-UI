/**
 * @file main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "main_gen.h"
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

lv_obj_t * main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dro_panel;
    static lv_style_t style_axis_label;
    static lv_style_t style_position_value;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_dro_panel);
        lv_style_set_bg_color(&style_dro_panel, SECONDARY_BG);
        lv_style_set_border_width(&style_dro_panel, 2);
        lv_style_set_border_color(&style_dro_panel, ACCENT_COLOR);
        lv_style_set_radius(&style_dro_panel, UNIT_MD);
        lv_style_set_pad_all(&style_dro_panel, UNIT_LG);

        lv_style_init(&style_axis_label);
        lv_style_set_text_color(&style_axis_label, TEXT_SECONDARY);
        lv_style_set_text_font(&style_axis_label, montserrat_14);

        lv_style_init(&style_position_value);
        lv_style_set_text_color(&style_position_value, ACCENT_COLOR);
        lv_style_set_text_font(&style_position_value, montserrat_20);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "main_#");
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
    lv_label_set_text(lv_label_0, "CNC Pendant - JOG MODE");
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
    lv_obj_set_width(lv_obj_4, lv_pct(90));
    lv_obj_set_height(lv_obj_4, 60);
    lv_obj_set_style_pad_all(lv_obj_4, UNIT_MD, 0);
    lv_obj_set_style_margin_bottom(lv_obj_4, UNIT_SM, 0);
    lv_obj_add_style(lv_obj_4, &style_dro_panel, 0);
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_4);
    lv_obj_set_style_flex_flow(lv_obj_5, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_5, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_5, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_1, "X:");
    lv_obj_set_style_text_color(lv_label_1, TEXT_SECONDARY, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_5);
    lv_label_bind_text(lv_label_2, &pos_x, NULL);
    lv_obj_set_style_text_color(lv_label_2, ACCENT_COLOR, 0);
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_3);
    lv_obj_set_width(lv_obj_6, lv_pct(90));
    lv_obj_set_height(lv_obj_6, 60);
    lv_obj_set_style_pad_all(lv_obj_6, UNIT_MD, 0);
    lv_obj_set_style_margin_bottom(lv_obj_6, UNIT_SM, 0);
    lv_obj_add_style(lv_obj_6, &style_dro_panel, 0);
    lv_obj_t * lv_obj_7 = lv_obj_create(lv_obj_6);
    lv_obj_set_style_flex_flow(lv_obj_7, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_7, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_7, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_7);
    lv_label_set_text(lv_label_3, "Y:");
    lv_obj_set_style_text_color(lv_label_3, TEXT_SECONDARY, 0);
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_7);
    lv_label_bind_text(lv_label_4, &pos_y, NULL);
    lv_obj_set_style_text_color(lv_label_4, ACCENT_COLOR, 0);
    
    lv_obj_t * lv_obj_8 = lv_obj_create(lv_obj_3);
    lv_obj_set_width(lv_obj_8, lv_pct(90));
    lv_obj_set_height(lv_obj_8, 60);
    lv_obj_set_style_pad_all(lv_obj_8, UNIT_MD, 0);
    lv_obj_set_style_margin_bottom(lv_obj_8, UNIT_SM, 0);
    lv_obj_add_style(lv_obj_8, &style_dro_panel, 0);
    lv_obj_t * lv_obj_9 = lv_obj_create(lv_obj_8);
    lv_obj_set_style_flex_flow(lv_obj_9, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_9, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_9, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_9);
    lv_label_set_text(lv_label_5, "Z:");
    lv_obj_set_style_text_color(lv_label_5, TEXT_SECONDARY, 0);
    
    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_9);
    lv_label_bind_text(lv_label_6, &pos_z, NULL);
    lv_obj_set_style_text_color(lv_label_6, ACCENT_COLOR, 0);
    
    lv_obj_t * lv_obj_10 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_10, lv_pct(100));
    lv_obj_set_height(lv_obj_10, 80);
    lv_obj_set_style_pad_all(lv_obj_10, UNIT_MD, 0);
    lv_obj_t * lv_obj_11 = lv_obj_create(lv_obj_10);
    lv_obj_set_style_flex_flow(lv_obj_11, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_11, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_11, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_11);
    lv_obj_set_width(lv_button_0, 100);
    lv_obj_set_height(lv_button_0, 50);
    lv_obj_add_style(lv_button_0, &style_button_primary, 0);
    lv_obj_t * lv_label_7 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_7, "ZERO");
    lv_obj_set_align(lv_label_7, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_button_1 = lv_button_create(lv_obj_11);
    lv_obj_set_width(lv_button_1, 100);
    lv_obj_set_height(lv_button_1, 50);
    lv_obj_add_style(lv_button_1, &style_button_primary, 0);
    lv_obj_t * lv_label_8 = lv_label_create(lv_button_1);
    lv_label_set_text(lv_label_8, "MACRO");
    lv_obj_set_align(lv_label_8, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_12 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_12, lv_pct(100));
    lv_obj_set_height(lv_obj_12, 30);
    lv_obj_set_style_bg_color(lv_obj_12, SECONDARY_BG, 0);
    lv_obj_t * lv_label_9 = lv_label_create(lv_obj_12);
    lv_label_bind_text(lv_label_9, &status_message, NULL);
    lv_obj_set_align(lv_label_9, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(lv_label_9, TEXT_SECONDARY, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

