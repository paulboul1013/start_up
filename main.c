#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "timer.h"

static const char *mode_name(Mode mode){
    switch (mode){
        case MODE_ASCENDING:
            return "mode_ascending";
        case MODE_COUNTDOWN:
            return "mode_countdown";
        case MODE_CLOCK:
            return "mode_clock";
        default:
            return "mode_unknown";
    }
}

static void print_state(const char *label, const State *state)
{
    printf("==== %s ====\n", label);
    printf("mode                 = %s\n", mode_name(state->mode));
    printf("displayed_time       = %.3f\n", state->displayed_time);
    printf("paused               = %d\n", state->paused);
    printf("exit_after_countdown = %d\n", state->exit_after_countdown);
    printf("quit                 = %d\n", state->quit);
    printf("wiggle_index         = %zu\n", state->wiggle_index);
    printf("wiggle_cooldown      = %.3f\n", state->wiggle_cooldown);
    printf("user_scale           = %.3f\n", state->user_scale);
    printf("\n");
}

int main(int argc, char **argv){
    
    // char *time_str="1:20:30";
    // float time=parse_time(time_str);
    // printf("%.2f\n",time);

    State state;
    
    parse_state_from_args(&state,argc,argv);

    print_state("after parse_state_from_args()",&state);

    float dt = 1.0f;

    for(int i=0;i<5;i++){
        state_update(&state,dt);
        
        char label[64];
        snprintf(label,sizeof(label),"After state_update() frame %d",i+1);

        print_state(label,&state);
    }
    
    
    return 0;
}