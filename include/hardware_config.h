/**
 * @file hardware_config.h
 * @brief Hardware configuration for ESP32-S3 CNC Pendant
 * 
 * Define all hardware-specific pins and settings here.
 * Adjust these values based on your specific board.
 */

#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

/*********************
 *   DISPLAY CONFIG
 *********************/

/* Display resolution (round LCD) */
#define HW_LCD_WIDTH         480
#define HW_LCD_HEIGHT        480

/* Display SPI pins */
#define HW_LCD_PIN_CS        14
#define HW_LCD_PIN_SCLK      13
#define HW_LCD_PIN_MOSI      15
#define HW_LCD_PIN_DC        16
#define HW_LCD_PIN_RST       21
#define HW_LCD_PIN_BL        47

/* Display buffer configuration */
#define HW_LCD_BUF_HEIGHT    (HW_LCD_HEIGHT / 10)
#define HW_LCD_BIT_PER_PIXEL 16

/*********************
 *   TOUCH CONFIG
 *********************/

/* Touch controller I2C pins */
#define HW_TOUCH_I2C_SDA     11
#define HW_TOUCH_I2C_SCL     12
#define HW_TOUCH_I2C_INT     -1   // Optional interrupt pin

/* Touch controller I2C address */
#define HW_TOUCH_I2C_ADDR    0x15  // CST816/FT6336

/*********************
 *   ENCODER CONFIG
 *********************/

/* Rotary encoder pins */
#define HW_ENCODER_PIN_A     8    // CLK
#define HW_ENCODER_PIN_B     7    // DT
#define HW_ENCODER_PIN_SW    6    // Button

/*********************
 *   SYSTEM CONFIG
 *********************/

/* LVGL configuration */
#define HW_LVGL_TICK_MS      2
#define HW_LVGL_TASK_PRIO    2
#define HW_LVGL_TASK_STACK   (4 * 1024)

/* Serial configuration */
#define HW_SERIAL_BAUD       115200

/*********************
 *   BOARD PRESETS
 *********************/

/* Uncomment one of these for common board configurations */

// #define HW_BOARD_WAVESHARE_RP2040_TOUCH_LCD_1_28
// #define HW_BOARD_LILYGO_T_DISPLAY_S3
// #define HW_BOARD_SEEED_XIAO_ESP32S3_ROUND_DISPLAY
// #define HW_BOARD_CUSTOM

#ifdef HW_BOARD_WAVESHARE_RP2040_TOUCH_LCD_1_28
/* Waveshare RP2040-Touch-LCD-1.28 configuration */
/* Adjust for ESP32-S3 if using similar hardware */
#undef HW_LCD_WIDTH
#undef HW_LCD_HEIGHT
#define HW_LCD_WIDTH         240
#define HW_LCD_HEIGHT        240
#endif

#ifdef HW_BOARD_SEEED_XIAO_ESP32S3_ROUND_DISPLAY
/* Seeed Studio XIAO ESP32S3 with Round Display configuration */
#undef HW_LCD_WIDTH
#undef HW_LCD_HEIGHT
#define HW_LCD_WIDTH         240
#define HW_LCD_HEIGHT        240
/* Adjust other pins as needed */
#endif

#endif /*HARDWARE_CONFIG_H*/
