#include <stdio.h>
#include "barang.h"

int main() {

    Word name1 = str2Word("PlatypusLaser");
    int price1 = 15000000;
    CurrentBarang barang1 = CreateInfoBarang(name1, price1);

    Word name2 = str2Word("ayamgoreng");
    int price2 = 5000000;
    CurrentBarang barang2 = CreateInfoBarang(name2, price2);

    Word name3 = str2Word("ayamgoreng");
    int price3 = 5000000;
    CurrentBarang barang3 = CreateInfoBarang(name3, price3);

    printf("Informasi Barang 1: ");
    printInfoBarang(barang1);
    printf("\n");

    printf("Informasi Barang 2: ");
    printInfoBarang(barang2);
    printf("\n");

    printf("Informasi Barang 3: ");
    printInfoBarang(barang3);
    printf("\n");

    if (isInfoBarangEmpty(barang1)) {
        printf("Barang 1 kosong.\n");
    } else {
        printf("Barang 1 tidak kosong.\n");
    }

    if (isInfoBarangEqual(barang1, barang2)) {
        printf("Barang 1 dan Barang 2 sama.\n");
    } else {
        printf("Barang 1 dan Barang 2 berbeda.\n");
    }

    if (isInfoBarangEqual(barang2, barang3)) {
        printf("Barang 2 dan Barang 3 sama.\n");
    } else {
        printf("Barang 2 dan Barang 3 berbeda.\n");
    }

    return 0;
}
