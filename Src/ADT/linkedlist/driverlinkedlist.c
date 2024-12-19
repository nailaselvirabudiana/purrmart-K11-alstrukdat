#include <stdio.h>
#include "linkedlist.h"
#include "../list_dinamis/list_dinamis.h"
#include "../mesinkata/mesinkata.h"
#include "../barang/barang.h"

int main(){
    Linkedlist wishlist;
    CreateEmpty(&wishlist);
    ArrayDin store = MakeArrayDin();
    CurrentBarang barang = CreateInfoBarang(str2Word("AK-48"), 10);
    InsertLast(&store, barang);



}