/**
 * @file cnc_pendant_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "cnc_pendant_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

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

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_screen_base;
lv_style_t style_panel;
lv_style_t style_button_primary;
lv_style_t style_button_danger;

/*----------------
 * Fonts
 *----------------*/

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t current_mode;
lv_subject_t selected_axis;
lv_subject_t jog_speed;
lv_subject_t spindle_rpm;
lv_subject_t feed_override;
lv_subject_t pos_x;
lv_subject_t pos_y;
lv_subject_t pos_z;
lv_subject_t pos_a;
lv_subject_t machine_connected;
lv_subject_t status_message;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void cnc_pendant_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_screen_base);
        lv_style_set_bg_color(&style_screen_base, PRIMARY_BG);
        lv_style_set_text_color(&style_screen_base, TEXT_PRIMARY);

        lv_style_init(&style_panel);
        lv_style_set_bg_color(&style_panel, SECONDARY_BG);
        lv_style_set_border_width(&style_panel, 2);
        lv_style_set_border_color(&style_panel, BORDER_COLOR);
        lv_style_set_radius(&style_panel, UNIT_SM);
        lv_style_set_pad_all(&style_panel, UNIT_MD);

        lv_style_init(&style_button_primary);
        lv_style_set_bg_color(&style_button_primary, ACCENT_COLOR);
        lv_style_set_text_color(&style_button_primary, TEXT_PRIMARY);
        lv_style_set_radius(&style_button_primary, UNIT_SM);
        lv_style_set_pad_all(&style_button_primary, UNIT_MD);

        lv_style_init(&style_button_danger);
        lv_style_set_bg_color(&style_button_danger, DANGER_COLOR);
        lv_style_set_text_color(&style_button_danger, TEXT_PRIMARY);
        lv_style_set_radius(&style_button_danger, UNIT_SM);
        lv_style_set_pad_all(&style_button_danger, UNIT_MD);

        style_inited = true;
    }

    /*----------------
     * Fonts
     *----------------*/


    /*----------------
     * Images
     *----------------*/
    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&current_mode, 0);
    lv_subject_init_int(&selected_axis, 0);
    lv_subject_init_int(&jog_speed, 50);
    lv_subject_set_min_value_int(&jog_speed, 1);
    lv_subject_set_max_value_int(&jog_speed, 100);
    lv_subject_init_int(&spindle_rpm, 0);
    lv_subject_set_min_value_int(&spindle_rpm, 0);
    lv_subject_set_max_value_int(&spindle_rpm, 24000);
    lv_subject_init_int(&feed_override, 100);
    lv_subject_set_min_value_int(&feed_override, 10);
    lv_subject_set_max_value_int(&feed_override, 200);
    static char pos_x_buf[UI_SUBJECT_STRING_LENGTH];
    static char pos_x_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&pos_x,
                           pos_x_buf,
                           pos_x_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "0.000"
                          );
    static char pos_y_buf[UI_SUBJECT_STRING_LENGTH];
    static char pos_y_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&pos_y,
                           pos_y_buf,
                           pos_y_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "0.000"
                          );
    static char pos_z_buf[UI_SUBJECT_STRING_LENGTH];
    static char pos_z_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&pos_z,
                           pos_z_buf,
                           pos_z_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "0.000"
                          );
    static char pos_a_buf[UI_SUBJECT_STRING_LENGTH];
    static char pos_a_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&pos_a,
                           pos_a_buf,
                           pos_a_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "0.000"
                          );
    lv_subject_init_int(&machine_connected, 0);
    static char status_message_buf[UI_SUBJECT_STRING_LENGTH];
    static char status_message_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&status_message,
                           status_message_buf,
                           status_message_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Ready"
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */

    /* Register subjects */
    lv_xml_register_subject(NULL, "current_mode", &current_mode);
    lv_xml_register_subject(NULL, "selected_axis", &selected_axis);
    lv_xml_register_subject(NULL, "jog_speed", &jog_speed);
    lv_xml_register_subject(NULL, "spindle_rpm", &spindle_rpm);
    lv_xml_register_subject(NULL, "feed_override", &feed_override);
    lv_xml_register_subject(NULL, "pos_x", &pos_x);
    lv_xml_register_subject(NULL, "pos_y", &pos_y);
    lv_xml_register_subject(NULL, "pos_z", &pos_z);
    lv_xml_register_subject(NULL, "pos_a", &pos_a);
    lv_xml_register_subject(NULL, "machine_connected", &machine_connected);
    lv_xml_register_subject(NULL, "status_message", &status_message);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/