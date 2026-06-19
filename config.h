#ifndef CONFIG_H
#define CONFIG_H

#define FPS 60
#define COLON_INDEX 10 //0~9 are digits and 10 is colon
#define SPRITE_CHAR_WIDTH (300 / 2)
#define SPRITE_CHAR_HEIGHT (380 / 2)
#define WIGGLE_COUNT 3
#define WIGGLE_DURATION (0.40f / WIGGLE_COUNT)
#define CHAR_WIDTH (300 / 2) 
#define CHAR_HEIGHT (380 / 2)
#define CHARS_COUNT 8 //HH:MM:SS
#define TEXT_WIDTH (CHAR_WIDTH * CHARS_COUNT)
#define TEXT_HEIGHT (CHAR_HEIGHT)

#define MAIN_COLOR_R 220 //rgb(220,220,220) gray
#define MAIN_COLOR_G 220
#define MAIN_COLOR_B 220

#define PAUSE_COLOR_R 220 //rgb(220,120,120) red
#define PAUSE_COLOR_G 120
#define PAUSE_COLOR_B 120

#define BACKGROUND_COLOR_R 24 //rgb(24,24,24) black
#define BACKGROUND_COLOR_G 24
#define BACKGROUND_COLOR_B 24

#define PENGER_STEPS_PER_SECOND 3
#define PENGER_SCALE 4
#define SCALE_FACTOR 0.15f

#define TITLE_CAP 256


#endif