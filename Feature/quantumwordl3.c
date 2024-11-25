#include <stdio.h>
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
# include "../ADT/random/random.h"
#include "../ADT/delay/delay.h"
#include "quantumwordl3.h"

// gcc ADT/mesinkarakter/mesinkarakter.c ADT/mesinkata/mesinkata.c ADT/random/random.c quantumwordle.c ADT/delay/delay.c -o tes
#define MAX_LENGTH 1000  // Definisi maks array

void QuantumWordle() {
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
    char *kata1 = katarandom(words, wordCount);
    wait_for_seconds(1);
    char *kata2 = katarandom(words, wordCount);
    wait_for_seconds(1);    
    char *kata3 = katarandom(words, wordCount);
    wait_for_seconds(1);
    char *kata4 = katarandom(words, wordCount);                                             
                                                        



    printf("==============WELCOME TO QUANTUM WORDLE===================\n");
    printf("You have 9 chance to guess 4 words.\n");
    printf("Good luck!\n");
    printf("!char! is Right placed \n(char) is contains the character \n|char| is false \n");

    Word str1;
    Word str2;
    Word str3;
    Word str4;

    for (int try = 0; try < 9; try++) {

        boolean correct1 = false;
        boolean correct2 = false;
        boolean correct3 = false;
        boolean correct4 = false;

        //Mulai masukin kata
        printf("Input 4 WORD. THE REST OF THE WORD WILL BE IGNORED! (5 char) : \n>> ");
        STARTWORD();
        str1 = currentWord;
        ADVWORD();
        str2 = currentWord;
        ADVWORD();
        str3 = currentWord;
        ADVWORD();
        str4 = currentWord;
        IgnoreRest();

        // Checking panjang harus 5
        while (str1.Length != 5 || str2.Length != 5 || str3.Length != 5 || str4.Length != 5) {

            printf("The length of the string must be 5. Please try again.\n");
            printf(">> ");
            STARTWORD();
            str1 = currentWord;
            ADVWORD();
            str2 = currentWord;
            ADVWORD();
            str3 = currentWord;
            ADVWORD();
            str4 = currentWord;
            IgnoreRest();
            printf("%d %d %d %d\n", str1.Length, str2.Length, str3.Length, str4.Length);
        }

        // Compare
        if (!compareWord(str1, str2Word(kata1))) {
        for (int j = 0; j < 5; j++) {
            if (kata1[j] == Word2str(str1)[j]) {
                printf("!%c! ", Word2str(str1)[j]);
            }
            else if (isOnWord(str2Word(kata1), Word2str(str1)[j])) {
                printf("(%c) ", Word2str(str1)[j]);
            } else {
                printf("|%c| ", Word2str(str1)[j]);
            }
        }
            printf("    ");
        } else {
            printf("string 1 correct\n");
            correct1 = true;
            printf("    ");

        }

        if (!compareWord(str2, str2Word(kata2))) {
        for (int j = 0; j < 5; j++) {
            if (kata2[j] == Word2str(str2)[j]) {
                printf("!%c! ", Word2str(str2)[j]);
            }
            else if (isOnWord(str2Word(kata2), Word2str(str2)[j])) {
                printf("(%c) ", Word2str(str2)[j]);
            } else {
                printf("|%c| ", Word2str(str2)[j]);
            }
        }
            printf("    ");
        } else {
            printf("string 2 correct");
            correct2 = true;
            printf("    ");

        }

        if (!compareWord(str3, str2Word(kata3))) {
        for (int j = 0; j < 5; j++) {
            if (kata3[j] == Word2str(str3)[j]) {
                printf("!%c! ", Word2str(str3)[j]);
            }
            else if (isOnWord(str2Word(kata3), Word2str(str3)[j])) {
                printf("(%c) ", Word2str(str3)[j]);
            } else {
                printf("|%c| ", Word2str(str3)[j]);
            }
        }
            printf("    ");
        } else {
            printf("string 3 correct");
            correct3 = true;
            printf("    ");
        }

        if (!compareWord(str4, str2Word(kata4))) {
        for (int j = 0; j < 5; j++) {
            if (kata3[j] == Word2str(str3)[j]) {
                printf("!%c! ", Word2str(str3)[j]);
            }
            else if (isOnWord(str2Word(kata3), Word2str(str3)[j])) {
                printf("(%c) ", Word2str(str3)[j]);
            } else {
                printf("|%c| ", Word2str(str3)[j]);
            }
        }
            printf("    ");
        } else {
            printf("string 4 correct");
            correct4 = true;
            printf("    ");

        }

        printf("\n");

        if (correct1 && correct2 && correct3 && correct4) {
            break;
        } else {
            printf("!!!!!!!!             You have %d chance left            !!!!!!!!\n", 8 - try);
        }






    }
    if (!compareWord(str1, str2Word(kata1))) {
        printf("The correct answer is %s\n", kata1);
    }
    if (!compareWord(str2, str2Word(kata2))) {
        printf("The correct answer is %s\n", kata2);
    }
    if (!compareWord(str3, str2Word(kata3))) {
        printf("The correct answer is %s\n", kata3);
    }
    if (!compareWord(str4, str2Word(kata4))) {
        printf("The correct answer is %s\n", kata4);
    }
    if (compareWord(str1, str2Word(kata1)) && compareWord(str2, str2Word(kata2)) && compareWord(str3, str2Word(kata3)) && compareWord(str4, str2Word(kata4)) ) {
        printf("YOU'RE SUCH A MASTER. TAKE ALL THE MONEY\n");
    } else {
        printf("You lose the game!! Try again, if you can.\n");
    }


}