#include "auth.h"
#include "user.h"
#include <stdio.h>

//PROFILE adalah command yang digunakan untuk melihat data diri pengguna. PROFILE hanya dapat dipanggil saat status pengguna telah login
void profile(User LoggedInUser, List Listuser){
    if (isLoggedIn){
        
        for (int x = 0; x < LengthUser(Listuser); x++){
                if (compareString(Listuser.A[x].nama, LoggedInUser.nama)){
                    Listuser.A[x].cart = LoggedInUser.cart;
                    Listuser.A[x].riwayat_pembelian = LoggedInUser.riwayat_pembelian;
                    Listuser.A[x].wishlist = LoggedInUser.wishlist;
                    Listuser.A[x].uang = LoggedInUser.uang;
                }
            }
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