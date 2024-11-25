#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita = NULL; // Initialize the file pointer
static int retval;

void START() {
    /* Mesin siap dioperasikan, pita disiapkan untuk membaca dari stdin */
    pita = stdin;
    ADV(); // Read the first character
    EOP = false;
}

void END() {
    /* Proses pita selesai, menutup file jika dibuka. */
    if (pita != NULL) {
        fclose(pita);
        pita = NULL;
    }
}

void ADV() {
    /* Pita dimajukan satu karakter. EOP di-update jika Enter ditekan. */
    retval = fscanf(pita, "%c", &currentChar); // Read next character
    EOP = (retval == EOF || currentChar == '\n'); // Set EOP if EOF or Enter
}

char GetCC() {
    /* Mengembalikan karakter saat ini (currentChar). */
    return currentChar;
}

boolean IsEOP() {
    /* Mengembalikan true jika EOP tercapai. */
    return EOP;
}

int panjangKarakter(char s[]) {
    /* Menghitung panjang string hingga EOP atau batas karakter tercapai. */
    int i = 0; // Index for the string
    while (!IsEOP() && i < MAX_LENGTH - 1) { // Ensure we don't overflow
        s[i] = GetCC(); // Store the current character in the string
        i++;
        ADV(); // Advance to the next character
    }
    s[i] = '\0'; // Null-terminate the string
    return i; // Return the length of the string
}

FILE* READFILE(const char *filename) {
    return fopen(filename, "r");
}

FILE* WRITEFILE(const char *filename) {
    return fopen(filename, "w");
}