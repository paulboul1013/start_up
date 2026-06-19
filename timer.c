#include "timer.h"
#include "time_parse.h"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void parse_state_from_args(State *state, int argc, char **argv){
    memset(state, 0 , sizeof(*state));

    state->wiggle_cooldown = WIGGLE_DURATION;
    state->user_scale = 1.0f;

    for (int i=1;i<argc;i++){
        if (strcmp(argv[i],"-p")==0){
            state->paused=1;
        }else if (strcmp(argv[i],"-e")==0){
            state->exit_after_countdown=1;
        }else if (strcmp(argv[i],"clock")==0){
            state->mode=MODE_CLOCK;
        }else{
            state->mode = MODE_COUNTDOWN;
            state->displayed_time = parse_time(argv[i]);
        }
    }
}

void state_update(State *state, float dt){
    if (state->wiggle_cooldown <= 0.0f) {
        state->wiggle_index++;
        state->wiggle_cooldown = WIGGLE_DURATION;
    }

    state->wiggle_cooldown -= dt;

    if (!state->paused){
        switch (state->mode){
            case MODE_ASCENDING: {
                state->displayed_time += dt;
            } break;

        case MODE_COUNTDOWN: {
            if (state->displayed_time > 1e-6) {
                state->displayed_time -= dt;
            } else {
                state->displayed_time = 0.0f;
                if (state->exit_after_countdown) {
                    exit(0);
                }
            }
        } break;

        case MODE_CLOCK: {
            float displayed_time_prev = state->displayed_time;
            time_t t=time(NULL);
            struct tm *tm = localtime(&t);
            state->displayed_time = tm->tm_sec + tm->tm_min * 60.0f + tm->tm_hour * 60.0f * 60.0f;
            if (state->displayed_time <= displayed_time_prev) {
                if (floorf(displayed_time_prev)==floorf(displayed_time_prev+dt)) {
                    state->displayed_time = displayed_time_prev + dt;
                } else {
                    state->displayed_time = displayed_time_prev;
                }
            }
        } break;
        }
    }
}