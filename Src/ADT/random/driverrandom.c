
#include <stdio.h>
#include "ADT/random/random.h"

int main() {
    // Array of words
    const char *words[] = {
        "APPLE",
        "TORCH",
        "START",
        "QUEST",
        "BERRY",
        "WATER",
        "GRAPE",
        "HONEY",
        "ZEBRA",
        "LEMON"
    };
    int wordCount = sizeof(words) / sizeof(words[0]);

    // Test Random function
    int randNumber = Random();
    printf("Random number (1 to 100): %d\n", randNumber);

    // Test katarandom function
    char *kata = katarandom(words, wordCount);;
    printf("Randomly chosen word: %s\n", kata);

    return 0;
}
