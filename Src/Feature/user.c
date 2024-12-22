#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "../Feature/user.h"
#include "../ADT/mesinkata/mesinkata.h"


// #include "user.h"
// #include <string.h>
// #include <stdio.h>

User CreateUser(char *nama, char *password, int uang, Stack riwayat_pembelian, Map cart, Linkedlist wishlist) {
    User user;
    cpStr(user.nama, nama, NMax - 1);
    cpStr(user.password, password, NMax - 1);
    user.uang = uang;
    user.riwayat_pembelian = riwayat_pembelian;
    user.cart = cart;
    user.wishlist = wishlist;
    return user;
}

void PrintUser(User user) {
    printf("Nama: %s\n", user.nama);
    printf("Uang: %d\n", user.uang);
}

boolean compareString(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}



void cpStr(char* dest, const char* src, int maxLen) {
    int i = 0;
    while (i < maxLen - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}