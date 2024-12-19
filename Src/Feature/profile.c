#include "auth.h"
#include "user.h"
#include <stdio.h>

//PROFILE adalah command yang digunakan untuk melihat data diri pengguna. PROFILE hanya dapat dipanggil saat status pengguna telah login
void profile(List *listuser){
    if (isLoggedIn){
        printf("Username: %s\n", LoggedInUser.nama);
        printf("Uang: %d\n", LoggedInUser.uang);
        printf("Riwayat Pembelian: %s\n", LoggedInUser.riwayat_pembelian);
        printf("Cart: %s\n", LoggedInUser.cart);
        printf("Wishlist: %s\n", LoggedInUser.wishlist);
    } else {
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
    }
}