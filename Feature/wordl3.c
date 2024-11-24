#include <stdio.h>
#include "wordl3.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
# include "../ADT/random/random.h"

#define MAX_LENGTH 1000  // Definisi maks array

void wordl3() {
    // Kumpulan karakter yg dirandom
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
        "LEMON",
        "MANGO",
        "BREAK",
        "SWEET",
        "SALTY",
        "SUGAR",
        "SPICE",
        "BREAD",
        "CAKES",
        "PIZZA",
        "PASTA",
        "STEAK",
        "SALAD",
        "SUSHI",
        "CURRY",
        "GIVEN"
    };
    int wordCount = sizeof(words) / sizeof(words[0]);

    // Random number
    int randNumber = Random();

    // Random kata
    char *kata = katarandom(words, wordCount);

    printf("=======================WORDLE==============================\n");
    printf("Welcome to WORDLE.\nYou have 5 chance to guess the word.\n");
    printf("Good luck!\n");
    printf("!char! is Right placed \n(char) is contains the character \n|char| is false \n");
    // Declare max string length
    char str[MAX_LENGTH];
    int length;
    // Loop pengulagan maks 5 kali
    for (int try = 0; try < 6; try++) {

        //Mulai masukin kata
        printf("Input WORD (max 5 char) : \n>> ");

        START();
        length = panjangKarakter(str);

        // Checking panjang harus 5
        while (length != 5) {
            printf("The length of the string must be 5. Please try again.\n");
            printf(">> ");
            START();
            length = panjangKarakter(str);
        }



        // Compare
        for (int j = 0; j < 5; j++) {
            if (kata[j] == str[j]) {
                printf("!%c! ", str[j]);
            }
            else if (isOnWord(str2Word(kata), str[j])) {
                printf("(%c) ", str[j]);
            } else {
                printf("|%c| ", str[j]);
            }
        }
        printf("\n");
        if (compareWord(str2Word(str), str2Word(kata))) {
            printf("===================The string is correct. You get 100 bucks===============================\n");
            break;
        }

    }
    printf("\n");



    // Use the manual string comparison function
    if (!compareWord(str2Word(str), str2Word(kata))) {
        printf("The correct string is: %s\n", kata);
        printf("Uh-oh You lose, better luck next time!\n");
        printf("=====================================================================\n");
    }
}