#include "auth.h"
#include "user.h"
#include <stdio.h>

//PROFILE adalah command yang digunakan untuk melihat data diri pengguna. PROFILE hanya dapat dipanggil saat status pengguna telah login
void profile(List *listuser){
    if (isLoggedIn){
        printf("Username: %s\n", listuser->A->nama);
        printf("Uang: %d\n", listuser->A->uang);
        printf("Riwayat: \n");
        PrintStackWithoutTag(listuser->A->riwayat_pembelian);
        printf("Cart: \n");
        PrintMap(listuser->A->cart);
        printf("Wishlist: \n");
        PrintInfo(listuser->A->wishlist);
    } else {
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
    }
}