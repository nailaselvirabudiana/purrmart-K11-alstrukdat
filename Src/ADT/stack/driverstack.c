#include <stdio.h>

#include "stack.h"

int main() {
    Stack S;
    CartItem item, poppedItem;

    CreateEmptyStack(&S);

    item.item.name = str2Word("Item1");
    item.quantity = 2;
    item.total_harga = 5000;
    Push(&S, item);

    item.item.name = str2Word("Item2");
    item.quantity = 3;
    item.total_harga = 8000;
    Push(&S, item);

    item.item.name = str2Word("Item3");
    item.quantity = 1;
    item.total_harga = 10000;
    Push(&S, item);


    printf("Isi stack awal:\n");
    PrintStack(S);


    printf("\nPop elemen:\n");
    Pop(&S, &poppedItem);
    printf("Item yang di-pop: %s %d %d\n", Word2str(poppedItem.item.name), poppedItem.quantity, poppedItem.total_harga);


    printf("\nIsi stack setelah pop:\n");
    PrintStack(S);


    printf("\nPanjang stack: %d\n", LengthStack(S));

 
    printf("\nMembalik urutan stack:\n");
    ReverseStack(&S);
    PrintStack(S);


    // printf("\nIsi stack tanpa tag:\n");
    // PrintStackWithoutTag(S);

    return 0;
}
