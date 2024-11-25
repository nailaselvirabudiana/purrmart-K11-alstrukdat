#include <stdlib.h>
#include <stdio.h>
#include "list_dinamis.h"

ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.Capacity = InitialSize;
    array.Neff = 0;
    array.A = (ArrayElType *)malloc(array.Capacity * sizeof(ArrayElType));
    return array;
}

void DeallocateArrayDin(ArrayDin *array) {
    for (int i = 0; i < array->Neff; i++) {

        free(array->A[i].name.TabWord);
    }
    free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

boolean IsEmptyList(ArrayDin array) {
    return array.Neff == 0;
}

int LengthArray(ArrayDin array) {
    return array.Neff;
}

int GetCapacity(ArrayDin array) {
    return array.Capacity;
}

void ResizeArray(ArrayDin *array, int newCapacity) {
    array->Capacity = newCapacity;
    array->A = (ArrayElType *)realloc(array->A, newCapacity * sizeof(ArrayElType));
}

void InsertAt(ArrayDin *array, ArrayElType el, IdxType i) {
    if (array->Neff >= array->Capacity) {
        ResizeArray(array, array->Capacity * 2); 
    }

    for (IdxType j = array->Neff; j > i; j--) {
        array->A[j] = array->A[j - 1];
    }

    array->A[i] = el; 
    array->Neff++;
}

void InsertLast(ArrayDin *array, ArrayElType el) {
    InsertAt(array, el, array->Neff);
}

void InsertFirst(ArrayDin *array, ArrayElType el) {
    InsertAt(array, el, 0);
}

void DeleteAt(ArrayDin *array, IdxType i) {

    if (i == array->Neff - 1) {
        array->Neff--;
    } else {
        
        for (IdxType j = i; j < array->Neff - 1; j++) {
            array->A[j].name = CloneWord(array->A[j + 1].name);
        }
        array->Neff--;
    }

    // Resize jika diperlukan
    if (array->Neff <= array->Capacity / 4 && array->Capacity > InitialSize) {
        ResizeArray(array, array->Capacity / 2);
    }
}

void DeleteLast(ArrayDin *array) {
    DeleteAt(array, array->Neff - 1);
}

void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}

IdxType SearchArrayDin(ArrayDin array, ArrayElType item) {
    for (IdxType i = 0; i < array.Neff; i++) {
        if (StringCompare(array.A[i].name, item.name)) {
            return i;
        }
    }
    return -1; 
}

void PrintArrayDin(ArrayDin array) {
    printf("[");
    for (int i = 0; i < array.Neff; i++) {
        printWord(array.A[i].name);
        // printf(" (Rp%d)", array.A[i].price);
        if (i < array.Neff - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
