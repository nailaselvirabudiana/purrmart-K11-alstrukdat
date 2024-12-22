#include "auth.h"
#include "user.h"
#include <stdio.h>

//PROFILE adalah command yang digunakan untuk melihat data diri pengguna. PROFILE hanya dapat dipanggil saat status pengguna telah login
void profile(User LoggedInUser){
    if (isLoggedIn){
        printf("Username: %s\n", LoggedInUser.nama);
        printf("Uang: %d\n", LoggedInUser.uang);
        printf("Riwayat: \n");
        PrintStackWithoutTag(LoggedInUser.riwayat_pembelian);
        printf("Cart: \n");
        PrintMap(LoggedInUser.cart);
        printf("Wishlist: \n");
        PrintInfo(LoggedInUser.wishlist);
    } else {
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
    }
}