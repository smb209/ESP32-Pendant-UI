/**
 * @file macros_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "macros_gen.h"
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

lv_obj_t * macros_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_macro_button;
    static lv_style_t style_macro_button_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_macro_button);
        lv_style_set_bg_color(&style_macro_button, SECONDARY_BG);
        lv_style_set_border_width(&style_macro_button, 2);
        lv_style_set_border_color(&style_macro_button, ACCENT_COLOR);
        lv_style_set_radius(&style_macro_button, UNIT_MD);
        lv_style_set_pad_all(&style_macro_button, UNIT_LG);
        lv_style_set_width(&style_macro_button, 200);
        lv_style_set_height(&style_macro_button, 80);

        lv_style_init(&style_macro_button_pressed);
        lv_style_set_bg_color(&style_macro_button_pressed, ACCENT_COLOR);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "macros_#");
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
    lv_label_set_text(lv_label_0, "MACRO COMMANDS");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_style_flex_grow(lv_obj_2, 1, 0);
    lv_obj_set_width(lv_obj_2, lv_pct(100));
    lv_obj_set_style_pad_all(lv_obj_2, UNIT_LG, 0);
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
    lv_obj_set_style_flex_flow(lv_obj_3, LV_FLEX_FLOW_COLUMN, 0);
    lv_obj_set_width(lv_obj_3, lv_pct(100));
    lv_obj_set_style_flex_cross_place(lv_obj_3, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(lv_obj_3, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_flex_flow(lv_obj_4, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_style_flex_main_place(lv_obj_4, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_set_width(lv_obj_4, lv_pct(100));
    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_4);
    lv_obj_add_style(lv_button_0, &style_macro_button, 0);
    lv_obj_add_style(lv_button_0, &style_macro_button_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_1 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_1, "PROBE Z");
    lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_button_1 = lv_button_create(lv_obj_4);
    lv_obj_add_style(lv_button_1, &style_macro_button, 0);
    lv_obj_add_style(lv_button_1, &style_macro_button_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_2 = lv_label_create(lv_button_1);
    lv_label_set_text(lv_label_2, "HOME ALL");
    lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_flex_flow(lv_obj_5, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_style_flex_main_place(lv_obj_5, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_set_width(lv_obj_5, lv_pct(100));
    lv_obj_t * lv_button_2 = lv_button_create(lv_obj_5);
    lv_obj_add_style(lv_button_2, &style_macro_button, 0);
    lv_obj_add_style(lv_button_2, &style_macro_button_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_3 = lv_label_create(lv_button_2);
    lv_label_set_text(lv_label_3, "ZERO XY");
    lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_button_3 = lv_button_create(lv_obj_5);
    lv_obj_add_style(lv_button_3, &style_macro_button, 0);
    lv_obj_add_style(lv_button_3, &style_macro_button_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_4 = lv_label_create(lv_button_3);
    lv_label_set_text(lv_label_4, "ZERO Z");
    lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_3);
    lv_obj_set_style_flex_flow(lv_obj_6, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_style_flex_main_place(lv_obj_6, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_set_width(lv_obj_6, lv_pct(100));
    lv_obj_t * lv_button_4 = lv_button_create(lv_obj_6);
    lv_obj_add_style(lv_button_4, &style_macro_button, 0);
    lv_obj_add_style(lv_button_4, &style_macro_button_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_5 = lv_label_create(lv_button_4);
    lv_label_set_text(lv_label_5, "GOTO ZERO");
    lv_obj_set_align(lv_label_5, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_button_5 = lv_button_create(lv_obj_6);
    lv_obj_add_style(lv_button_5, &style_macro_button, 0);
    lv_obj_add_style(lv_button_5, &style_macro_button_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_6 = lv_label_create(lv_button_5);
    lv_label_set_text(lv_label_6, "UNLOCK");
    lv_obj_set_align(lv_label_6, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_7 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_7, lv_pct(100));
    lv_obj_set_height(lv_obj_7, 80);
    lv_obj_set_style_pad_all(lv_obj_7, UNIT_MD, 0);
    lv_obj_t * lv_obj_8 = lv_obj_create(lv_obj_7);
    lv_obj_set_style_flex_flow(lv_obj_8, LV_FLEX_FLOW_ROW, 0);
    lv_obj_set_width(lv_obj_8, lv_pct(100));
    lv_obj_set_style_flex_main_place(lv_obj_8, LV_FLEX_ALIGN_SPACE_AROUND, 0);
    lv_obj_t * lv_button_6 = lv_button_create(lv_obj_8);
    lv_obj_set_width(lv_button_6, 120);
    lv_obj_set_height(lv_button_6, 50);
    lv_obj_add_style(lv_button_6, &style_button_primary, 0);
    lv_obj_t * lv_label_7 = lv_label_create(lv_button_6);
    lv_label_set_text(lv_label_7, "BACK");
    lv_obj_set_align(lv_label_7, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_9 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_9, lv_pct(100));
    lv_obj_set_height(lv_obj_9, 30);
    lv_obj_set_style_bg_color(lv_obj_9, SECONDARY_BG, 0);
    lv_obj_t * lv_label_8 = lv_label_create(lv_obj_9);
    lv_label_bind_text(lv_label_8, &status_message, NULL);
    lv_obj_set_align(lv_label_8, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(lv_label_8, TEXT_SECONDARY, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

