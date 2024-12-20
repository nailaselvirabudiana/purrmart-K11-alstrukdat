#include <stdio.h>
#include "cart.h"
#include "../ADT/setmap/map.h"
#include "../ADT/barang/barang.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/store/store.h"
#include "../ADT/stack/stack.h"
#include "user.h"

void cart_pay(Map *cart, int *uang_user, Stack *riwayat_pembelian) {
    
    if (cart->Count == 0) {
        printf("Keranjang belanja kosong! Tidak ada barang yang dapat dibeli.\n");
        return;
    }
    
    int total = 0;
    printf("Kamu akan membeli barang-barang berikut:\n");
    printCart(*cart);

    for (int i = 0; i < cart->Count; i++) {
        total += cart->Elements[i].Key.price * cart->Elements[i].Value;
    }

    printf("\nTotal biaya yang harus dikeluarkan adalah %d. Apakah jadi dibeli? (Ya/Tidak): ", total);
    STARTWORD();
    Word input;
    input = currentWord;

    if (compareWord(input, str2Word("Ya"))) {
        if (*uang_user >= total) {

            *uang_user -= total;
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
          

            for (int i = 0; i < cart->Count; i++) {
                CartItem keranjang;
                printf("test");
                keranjang.item = cart->Elements[i].Key;
                keranjang.quantity = cart->Elements[i].Value;
                keranjang.total_harga = cart->Elements[i].Key.price * cart->Elements[i].Value;
                Push(riwayat_pembelian, keranjang);
            }

 
            CartItem separator = { .item.name = str2Word("END_TRANSACTION"), .quantity = cart->Count, .total_harga = total };
            Push(riwayat_pembelian, separator);

       
            cart->Count = 0;

        } else {
       
            printf("Transaksi gagal! Saldo kamu hanya %d, sedangkan total harga adalah %d.\n", *uang_user, total);
        }
    } else {
    
        printf("Pembelian dibatalkan.\n");
    }
}

void cart_add(Map *cart, CurrentBarang *barang, int jumlah){
    if (jumlah <= 0) {
        printf("Jumlah Tidak Valid\n");
        return;
    }

    if (IsMemberMap(*cart, *barang)) {
        ubahValueMap(cart, *barang, ValueMap(*cart, *barang) + jumlah);
        printf("%s berhasil ditambahkan kembali sebanyak %d\n", Word2str(barang->name), jumlah);
    } else {
        InsertMap(cart, *barang, jumlah);
        printf("%s berhasil ditambahkan sebanyak %d\n", Word2str(barang->name) , jumlah);
}

}

void cart_remove(Map *cart, CurrentBarang *barang, int jumlah){
    if (jumlah <= 0) {
        printf("Jumlah Tidak Valid\n");
        return;
    }

    if (IsMemberMap(*cart, *barang)){
        if (ValueMap(*cart, *barang) > jumlah) {
            ubahValueMap(cart, *barang, ValueMap(*cart, *barang) - jumlah);
            printf("%s berhasil dihapus sebanyak %d\n",Word2str(barang->name), jumlah);
        } else {
            printf("%s berhasil dihapus sebanyak %d\n", Word2str(barang->name) ,ValueMap(*cart, *barang));
            DeleteMap(cart, *barang);
        }
    } else {
        printf("Barang tidak ada di keranjang\n");
    }
}

void printCart(Map cart) {
    if (IsEmptyMap(cart)) {
        printf("Keranjang Kosong\n");
    } else {
        printf("Isi Keranjang:\n");
        printf("%-10s | %-20s | %-10s\n", "Jumlah", "Nama Barang", "Harga");
        printf("--------------------------------------------------------\n");
        for (int i = 0; i < cart.Count; i++) {
            printf("%-10d | %-20s | %-10d\n",
                   cart.Elements[i].Value,
                   Word2str(cart.Elements[i].Key.name),
                   cart.Elements[i].Key.price * cart.Elements[i].Value);
        }
    }
}