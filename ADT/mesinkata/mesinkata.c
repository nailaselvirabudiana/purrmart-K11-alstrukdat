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

// Removed duplicate PrintWord function since it's the same as printWord