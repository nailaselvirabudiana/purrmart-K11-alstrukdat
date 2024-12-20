#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while ((currentChar == BLANK) && (currentChar != MARK)) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void CopyWord() {
    currentWord.Length = 0;
    while ((currentChar != BLANK) && (currentChar != MARK)) {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        } else {
            break;
        }
    }
}

boolean isEndWord() {
    return EndWord;
}

boolean StringCompare(Word kata1, Word kata2) {
    if (kata1.Length != kata2.Length) {
        return false;
    }
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

Word str2Word(char* String) {
    Word kata;
    int i = 0;
    while (String[i] != '\0' && i < NMax) {
        kata.TabWord[i] = String[i];
        i++;
    }
    kata.Length = i;
    return kata;
}

char* Word2str(Word Kata) {
    static char str[NMax + 1]; // +1 for null terminator
    for (int i = 0; i < Kata.Length; i++) {
        str[i] = Kata.TabWord[i];
    }
    str[Kata.Length] = '\0';
    return str;
}

void printWord(Word Kata) {
    for(int i = 0; i < Kata.Length; i++) {
        printf("%c", Kata.TabWord[i]);
    }
}

int Word2int(Word Kata) {
    int r = 0, i = Kata.Length, pengali = 1;
    while(i--) {
        r += (Kata.TabWord[i] - '0') * pengali;
        pengali *= 10;
    }
    return r;
}

Word int2Word(int Angka) {
    Word Kata;
    char tmpc;
    int tmp = Angka, l = 0, i;

    if (Angka == 0) {
        Kata.TabWord[0] = '0';
        Kata.Length = 1;
        return Kata;
    }

    while(tmp > 0) {
        l++;
        tmp /= 10;
    }

    tmp = Angka;
    for(i = l - 1; i >= 0; i--) {
        Kata.TabWord[i] = '0' + tmp % 10;
        tmp /= 10;
    }
    
    Kata.Length = l;
    return Kata;
}

Word CloneWord(Word kata) {
    Word copy = kata;
    return copy;
}

boolean compareWord(Word kata1, Word kata2) {
    if (kata1.Length != kata2.Length) {
        return false;
    }
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

char isOnWord(Word kata, char c) {
    for (int i = 0; i < kata.Length; i++) {
        if (kata.TabWord[i] == c) {
            return 1;
        }
    }
    return 0;
}

void STARTINPUT()
{
    currentWord = str2Word("");
    STARTWORD(stdin);
}

void ReadInt(FILE *file, int *angka) {
    fscanf(file, "%d", angka);
}

void ReadWord(FILE *file, char *str) {
    fscanf(file, "%s", str);
}

void ReadMultiple(FILE *file, char *str) {
    fscanf(file, "%[^\n]", str);
}

void IgnoreRest() {
    while (!EOP) {
        ADVWORD();
    }
}

Word ConcatWord(Word K1, Word K2)
{
    Word K3 = K1;
	int i, j = 0;
	int l = K1.Length + K2.Length;
	for (i = K1.Length; i < l; i++) {
		K3.TabWord[i] = K2.TabWord[j];
		K3.Length++;
		j++;
	}
	return K3;
}

Word ReadLine() {
    Word result;
    result.Length = 0;
    
    if (!EndWord) {
        for (int i = 0; i < currentWord.Length; i++) {
            result.TabWord[result.Length++] = currentWord.TabWord[i];
        }
    }

    while (!EOP && currentChar != '\n') {

        if (result.Length < NMax) {
            result.TabWord[result.Length++] = BLANK;
        }
        
        ADVWORD();
        
        if (!EndWord) {
            for (int i = 0; i < currentWord.Length; i++) {
                if (result.Length < NMax) {
                    result.TabWord[result.Length++] = currentWord.TabWord[i];
                }
            }
        }
    }
    
    return result;
}

boolean isKataInteger(Word W) {
    for (int i = 0; i < W.Length; i++) {
        if (W.TabWord[i] < '0' || W.TabWord[i] > '9') {
            return false;
        }
    }
    return true;
}

// Removed duplicate PrintWord function since it's the same as printWord