#include <stdio.h>
#include <time.h>
#include "delay.h"
#include "../../Feature/hiasan.h"

void wait_for_seconds(int seconds) {
    time_t start_time = time(0); 
    while (time(0) - start_time < seconds) {
        loading_animation(seconds);
    }
}

void sleep(int seconds){
    time_t start_time = time(0); 
    while (time(0) - start_time < seconds) {
    }
}