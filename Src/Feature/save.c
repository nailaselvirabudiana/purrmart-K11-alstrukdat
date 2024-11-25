#include <stdio.h>
#include "../ADT/list/list.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "save.h"

// Fungsi untuk menulis
void writeToFile(FILE *file, ArrayDin *store, List *user) {
    if (file != NULL) {
        // Menulis jumlah barang
        fprintf(file, "%d\n", store->Neff);
        for (int i = 0; i < store->Neff; i++) {
            // Menulis data barang (harga dan nama)
            fprintf(file, "%d %s\n", store->A[i].price, Word2str(store->A[i].name));
        }

        // Menulis jumlah pengguna
        fprintf(file, "%d\n", user->Neff);
        for (int i = 0; i < user->Neff; i++) {
            // Menulis username dan password
            fprintf(file, "%d %s ", user->A[i].uang, user->A[i].nama);
            fprintf(file, "%s\n", user->A[i].password);
        }

        printf("Savefile berhasil disimpan.\n");
        END();  // Menutup file setelah menulis
    } else {
        printf("File gagal disimpan.\n");
    }
}

// Menyimpan
void saveFile(const char *filename, ArrayDin *store, List *user) {
    FILE *file = WRITEFILE(filename);
    if (file != NULL) {
        writeToFile(file, store, user);  // Menulis data ke file
    } else {
        printf("Gagal membuka file untuk disimpan.\n");
    }

    END();  // Jangan lupa menutup file setelah selesai :D
}