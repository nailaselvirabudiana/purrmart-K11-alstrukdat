#include <stdio.h>
#include "list_dinamis.h"

int main() {

    ArrayDin array = MakeArrayDin();


    ArrayElType item1;
    ArrayElType item2;
    ArrayElType item3;
    ArrayElType item4;
    ArrayElType item5;

    item1.name = str2Word("Platypus Laser");
    item2.name = str2Word("Shrink Ray");
    item3.name = str2Word("Net Shooter");
    item4.name = str2Word("Anjay mabar");
    item5.name = str2Word("apalagi ya ?");

    InsertLast(&array, item1);
    InsertLast(&array, item2);
    InsertLast(&array, item3);
    InsertLast(&array, item4);
    InsertLast(&array, item5);


    printf("Isi toko: ");
    PrintArrayDin(array);

    // Mencari elemen di array
    printf("\nMencari 'Shrink Ray': ");
    ArrayElType searchItem; 
    searchItem.name = str2Word("Shrink Ray");
    int index = SearchArrayDin(array, searchItem);
    if (index != -1) {
        printf("Ditemukan di index %d\n", index);
    } else {
        printf("Tidak ditemukan\n");
    }

    // Menghapus elemen pertama
    DeleteFirst(&array);
    printf("\nSetelah menghapus elemen pertama:\n");
    PrintArrayDin(array);

    //insert first
    ArrayElType item6;

    item6.name = str2Word("hiohoho");
    InsertFirst(&array,item6);
    PrintArrayDin(array);

    //delete last
    DeleteLast(&array);
    printf("\nSetelah menghapus elemen terakhir:\n");
    PrintArrayDin(array);

    DeallocateArrayDin(&array);

    return 0;
}
