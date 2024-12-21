#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void loadFile(const char *filename, ArrayDin *store, List *user){
    FILE *file = READFILE(filename);
    if (file != NULL){
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        
        int N;
        ReadInt(file, &N);

        for (int i = 0; i < N; i++){
            int harga;
            ReadInt(file, &harga);
            char name[100];
            ReadMultiple(file, name);
            CurrentBarang item = CreateInfoBarang(str2Word(name), harga);
            InsertLast(store, item);
        }

        int M;
        ReadInt(file, &M);
        
        for (int i = 0; i < M; i++){
            int uang;
            ReadInt(file, &uang);
            char usn[100];
            ReadWord(file, usn);
            char pw[100];
            ReadWord(file, pw);
            
            Stack riwayat_pembelian;
            Map cart;
            CreateEmptyStack(&riwayat_pembelian);
            CreateEmptyMap(&cart);
            
            int K;
            ReadInt(file, &K);

            for (int a = 0; a < K; a++){
                int L; int X;
                ReadInt(file, &L);
                ReadInt(file, &X);
                CartItem endtrans;
                endtrans.item.name = str2Word("START_TRANSACTION");
                endtrans.quantity = L;
                endtrans.total_harga = X;
                Push(&riwayat_pembelian, endtrans);

                for (int c = 0; c < L; c++){
                    int totalbiaya;
                    ReadInt(file, &totalbiaya);
                    int qty;
                    ReadInt(file, &qty);
                    char namabarang[100];
                    ReadMultiple(file, namabarang);
                    CartItem items;
                    items.item.name = str2Word(namabarang);
                    items.quantity = qty;
                    items.total_harga = totalbiaya;
                    Push(&riwayat_pembelian, items);
                }

                CartItem starttrans;
                starttrans.item.name = str2Word("END_TRANSACTION");
                starttrans.quantity = L;
                starttrans.total_harga = X;
                Push(&riwayat_pembelian, starttrans);
            }

            Linkedlist wishlist;
            CreateEmpty(&wishlist);
            
            int J;
            ReadInt(file, &J);
            printf("%d", J);

            for (int b = 0; b < J; b++) {
                int skipint;
                ReadInt(file, &skipint);
                char namebarang[100];
                ReadMultiple(file, namebarang);
                InsVLast(&wishlist, str2Word(namebarang));
            }

            User pengguna = CreateUser(usn, pw, uang, riwayat_pembelian, cart, wishlist);
            InsertLastUser(user, pengguna);
        }

        ReverseStack(&user->A->riwayat_pembelian);
        
        fclose(file);
    }
    else{
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan. Anda otomatis Start.\n");
    }
}