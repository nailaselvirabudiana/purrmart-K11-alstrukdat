#ifndef STORE_H
#define STORE_H

#include "../list_dinamis/list_dinamis.h"
#include "../queue/queue.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_BARANG 100 


void handle_store_request(Queue *request_queue, ArrayDin store);

void handle_store_supply(ArrayDin *store, Queue *request_queue);

void handle_store_remove(ArrayDin *store);

// Fungsi untuk menampilkan item yang ada di dalam toko
void store_list(ArrayDin store);

// Fungsi untuk menambahkan permintaan item baru ke antrian
void store_request(Queue *request_queue, ArrayDin store, BarangElType item);

// Fungsi untuk menambahkan item dari antrian permintaan ke toko
void store_supply(ArrayDin *store, Queue *request_queue, Word command, int price);

// Fungsi untuk menghapus item dari toko
void store_remove(ArrayDin *store, Word item_name);

CurrentBarang cariBarang(ArrayDin store, Word item_name);
#endif