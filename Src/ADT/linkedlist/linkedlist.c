#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

boolean isEmpty(Linkedlist L){
    return First(L) == Nil;
}

void CreateEmpty(Linkedlist *L){
    First(*L) = Nil;
}

Address Alokasi(Infotype X){
    Address P = (Address)malloc(sizeof(Node));
    if(P != Nil){
        P->info = X;
        P->next = Nil;
    }
    return P;
}

void Dealokasi(Address *P){
    free(*P);
    *P = Nil;
}

Address Search(Linkedlist L, Infotype X){
    Address P = First(L);
    while(P!=Nil){
        if(compareWord(Info(P), X)){
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsVFirst(Linkedlist *L, Infotype X){
    Address P = Alokasi(X);
    if(P!=Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(Linkedlist *L, Infotype X){
    Address P = Alokasi(X);
    if (P != Nil) {
        if (isEmpty(*L)) {
            First(*L) = P;
        } else {
            Address Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirst(Linkedlist *L, Infotype *X){
    if (!isEmpty(*L)) {
        Address P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        Dealokasi(&P);
    }
}

void DelVLast(Linkedlist *L, Infotype *X){
    if (!isEmpty(*L)) {
        Address P = First(*L);
        Address Prec = Nil;
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        *X = Info(P);
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
        Dealokasi(&P);
    }
}

void InsFirst(Linkedlist *L, Address P){
    Next(P) = First(*L);
    First(*L) = P;
}

void InsAfter(Linkedlist *L, Address P, Address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsLast(Linkedlist *L, Address P) {
    if (isEmpty(*L)) {
        First(*L) = P;
    } else {
        Address Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

void DelFirst(Linkedlist *L, Address *P) {
    if (!isEmpty(*L)) {
        *P = First(*L);
        First(*L) = Next(*P);
        Next(*P) = Nil;
    }
}

void DelP(Linkedlist *L, Infotype X) {
    Address P = First(*L);
    Address Prec = Nil;
    while (P != Nil && !compareWord(Info(P), X)) {
        Prec = P;
        P = Next(P);
    }
    if (P != Nil) {
        if (Prec == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Dealokasi(&P);
    }
}

void DelLast(Linkedlist *L, Address *P) {
    if (!isEmpty(*L)) {
        Address Last = First(*L);
        Address Prec = Nil;
        while (Next(Last) != Nil) {
            Prec = Last;
            Last = Next(Last);
        }
        *P = Last;
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
    }
}

void DelAfter(Linkedlist *L, Address *Pdel, Address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

void PrintInfo(Linkedlist L) {
    printf("[");
    Address P = First(L);
    while (P != Nil) {
        printWord(Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}

int NbElmt2(Linkedlist L) {
    int count = 0;
    Address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

void InversLinkedlist(Linkedlist *L) {
    Address Prev = Nil;
    Address Curr = First(*L);
    Address Next;
    while (Curr != Nil) {
        Next = Next(Curr);
        Next(Curr) = Prev;
        Prev = Curr;
        Curr = Next;
    }
    First(*L) = Prev;
}

void Konkat1(Linkedlist *L1, Linkedlist *L2, Linkedlist *L3) {
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    if (!isEmpty(*L1)) {
        Address Last = First(*L1);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
