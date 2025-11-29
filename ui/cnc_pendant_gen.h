/**
 * @file cnc_pendant_gen.h
 */

#ifndef CNC_PENDANT_GEN_H
#define CNC_PENDANT_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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

#define UNIT_XS 4

#define UNIT_SM 8

#define UNIT_MD 12

#define UNIT_LG 16

#define UNIT_XL 24

#define OPA_DISABLED lv_pct(30)

#define OPA_MUTED lv_pct(60)

#define OPA_FULL lv_pct(100)

#define PRIMARY_BG lv_color_hex(0x1a1a1a)

#define SECONDARY_BG lv_color_hex(0x2d2d2d)

#define ACCENT_COLOR lv_color_hex(0x00cc66)

#define WARNING_COLOR lv_color_hex(0xff9900)

#define DANGER_COLOR lv_color_hex(0xff3333)

#define TEXT_PRIMARY lv_color_hex(0xffffff)

#define TEXT_SECONDARY lv_color_hex(0xcccccc)

#define BORDER_COLOR lv_color_hex(0x404040)

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    PENDANTMODE_MODE_JOG,
    PENDANTMODE_MODE_MACRO,
    PENDANTMODE_MODE_SETUP
}PendantMode_t;

typedef enum {
    AXISSELECT_AXIS_X,
    AXISSELECT_AXIS_Y,
    AXISSELECT_AXIS_Z,
    AXISSELECT_AXIS_A
}AxisSelect_t;

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_screen_base;
extern lv_style_t style_panel;
extern lv_style_t style_button_primary;
extern lv_style_t style_button_danger;

/*----------------
 * Fonts
 *----------------*/

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t current_mode;
extern lv_subject_t selected_axis;
extern lv_subject_t jog_speed;
extern lv_subject_t spindle_rpm;
extern lv_subject_t feed_override;
extern lv_subject_t pos_x;
extern lv_subject_t pos_y;
extern lv_subject_t pos_z;
extern lv_subject_t pos_a;
extern lv_subject_t machine_connected;
extern lv_subject_t status_message;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void cnc_pendant_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "screens/macros_gen.h"
#include "screens/main_gen.h"
#include "screens/setup_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CNC_PENDANT_GEN_H*/