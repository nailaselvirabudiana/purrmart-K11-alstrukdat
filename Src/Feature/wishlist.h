#ifndef wishlist_h
#define wishlist_h

#include "mesinkata.h"
#include "mesinkarakter.h"
#include "linkedlist.h"
#include "list_dinamis.h"

void WishlistAdd(ArrayDin S, List *W);

void WishlistSwap(List *W);

void WishlistRemovePos(List *W);

void WishlistRemove(List *W);

void WishlistClear(List *W);

void WishlistShow(List W);

#endif

