#include "barang.h"
#include <stdio.h>

CurrentBarang CreateInfoBarang (Word name, int price){
    CurrentBarang B;
    B.name = name;
    B.price = price;
    return B;
}

void printInfoBarang(CurrentBarang B) {
    printWord(B.name); printf(" - ");
    printWord(int2Word(B.price));
}

boolean isInfoBarangEmpty(CurrentBarang B) {
    return StringCompare(B.name, str2Word("-"));
}

boolean isInfoBarangEqual(CurrentBarang B1, CurrentBarang B2) {
    return StringCompare(B1.name, B2.name);
}

