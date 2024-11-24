#ifndef __BARANG_H__
#define __BARANG_H__

#define MAX_LEN 20
#include "../mesinkata/mesinkata.h"

typedef struct {
  Word name;
  int price;
} CurrentBarang;

CurrentBarang CreateInfoBarang (Word name, int price);

void printInfoBarang(CurrentBarang B);

boolean isInfoBarangEmpty(CurrentBarang B);

boolean isInfoBarangEqual(CurrentBarang B1, CurrentBarang B2);


#endif