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

            // Riwayat Maksimal
            Stack tempStack;
            CreateEmptyStack(&tempStack);
            int total_riwayat = 0;

            while (!IsEmptyStack(user->A[i].riwayat_pembelian)) {
                CartItem brg;
                Pop(&user->A[i].riwayat_pembelian, &brg);
                if (compareWord(brg.item.name, str2Word("END_TRANSACTION"))){
                    total_riwayat++;
                }
                Push(&tempStack, brg);
            }
            
            fprintf(file, "%d\n", total_riwayat);
            while (!IsEmptyStack(tempStack)){
                CartItem hist;
                Pop(&tempStack, &hist);
                if (compareWord(hist.item.name, str2Word("END_TRANSACTION"))){
                    fprintf(file, "%d %d\n", hist.quantity, hist.total_harga);
                }
                else{
                    fprintf(file, "%d %d %s\n", hist.total_harga, hist.quantity, Word2str(hist.item.name));
                }
            }

            // Wishlist
            int J = NbElmt(user->A[i].wishlist);
            Address wl = First(user->A[i].wishlist);
            fprintf(file, "%d\n", J);
            for (int j = 0; j < J; j++){
                fprintf(file, "%s\n", Word2str(Info(wl)));
                wl = Next(wl);
            }
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