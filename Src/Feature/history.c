#include "history.h"
#include <stdio.h>
#include "../ADT/boolean.h"

void show_history(Stack riwayat_pembelian, int n) {
    if (IsEmptyStack(riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    int length = LengthStack(riwayat_pembelian); 
    int transaksi_cnt = 0; 
    int transaksi_total = 0; 
    boolean is_new_transaction = true;
    printf("Riwayat pembelian barang:\n\n");
    for (int i = 0; i < length; i++) {
        CartItem current_item = riwayat_pembelian.items[i];
        if (compareWord(current_item.item.name, str2Word("END_TRANSACTION"))) {
            if (!is_new_transaction) {
                printf("Total %d\n\n", transaksi_total); 
            }
            transaksi_cnt++;
            transaksi_total = 0; 
            is_new_transaction = true;
            if (transaksi_cnt >= n) {
                break;
            }
    } else {
            if (is_new_transaction) {
                printf("Pembelian %d\n", transaksi_cnt + 1, transaksi_total); 
                is_new_transaction = false;
                printf("Kuantitas\tNama\t\tTotal\n");
            }
            printf("%d\t\t%-10s\t%d\n",
                   current_item.quantity,
                   Word2str(current_item.item.name),
                   current_item.total_harga);
        
            transaksi_total += current_item.total_harga;
        }
    }
    if (!is_new_transaction) {
        printf("Total %d\n", transaksi_total);
    }
}