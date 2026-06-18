#include "time_parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float parse_time(const char *time) {
    float result = 0.0f;

    while (*time) {
        char *end_ptr=NULL;
        float second=strtof(time,&end_ptr);
        
        if (time==end_ptr){
            fprintf(stderr,"`%s` is not a number\n",time);
            exit(1);
        }

        if (isspace(*end_ptr)){
            end_ptr++;
        }

        switch (*end_ptr){
            case '\0':
            case 's':
                result+=second;
                break;
            case 'm':
                result+=second * 60.0f;
                break;
            case 'h':
                result+=second*60.0f*60.0f;
                break;
            default:
                fprintf(stderr,"`%c` is wrong time format\n",*end_ptr);
                exit(1);
        }

        time=end_ptr; //point to s,m,h,'\0' characters
        if (*time) { //skip s,m,h characters
            time++;
        }
    }

    return result;
}