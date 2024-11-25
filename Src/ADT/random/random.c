#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#include "../mesinkata/mesinkata.h"

int Random(){
    int max_num = 100;
    srand(time(0));
    
    int random = (rand() % max_num) + 1;
    
    return random;
}

char* katarandom(const char *words[], int wordCount) {
    // Map the random number (1 to 100) to a valid index (0 to wordCount - 1)
    int randomIndex = (Random() - 1) % wordCount;

    // Explicitly cast away the const qualifier
    return (char*)words[randomIndex];
}