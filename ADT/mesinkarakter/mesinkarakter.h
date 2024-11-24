#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include <stdio.h>
#include "../boolean.h"

#define MARK '\n'        // Define the MARK character for end of processing
#define MAX_LENGTH 1000 // Maximum length of the input string


extern char currentChar;
extern boolean EOP;
void START();
void SecondStart();
void END();
void ADV();
char GetCC();
boolean IsEOP();
int panjangKarakter(char s[]);

#endif
