/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

#ifndef _BOARDS_ADAFRUIT_MACROPAD_RP2040_H
#define _BOARDS_ADAFRUIT_MACROPAD_RP2040_H

// For board detection
#define ADAFRUIT_MACROPAD_RP2040

// On some samples, the xosc can take longer to stabilize than is usual
#ifndef PICO_XOSC_STARTUP_DELAY_MULTIPLIER
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64
#endif

// --- BOARD SPECIFIC ---
#ifndef ADAFRUIT_MACROPAD_KEY1_PIN
#define ADAFRUIT_MACROPAD_KEY1_PIN 1
#endif

#ifndef ADAFRUIT_MACROPAD_KEY2_PIN
#define ADAFRUIT_MACROPAD_KEY2_PIN 2
#endif

#ifndef ADAFRUIT_MACROPAD_KEY3_PIN
#define ADAFRUIT_MACROPAD_KEY3_PIN 3
#endif

#ifndef ADAFRUIT_MACROPAD_KEY4_PIN
#define ADAFRUIT_MACROPAD_KEY4_PIN 4
#endif

#ifndef ADAFRUIT_MACROPAD_KEY5_PIN
#define ADAFRUIT_MACROPAD_KEY5_PIN 5
#endif

#ifndef ADAFRUIT_MACROPAD_KEY6_PIN
#define ADAFRUIT_MACROPAD_KEY6_PIN 6
#endif

#ifndef ADAFRUIT_MACROPAD_KEY7_PIN
#define ADAFRUIT_MACROPAD_KEY7_PIN 7
#endif

#ifndef ADAFRUIT_MACROPAD_KEY8_PIN
#define ADAFRUIT_MACROPAD_KEY8_PIN 8
#endif

#ifndef ADAFRUIT_MACROPAD_KEY9_PIN
#define ADAFRUIT_MACROPAD_KEY9_PIN 9
#endif

#ifndef ADAFRUIT_MACROPAD_KEY10_PIN
#define ADAFRUIT_MACROPAD_KEY10_PIN 10
#endif

#ifndef ADAFRUIT_MACROPAD_KEY11_PIN
#define ADAFRUIT_MACROPAD_KEY11_PIN 11
#endif

#ifndef ADAFRUIT_MACROPAD_KEY12_PIN
#define ADAFRUIT_MACROPAD_KEY12_PIN 12
#endif

#ifndef ADAFRUIT_MACROPAD_LED_PIN
#define ADAFRUIT_MACROPAD_LED_PIN 13
#endif

#ifndef ADAFRUIT_MACROPAD_SPEAKER_ENABLE_PIN
#define ADAFRUIT_MACROPAD_SPEAKER_ENABLE_PIN 14
#endif

#ifndef ADAFRUIT_MACROPAD_SPEAKER_PIN
#define ADAFRUIT_MACROPAD_SPEAKER_PIN 16
#endif

#ifndef ADAFRUIT_MACROPAD_BUTTON_PIN
#define ADAFRUIT_MACROPAD_BUTTON_PIN 0
#endif

#ifndef ADAFRUIT_MACROPAD_ROTA_PIN
#define ADAFRUIT_MACROPAD_ROTA_PIN 17
#endif

#ifndef ADAFRUIT_MACROPAD_ROTB_PIN
#define ADAFRUIT_MACROPAD_ROTB_PIN 18
#endif

#ifndef ADAFRUIT_MACROPAD_NEOPIXEL_PIN
#define ADAFRUIT_MACROPAD_NEOPIXEL_PIN 19
#endif

#ifndef ADAFRUIT_MACROPAD_DISPLAY_OLED_CS_PIN
#define ADAFRUIT_MACROPAD_DISPLAY_OLED_CS_PIN 22
#endif

#ifndef ADAFRUIT_MACROPAD_DISPLAY_OLED_RESET_PIN
#define ADAFRUIT_MACROPAD_DISPLAY_OLED_RESET_PIN 23
#endif

#ifndef ADAFRUIT_MACROPAD_DISPLAY_OLED_DC_PIN
#define ADAFRUIT_MACROPAD_DISPLAY_OLED_DC_PIN 24
#endif

#ifndef ADAFRUIT_MACROPAD_DISPLAY_SCK_PIN
#define ADAFRUIT_MACROPAD_DISPLAY_SCK_PIN 26
#endif

#ifndef ADAFRUIT_MACROPAD_DISPLAY_MOSI_PIN
#define ADAFRUIT_MACROPAD_DISPLAY_MOSI_PIN 27
#endif

#ifndef ADAFRUIT_MACROPAD_DISPLAY_MISO_PIN
#define ADAFRUIT_MACROPAD_DISPLAY_MISO_PIN 28
#endif

// no PICO_DEFAULT_UART

//------------- LED -------------//
#ifndef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN ADAFRUIT_MACROPAD_LED_PIN
#endif

#ifndef PICO_DEFAULT_WS2812_PIN
#define PICO_DEFAULT_WS2812_PIN ADAFRUIT_MACROPAD_NEOPIXEL_PIN
#endif

//------------- I2C -------------//
#ifndef PICO_DEFAULT_I2C
#define PICO_DEFAULT_I2C 0
#endif

#ifndef PICO_DEFAULT_I2C_SDA_PIN
#define PICO_DEFAULT_I2C_SDA_PIN 20
#endif

#ifndef PICO_DEFAULT_I2C_SCL_PIN
#define PICO_DEFAULT_I2C_SCL_PIN 21
#endif

//------------- SPI -------------//
#ifndef PICO_DEFAULT_SPI
#define PICO_DEFAULT_SPI 1
#endif

#ifndef PICO_DEFAULT_SPI_TX_PIN
#define PICO_DEFAULT_SPI_TX_PIN 27
#endif

#ifndef PICO_DEFAULT_SPI_RX_PIN
#define PICO_DEFAULT_SPI_RX_PIN 28
#endif

#ifndef PICO_DEFAULT_SPI_SCK_PIN
#define PICO_DEFAULT_SPI_SCK_PIN 26
#endif

//------------- FLASH -------------//

// Use slower generic flash access
#define PICO_BOOT_STAGE2_CHOOSE_GENERIC_03H 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 4
#endif

#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (8 * 1024 * 1024)
#endif

// All boards have B1 RP2040
#ifndef PICO_FLOAT_SUPPORT_ROM_V1
#define PICO_FLOAT_SUPPORT_ROM_V1 0
#endif

#ifndef PICO_DOUBLE_SUPPORT_ROM_V1
#define PICO_DOUBLE_SUPPORT_ROM_V1 0
#endif

#endif
