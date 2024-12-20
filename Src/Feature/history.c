#include "history.h"
#include <stdio.h>
#include "../ADT/boolean.h"


void show_history(Stack riwayat_pembelian, int n) {
    if (IsEmptyStack(riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n\n");

    int transactions = 0;
    int start_idx = riwayat_pembelian.TOP;
    int end_idx = riwayat_pembelian.TOP;

    CartItem X;


    Pop(&riwayat_pembelian, &X);

    ReverseStack(&riwayat_pembelian);

    // Iterasi untuk memproses setiap transaksi
    while (transactions < n && start_idx >= 0) {

        while (start_idx >= 0 && 
               !compareWord(riwayat_pembelian.items[start_idx].item, str2Word("END_TRANSACTION"))) {
            start_idx--;
        }

        if (start_idx >= 0) {
            
            int total_harga = riwayat_pembelian.items[start_idx].total_harga;


            transactions++;
            printf("Pembelian %d - Total %d\n", transactions, total_harga);
            printf("%-10s | %-15s | %-10s\n", "Kuantitas", "Nama Barang", "Total Harga");
            printf("---------------------------------------------\n");

            // Cetak item dalam transaksi
            for (int j = start_idx + 1; j <= end_idx; j++) {
                if (!compareWord(riwayat_pembelian.items[j].item, str2Word("END_TRANSACTION"))) {
                    printf("%-10d | %-15s | %-10d\n",
                           riwayat_pembelian.items[j].quantity,
                           Word2str(riwayat_pembelian.items[j].item),
                           riwayat_pembelian.items[j].total_harga);
                }
            }
            printf("\n");


            end_idx = start_idx - 1;
            start_idx--;
        }
    }


    ReverseStack(&riwayat_pembelian);
}