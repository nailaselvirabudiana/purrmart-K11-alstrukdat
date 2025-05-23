#include <stdio.h>
#include "auth.h"

// List listuser;
// boolean isLoggedIn = false;
User LoggedInUser;

boolean UsernameTaken(List *L, char *username) {
    for (int i = 0; i < LengthUser(*L); i++) {
        User user = GetUser(*L, i);
        if (compareString(user.nama, username)) {
            return true; // Username sudah ada
        }
    }
    return false; // Username tersedia
}


void registerUser(List *listuser) {
    printf("Username: ");
    STARTINPUT();
    
    Word username = currentWord;

    // Mengecek apakah username sudah terdaftar
    if (UsernameTaken(listuser, Word2str(username))) {
        printf("Akun dengan username '%s' sudah terdaftar. Silakan lakukan REGISTER ulang.\n", Word2str(username));
        return;
    }

    if (username.Length == 0) {
        printf("Username tidak valid");
        return;
    }

    printf("Password: ");
    STARTINPUT();
    
    Word password = currentWord;

    if (password.Length == 0) {
        printf("Password tidak valid");
        return;
    }
    
    User newUser;
    cpStr (newUser.nama, Word2str(username),NMax-1);
    cpStr (newUser.password, Word2str(password),NMax-1);
    newUser.uang = 0; 
    Map cart;
    CreateEmptyMap(&cart);
    newUser.cart = cart;
    Stack riwayat_pembelian;
    CreateEmptyStack(&riwayat_pembelian);
    newUser.riwayat_pembelian = riwayat_pembelian;
    Linkedlist wishlist;
    CreateEmpty(&wishlist);
    newUser.wishlist = wishlist;
    InsertLastUser(listuser, newUser); 
    printf("Akun dengan username '%s' telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", Word2str(username));
}


int login(List *listuser) {
    if (isLoggedIn) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", LoggedInUser.nama);
        return 0;
    }
    printf("Username: ");
    STARTINPUT();
    Word username = currentWord;

    printf("Password: ");
    STARTINPUT();
    Word password = currentWord;

    for (int i = 0; i < LengthUser(*listuser); i++) {
        User user = GetUser(*listuser, i);
        if (compareString(user.nama, Word2str(username)) && compareString(user.password, Word2str(password))) {
            isLoggedIn = true;
            LoggedInUser = user;
            printf("Anda telah login ke PURRMART sebagai %s.\n", Word2str(username));
            return 1;
        }
    }
    printf("Username atau password salah.\n");
    return 0;
}


void logout() {
    if (!isLoggedIn) {
        printf("Anda belum login.\n");
    } else {
        printf("Telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n");
        isLoggedIn = false;
    }
}