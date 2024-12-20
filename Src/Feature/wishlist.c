#include <stdio.h>
#include "wishlist.h"
#include "../ADT/linkedlist/linkedlist.h"
#include "../ADT/list_dinamis/list_dinamis.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"

void WishlistAdd(ArrayDin S, Linkedlist *W){
    printf("Masukkan nama barang : ");
    STARTWORD();
    Word add = ReadLine();
    IdxType P = SearchNameArrayDin(S, add); //store
    Address Q = Search(*W, add); //wishlist
    if(P == -1){
        printf("Tidak ada barang dengan nama ");
        printWord(add);
        printf("!\n");
    }else if(Q == Nil){
        InsVLast(W, add);
        printf("Berhasil menambahkan ");
        printWord(add);
        printf(" ke wishlist!\n");
    }else if(Q != Nil){
        printWord(add);
        printf(" sudah ada di wishlist!\n");
    }
}

void WishlistSwap(Linkedlist *W, int swap1, int swap2){
    Address s1 = First(*W);
    Address s2 = First(*W);
    if(isEmpty(*W)){
        printf("Wishlist kosong!\n");
    }else{
        for(int i = 0; i<swap1-1; i++){
            s1 = Next(s1);
            if(s1 == Nil){
                break;
            }
        }
        for(int i = 0; i<swap2-1; i++){
            s2 = Next(s2);
            if(s2 == Nil){
                break;
            }
        }
        if(s1 == Nil){
            printf("Penukaran gagal, Barang ke-%d tidak ada di wishlist\n", swap1);
        }else if(s2 == Nil){
            printf("Penukaran gagal, Barang ke-%d tidak ada di wishlist\n", swap2);
        }else if(swap1 == 1){
            Address Temp;
            Address Prev2 = First(*W);
            for(int i = 0; i<swap2-2; i++){
                Prev2 = Next(Prev2);
            }
            if(swap2-swap1 == 1){
                Next(s1) = Next(s2);
                Next(s2) = s1;
                First(*W) = s2;
            }else{
                Temp = Next(s2);
                Next(s2) = Next(s1);
                Next(Prev2) = s1;
                Next(s1) = Temp;
                First(*W) = s2;
            }
            printf("Berhasil menukar posisi %s ",  Word2str(s1->info));
            printf("dengan %s pada wishlist!\n", Word2str(s2->info));
        }else{
            Address Temp;
            Address Prev1 = First(*W);
            Address Prev2 = First(*W);
            for(int i = 0; i<swap1-2; i++){
                Prev1 = Next(Prev2);
            }
            if(swap2-swap1 == 1){
                Next(s1) = Next(s2);
                Next(s2) = s1;
                Next(Prev1) = s2;
            }else{
                for(int i = 0; i<swap2-2; i++){
                    Prev2 = Next(Prev2);
                }
                Temp = Next(s2);
                Next(Prev1) = s2;
                Next(s2) = Next(s1);
                Next(Prev2) = s1;
                Next(s1) = Temp; 
            }
            printf("Berhasil menukar posisi %s ",  Word2str(s1->info));
            printf("dengan %s pada wishlist!\n", Word2str(s2->info));
        }
    }
}

void WishlistRemovePos(Linkedlist *W, int iremove){
    Address A = First(*W);
    if(isEmpty(*W)){
        printf("Penghapusan barang wishlist gagal dilakukan, wishlist kosong!\n");
    }else{
        for(int i = 0; i<iremove-1; i++){
            A = Next(A);
            if(A == Nil){
                break;
            }
        }
        if(A == Nil){
            printf("Penghapusan barang wishlist gagal dilakukan, Barang ke-%d tidak ada di wishlist!\n", iremove);
        }else{
            DelP(W, Info(A));
            printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", iremove);
        }
    }
    return;
}

void WishlistRemove(Linkedlist *W){
    printf("Masukkan nama barang yang ingin dihapus : ");
    STARTWORD();
    Word remove = ReadLine();
    Address R = Search(*W, remove);
    if(R == Nil){
        printf("Penghapusan barang WISHLIST gagal dilakukan, ");
        printWord(remove);
        printf(" tidak ada di wishlist\n");
    }else{
        DelP(W, remove);
        printWord(remove);
        printf(" berhasil dihapus dari wishlist\n");
    }    
}

void WishlistClear(Linkedlist *W){
    printf("wishlist telah dikosongkan.\n");
    Address P = First(*W);
    Address temp;
    while(P!=Nil){
        temp = P;
        P = Next(P);
        Dealokasi(&temp);
    }
    First(*W) = Nil;
}

void WishlistShow(Linkedlist W){
    if(isEmpty(W)){
        printf("Wishlist kamu kosong!\n");
    }else{
        printf("Berikut ini adalah wishlist-mu:\n");
        int i = 1;
        Address D = First(W);
        while(D != Nil){
            printf("%d ", i);
            printWord(Info(D));
            printf("\n");
            i++;
            D = Next(D);
        }
    }
}
