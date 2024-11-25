#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void loadFile(const char *filename, ArrayDin *store, List *user){
    FILE *file = READFILE(filename);
    if (file != NULL){
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        int Nitems;
        ReadInt(file, &Nitems);
        for (int i = 0; i < Nitems; i++){
            int harga;
            ReadInt(file, &harga);
            char name[100];
            ReadMultiple(file, name);
            CurrentBarang item = CreateInfoBarang(str2Word(name), harga);
            InsertLast(store, item);
        }

        int Nusers;
        ReadInt(file, &Nusers);
        currentWord = int2Word(Nusers);
        for (int i = 0; i < Nusers; i++){
            int uang;
            ReadInt(file, &uang);
            char usn[100];
            ReadWord(file, usn);
            char pw[100];
            ReadWord(file, pw);

            User pengguna = CreateUser(usn, pw, uang);
            InsertLastUser(user, pengguna);
        }
        fclose(file);
    }
    else{
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan. Anda otomatis Start\n");
    }
}