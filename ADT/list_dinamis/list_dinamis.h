// list_barang.h
#ifndef LIST_DINAMIS_H
#define LIST_DINAMIS_H

#include "../mesinkata/mesinkata.h"
#include "../barang/barang.h"


#define InitialSize 10
#define MAX_LEN 20
typedef int IdxType;
typedef CurrentBarang ArrayElType;

// typedef struct {
//     char name[MAX_LEN];
//     int money;
// }User;

typedef struct {
    ArrayElType *A;
    int Capacity;
    int Neff;
} ArrayDin;

#define A(AD) (AD).A
#define Cap(AD) (AD).Capacity
#define Neff(AD) (AD).Neff


ArrayDin MakeArrayDin();
void DeallocateArrayDin(ArrayDin *array);
boolean IsEmptyList(ArrayDin array);
int Lengtharray(ArrayDin array);
int GetCapacity(ArrayDin array);
void InsertAt(ArrayDin *array, ArrayElType el, IdxType i);
void InsertLast(ArrayDin *array, ArrayElType el);
void InsertFirst(ArrayDin *array, ArrayElType el);
void DeleteAt(ArrayDin *array, IdxType i);
void DeleteLast(ArrayDin *array);
void DeleteFirst(ArrayDin *array);
void PrintArrayDin(ArrayDin array);
IdxType SearchArrayDin(ArrayDin array, ArrayElType item);

#endif
