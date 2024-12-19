#include <stdio.h>
#include <stdlib.h>
#include "store.h"


void handle_store_request(Queue *request_queue, ArrayDin store) {
    BarangElType item;
    printf("Masukkan nama barang yang ingin diminta: ");
    STARTWORD();
    item.name = ReadLine();
    store_request(request_queue, store, item);
    printf("\n");
}

void handle_store_supply(ArrayDin *store, Queue *request_queue) {
    if (queueisEmpty(*request_queue)) {
        printf("Antrean kosong! Tidak ada barang untuk disuplai.\n");
        return;
    }

    boolean exitSupply = false;
    while (!exitSupply) {
        BarangElType item = HEAD(*request_queue);
        printf("Barang dalam antrean: ");
        printWord(item.name);
        printf("\n");

        printf("Apakah kamu ingin menambahkan barang ");
        printWord(item.name);
        printf(" : ");
        STARTWORD();
        ADVWORD();
        Word command = currentWord;
        printf("\n");

        if (compareWord(command, str2Word("Terima"))) {
            int price = 0;
            while (price <= 0) {
                printf("Masukkan harga barang: ");
                STARTWORD();
                ADVWORD();
                price = Word2int(currentWord);
                if (price <= 0) {
                    printf("Harga tidak valid, ");
                }
            }
            store_supply(store, request_queue, command, price);
            break;
        } else if (compareWord(command, str2Word("Tunda")) || 
                   compareWord(command, str2Word("Tolak"))) {
            store_supply(store, request_queue, command, 0);
            break;
        } else if (compareWord(command, str2Word("Purry"))) {
            printf("<Kembali ke menu>\n");
            exitSupply = true;
        } else {
            printf("Command tidak valid!\n");
        }
    }
}

void handle_store_remove(ArrayDin *store) {
    printf("Masukkan nama barang yang ingin dihapus dari toko: ");
    BarangElType item;
    STARTWORD();
    item.name = ReadLine();
    // item.name = currentWord;
    store_remove(store, item.name);
    printf("\n");
}


//fungsi menampilkan barang
void store_list(ArrayDin store) {
    if (IsEmptyList(store)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < store.Neff; i++) {
            printf("- ");
            printWord(store.A[i].name);
            // //DEBUG
            // printf(" - %d", store.A[i].price);
            printf("\n");
        }
    }
}

// Fungsi untuk menambahkan permintaan item baru ke antrian
void store_request(Queue *request_queue, ArrayDin store, BarangElType item) {

    for (int i = 0; i < store.Neff; i++) {
        if (isInfoBarangEqual(store.A[i], item)) {
            printf("Barang ");
            printWord(item.name);
            printf(" sudah ada di toko!\n");
            return;
        }
    }

    if (!queueisEmpty(*request_queue)) {
        for (int i = request_queue->idxHead; i <= request_queue->idxTail; i++) {
            if (compareWord(request_queue->buffer[i].name, item.name)) {
                printf("Barang ");
                printWord(item.name);
                printf(" sudah ada di antrian!\n");
                return;
            }
        }
    }


    if (queueisFull(*request_queue)) {
        printf("Antrian permintaan penuh. Tidak dapat menambahkan barang.\n");
    } else {
        enqueue(request_queue, item);
        printf("Permintaan untuk ");
        printWord(item.name);
        printf(" telah ditambahkan ke antrian.\n");
    }
}

// Fungsi untuk mengambil antrean barang
void store_supply(ArrayDin *store, Queue *request_queue, Word command, int price) {
    if (queueisEmpty(*request_queue)) {
        printf("Maaf, antrean kosong.\n");
        return;
    }

    BarangElType item = HEAD(*request_queue);  

    if (compareWord(command, str2Word("Terima"))) {

        dequeue(request_queue, &item);  
        item.price = price;
        InsertLast(store, item); 
        printWord(item.name);
        printf(" dengan harga %d telah ditambahkan ke toko.\n", price);
        
    } else if (compareWord(command, str2Word("Tunda"))) {
        printWord(item.name);
        printf(" dikembalikan ke antrian.\n");

        BarangElType tunda;
        dequeue(request_queue,&tunda);
        enqueue(request_queue,tunda);
        
    } else if (compareWord(command, str2Word("Tolak"))) {
        dequeue(request_queue, &item);
        printWord(item.name);
        printf(" dihapuskan dari antrian.\n");}

}

// Fungsi untuk menghapus item dari toko
void store_remove(ArrayDin *store, Word item_name) {
    boolean found = false;
    for (int i = 0; i < store->Neff; i++) {
        if (compareWord(store->A[i].name, item_name)) {
            found = true;
            DeleteAt(store, i);
            printWord(item_name);
            printf(" telah berhasil dihapus.\n");
            return;
        }
    }
    if (!found) {
        printf("Toko tidak menjual ");
        printWord(item_name);
        printf(".\n");
    }
}

CurrentBarang cariBarang (ArrayDin store, Word item_name) {
    for (int i = 0; i < store.Neff; i++) {
        if (compareWord(store.A[i].name, item_name)) {
            return store.A[i];
        }
    }
    printf("Barang tidak ditemukan\n");
    return;
}