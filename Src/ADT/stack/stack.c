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

void Push(Stack *S, CartItem X) {

    for (int i = 0; i<= S->TOP; i++) {
        if (compareWord(S->items[i].item.name, X.item.name)) {
            S->items[i].quantity += X.quantity;
            return;
        }
    }
    if (!IsFullStack(*S)) {
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
        printf("Cart kosong.\n");
    } else {
        printf("Isi Cart:\n");
        for (int i = S.TOP, index = 1; i >= 0; i--, index++) {
            printf("%d. %s %d\n", index, S.items[i].item.name, S.items[i].quantity);
        }
    }
}

int TotalQuantity(Stack S) {
    int total = 0;
    for (int i = 0; i <= S.TOP; i++) {
        total += S.items[i].quantity;
    }
    return total;
}

boolean IsMemberStack(Stack S, CartItem X) {
    for (int i = 0; i <= S.TOP; i++) {
        if (compareWord(S.items[i].item.name, X.item.name) == 0) {
            return true;
        }
    }
    return false;
}

int LengthStack (Stack S){
    return S.TOP + 1;
}