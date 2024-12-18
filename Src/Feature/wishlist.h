#ifndef wishlist_h
#define wishlist_h

#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/linkedlist/linkedlist.h"
#include "../ADT/list_dinamis/list_dinamis.h"

void WishlistAdd(ArrayDin S, Linkedlist *W);

void WishlistSwap(Linkedlist *W, int swap1, int swap2);

void WishlistRemovePos(Linkedlist *W, int iremove);

void WishlistRemove(Linkedlist *W);

void WishlistClear(Linkedlist *W);

void WishlistShow(Linkedlist W);

#endif

