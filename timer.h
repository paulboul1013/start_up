#ifndef TIME_H
#define TIME_H


#include <stddef.h>
#include "config.h"

typedef enum {
    MODE_ASCENDING = 0,
    MODE_COUNTDOWN,
    MODE_CLOCK,
} Mode;

typedef struct {
    Mode mode;
    float displayed_time;
    int paused;
    int exit_after_countdown;

    int quit;
    size_t wiggle_index;
    float wiggle_cooldown;
    float user_scale;
    char prev_title[TITLE_CAP];
} State;

void parse_state_from_args(State *state, int argc, char **argv);
void state_update(State *state, float dt);



#endif