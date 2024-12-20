#include <stdio.h>
#include "stack.h"

typedef int infotypestack;
typedef int address;

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S) {
    S->TOP = NilStack;
}

void initStack(Stack *s) {
    s->TOP = NilStack;
}

boolean IsEmptyStack(Stack S) {
    return S.TOP == NilStack;
}

boolean IsFullStack(Stack S) {
    return S.TOP == MaxEl - 1;
}

// void Push(Stack *S, CartItem X) {
//     if (!IsFullStack(*S)) {
//         S->TOP++;
//         S->items[S->TOP] = X;
//     } else {
//         printf("Stack penuh. Tidak bisa menambahkan item.\n");
//     }
// }

// void Push(Stack *S, CartItem X) {

//     for (int i = 0; i<= S->TOP; i++) {
//         if (compareWord(S->items[i].item.name, X.item.name)) {
//             S->items[i].quantity += X.quantity;
//             return;
//         }
//     }
//     if (!IsFullStack(*S)) {
//         S->TOP++;
//         S->items[S->TOP] = X;
//     } else {
//         printf("Stack penuh. Tidak bisa menambahkan item.\n");
//     }
// }

void Push(Stack *S, CartItem X) {
    // Periksa apakah stack penuh
    if (!IsFullStack(*S)) {
        // Tambahkan elemen baru di posisi teratas
        S->TOP++;
        S->items[S->TOP] = X;
    } else {
        printf("Stack penuh. Tidak bisa menambahkan item.\n");
    }
}


void Pop(Stack *S, CartItem *X) {
    if (!IsEmptyStack(*S)) {
        *X = S->items[S->TOP];
        S->TOP--;
    } else {
        printf("Stack kosong. Tidak ada item untuk dihapus.\n");
    }
}

void PrintStack(Stack S) {
    if (IsEmptyStack(S)) {
        printf("riwayat kosong.\n");
    } else {
        printf("Isi riwayat:\n");
        for (int i = S.TOP, index = 1; i >= 0; i--, index++) {
            printf("%d. %s %d %d\n", index, Word2str(S.items[i].item), S.items[i].quantity, S.items[i].total_harga);
        }
    }
}



int LengthStack (Stack S){
    return S.TOP + 1;
}

void ReverseStack(Stack *S)
/* Membalikkan urutan elemen dalam stack */
{
    Stack temp;
    CreateEmptyStack(&temp);
    CartItem X;
    
    while (!IsEmptyStack(*S)) {
        Pop(S, &X);
        Push(&temp, X);
    }
    
    *S = temp;
}