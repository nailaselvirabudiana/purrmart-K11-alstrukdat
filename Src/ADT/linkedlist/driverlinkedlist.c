#include <stdio.h>
#include "linkedlist.h"
#include "../list_dinamis/list_dinamis.h"
#include "../mesinkata/mesinkata.h"
#include "../barang/barang.h"

int main(){
    Linkedlist wishlist;
    CreateEmpty(&wishlist);
    ArrayDin store = MakeArrayDin();
    CurrentBarang barang1 = CreateInfoBarang(str2Word("AK-48"), 10);
    CurrentBarang barang2 = CreateInfoBarang(str2Word("AK-49"), 11);
    CurrentBarang barang3 = CreateInfoBarang(str2Word("AK-50"), 12);
    //Memasukkan barang ke store
    InsertLast(&store, barang1);
    InsertLast(&store, barang2);
    InsertLast(&store, barang3);
    //memasukkan barang ke wishlist
    InsVFirst(&wishlist, barang1.name);
    InsVLast(&wishlist, barang2.name);
    InsVFirst(&wishlist, barang3.name);
    PrintInfo(wishlist);
    //menghapus barang dari wishlist
    DelP(&wishlist, barang3.name);
    PrintInfo(wishlist);
    
    return 0;
}   