#include <stdio.h>
#include "../ADT/stack/stack.h"
#include "../ADT/setmap/map.h"
#include "../ADT/store/store.h"
#include "user.h"
#include "../ADT/barang/barang.h"
#include "../ADT/store/store.h"


void cart_pay (Map *cart, int *uang_user, Stack *riwayat_pembelian, Word input);

void cart_add(Map *cart, CurrentBarang *barang, int jumlah);

void cart_remove(Map *cart, CurrentBarang *barang, int jumlah);

void printCart(Map cart);
