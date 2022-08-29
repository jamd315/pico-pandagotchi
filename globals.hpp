#ifndef _PANDAGOTCHI_GLOBALS_H
#define _PANDAGOTCHI_GLOBALS_H

// Graphics stuff
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define FACE_HEIGHT 64
#define FACE_WIDTH 64
#define FACE_LEFT (SCREEN_WIDTH - FACE_WIDTH) / 2
#define FACE_TOP (SCREEN_HEIGHT - FACE_HEIGHT) / 2
#define LEFT_EYE_LEFT FACE_LEFT + 19
#define LEFT_EYE_TOP 19
#define RIGHT_EYE_LEFT FACE_LEFT + 35
#define RIGHT_EYE_TOP 17
#define EYE_WIDTH 8
#define EYE_HEIGHT 8
#define MOUTH_LEFT FACE_LEFT + 20
#define MOUTH_TOP 28
#define MOUTH_WIDTH 24
#define MOUTH_HEIGHT 16
#define ICON_HEIGHT 16
#define ICON_WIDTH 16
#define WASTE_LEFT 80
#define WASTE_TOP 48

// Pins
//#define OLED_RESET 4  // Not really sure if this is needed
//#define SPEAKER_PIN 10
//#define ERROR_LED_PIN 9
//#define BTN_A_PIN 4
//#define BTN_B_PIN 5
//#define BTN_C_PIN 6

// Misc
#define DEBOUNCE_TIME 100

// Settings (comment out as needed)
//#define USE_SERIAL
#define USE_SOUND
//#define DISPLAY_DEBUG

#endif