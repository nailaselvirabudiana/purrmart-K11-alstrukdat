#include <stdio.h>
#include "list_dinamis.h"
#include "mesinkata.h"
#include "array.h"
#include "user.h"
#include "save.h"

// Fungsi untuk menulis
void writeToFile(FILE *file, ArrayDin *store, TabKata *arrusers, TabKata *arrpassword) {
    if (file != NULL) {
        // Menulis jumlah barang
        fprintf(file, "%d\n", store->Neff);
        for (int i = 0; i < store->Neff; i++) {
            // Menulis data barang (harga dan nama)
            fprintf(file, "%d %s\n", store->A[i].price, Word2str(store->A[i].name));
        }

        // Menulis jumlah pengguna
        fprintf(file, "%d\n", arrusers->Neff);
        for (int i = 0; i < arrusers->Neff; i++) {
            // Menulis username dan password
            fprintf(file, "%s %s\n", Word2str(arrusers->TI[i]), Word2str(arrpassword->TI[i]));
        }

        printf("Data berhasil disimpan ke file.\n");
        fclose(file);  // Menutup file setelah menulis
    } else {
        printf("File gagal disave.\n");
    }
}

// Menyimpan
void saveFile(char *filename, ArrayDin *store, TabKata *arrusers, TabKata *arrpassword) {
    char filepath[100];
    constructFilePath(filepath, "./save/", filename);  // Menyusun path file
    WRITEFILE(filepath); // Membuka file mode write
    if (currentFile != NULL) {
        writeToFile(currentFile, store, arrusers, arrpassword);  // Menulis data ke file
    } else {
        printf("Gagal membuka file untuk disimpan.\n");
    }

    END();  // Jangan lupa menutup file setelah selesai
}
