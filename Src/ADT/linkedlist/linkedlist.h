#ifndef Linkedlist_H
#define Linkedlist_H

#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../boolean.h"

#define Nil NULL

typedef Word Infotype;
typedef struct node* Address;
typedef struct node {
    Infotype info;
    Address next;
} Node;
typedef struct {
    Address First;
} Linkedlist;

#define Index(p) (p)->index;
#define Info(p) (p)->info
#define Next(p) (p)->next
#define First(L) ((L).First)

// boolean isEmpty(Linkedlist L);

void CreateEmpty(Linkedlist *L);

Address Alokasi(Infotype X);

void Dealokasi(Address *P);

Address Search (Linkedlist L, Infotype X);

void InsVFirst (Linkedlist *L, Infotype X);

void InsVLast (Linkedlist *L, Infotype X);

// void DelVFirst (Linkedlist *L, Infotype *X);

// void DelVLast (Linkedlist *L, Infotype *X);

// void InsFirst (Linkedlist *L, Address P);

// void InsAfter (Linkedlist *L, Address P, Address Prec);

// void InsLast (Linkedlist *L, Address P);

// void DelFirst (Linkedlist *L, Address *P);

void DelP (Linkedlist *L, Infotype X);

// void DelLast (Linkedlist *L, Address *P);

// void DelAfter (Linkedlist *L, Address *Pdel, Address Prec);

void PrintInfo (Linkedlist L);

// int NbElmt (Linkedlist L);

// void InversLinkedlist (Linkedlist *L);

// void Konkat1 (Linkedlist *L1, Linkedlist *L2, Linkedlist *L3);

#endif