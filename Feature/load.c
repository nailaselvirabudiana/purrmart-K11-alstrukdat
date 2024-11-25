#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void loadFile(const char *filename, ArrayDin store, List money, List arrusers, List arrpassword){
    store = MakeArrayDin();
    BarangElType item;
    MakeEmpty(&money); MakeEmpty(&arrusers); MakeEmpty(&arrpassword);
    FILE *file = READFILE(filename);
    if (file != NULL){
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        int Nitems;
        ReadInt(file, &Nitems);
        printf("Jumlah barang: %d\n", Nitems);
        for (int i = 0; i < Nitems; i++){
            int harga;
            ReadInt(file, &harga);
            item.price = harga;
            printf("harga: %d\n", item.price);
            char barang[100];
            ReadWord(file, barang);
            item.name = str2Word(barang);
            printWord(item.name);
            printf("\n");
            InsertLast(&store, item);
        }

        int Nusers;
        ReadInt(file, &Nusers);
        printf("Jumlah pengguna: %d\n", Nusers);
        for (int i = 0; i < Nusers; i++){
            int uang;
            ReadInt(file, &uang);
            Word duit = int2Word(uang);
            AddElmt(&money, duit);
            printWord(duit);
            printf("\n");
            char usn[100];
            ReadWord(file, usn);
            Word username = str2Word(usn);
            AddElmt(&arrusers, username);
            printWord(username);
            printf("\n");
            char pw[100];
            ReadWord(file, pw);
            Word password = str2Word(pw);
            AddElmt(&arrpassword, password);
            printWord(password);
            printf("\n");
        }
        END();
        printf("%d\n", store.Neff);
    }
    else{
        printf("PURRMART gk bs jalan.");
    }
}