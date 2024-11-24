#include <stdio.h>
#include <stdlib.h>
#include "store.h"

int main() {

    ArrayDin store = MakeArrayDin(10); 
    Queue request_queue;
    CreateQueue(&request_queue); 

    // Menambahkan beberapa barang ke toko untuk pengujian
    BarangElType item;
    item.name = str2Word("Platypus Laser");
    item.price = 500;
    InsertLast(&store, item);

    item.name = str2Word("Shrink Ray");
    item.price = 400;
    InsertLast(&store, item);

    item.name = str2Word("Net Shooter");
    item.price = 300;
    InsertLast(&store, item);

    item.name = str2Word("Camouflage Cloak");
    item.price = 450;
    InsertLast(&store, item);

    item.name = str2Word("Sleep Dart Gun");
    item.price = 250;
    InsertLast(&store, item);

    item.name = str2Word("Bubble Blaster");
    item.price = 350;
    InsertLast(&store, item);

    // Test case STORE LIST (ada barang)
    printf(">> STORE LIST (kondisi ada barang)\n");
    store_list(store);
    printf("\n");

    // Test case STORE LIST (tidak ada barang)
    ArrayDin empty_store = MakeArrayDin(10);
    printf(">> STORE LIST (kondisi gaada barang)\n");
    store_list(empty_store);
    printf("\n");

    // Test case STORE REQUEST
    printf(">> STORE REQUEST\n");
    printf("Nama barang yang diminta: AK47\n");
    item.name = str2Word("AK47");
    store_request(&request_queue, store, item);

    printf("Nama barang yang diminta: Adaditoko\n");
    item.name = str2Word("Adaditoko");
    store_request(&request_queue, store, item);

    printf("Nama barang yang diminta: Adadiantrian\n");
    item.name = str2Word("Adadiantrian");
    enqueue(&request_queue, item); 
    store_request(&request_queue, store, item);
    printf("\n");

    displayQueue(request_queue);
    printf("\n");

    // Test case STORE SUPPLY
    printf(">> STORE SUPPLY\n");
    Word command = str2Word("Terima");

    store_supply(&store, &request_queue, command, 100);
    printf("\n");
    displayQueue(request_queue);
    printf("\n");

    command = str2Word("Tunda");

    printf("\n");
    store_supply(&store, &request_queue, command, 0);
    printf("\n");

    displayQueue(request_queue);
    printf("\n");

    command = str2Word("Tolak");
    printf("\n");
    store_supply(&store, &request_queue, command, 0);
    printf("\n");
    displayQueue(request_queue);
    printf("\n");


    command = str2Word("Purry");
    store_supply(&store, &request_queue, command, 350);
    printf("\n");
    displayQueue(request_queue);
    printf("\n");


    printf(">> STORE LIST \n");
    store_list(store);
    printf("\n");


    // Test case STORE REMOVE
    printf(">> STORE REMOVE\n");
    Word item_name = str2Word("Platypus Laser");
    printf("Nama barang yang akan dihapus: ");
    printWord(item_name);
    printf("\n");
    store_remove(&store, item_name);

    item_name = str2Word("Inator Neutralizer");
    printf("Nama barang yang akan dihapus: ");
    printWord(item_name);
    printf("\n");
    store_remove(&store, item_name);

    printf(">> STORE LIST\n");
    store_list(store);
    printf("\n");



    return 0;
}
