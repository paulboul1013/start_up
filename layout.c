#include "layout.h"
#include "config.h"

#include <math.h>

void initial_pen(
    int w,
    int h,
    int *pen_x,
    int *pen_y,
    float user_scale,
    float *fit_scale
){

    if (w <= 0 || h <= 0) {
        *pen_x = 0;
        *pen_y = 0;
        *fit_scale = 1.0f;
        return;
    }

    float text_aspect_ratio = (float) TEXT_WIDTH / (float) TEXT_HEIGHT;
    float window_aspect_ratio = (float)w/ (float)h;

    if (text_aspect_ratio  > window_aspect_ratio){
        *fit_scale = (float)w /(float) TEXT_WIDTH;
    } else{
        *fit_scale = (float)h /(float) TEXT_HEIGHT;
    }

    const int effective_digit_width = (int)floorf((float)CHAR_WIDTH * user_scale * (*fit_scale));
    const int effective_digit_height = (int)floorf((float)CHAR_HEIGHT * user_scale * (*fit_scale));

    *pen_x = w/2 -effective_digit_width * CHARS_COUNT/2;
    *pen_y = h/2 -effective_digit_height/2;

}