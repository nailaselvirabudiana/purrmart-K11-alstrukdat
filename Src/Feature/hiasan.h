#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#define INTERVAL (0.1 * CLOCKS_PER_SEC) // tenth second


#define BAR_WIDTH 30                    // Lebar progres bar

void loading_animation(int duration);

void opening();