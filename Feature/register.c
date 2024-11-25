#include <stdio.h>
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "register.h"
#include "../ADT/list/list.h"
#include "user.h"

// src/ADT/mesinkata/mesinkata.h
extern List listuser;

boolean UsernameTaken( List *L,  char *username) {
    for (int i = 0; i < Length(*L); i++) {
        if (compareString(Get(*L, i).nama, username)) {
            return true;
        }
    }
    return false;
}

// Fungsi register user baru
void registerUser() {
    printf("Username: ");
    STARTINPUT();
    
    Word username = currentWord;

    // Mengecek apakah username sudah terdaftar
    if (UsernameTaken(&listuser, Word2str(username))) {
        printf("Akun dengan username '%s' sudah terdaftar. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }

    printf("Password: ");
    STARTINPUT();
    
    Word password = currentWord;
    

    // Membuat user baru dan menambahkannya ke daftar
    User newUser;
    cpStr (newUser.nama, Word2str(username),NMax);
    cpStr (newUser.password, Word2str(password),NMax);
    newUser.uang = 0; // Default uang adalah 0

    InsertLast(&listuser, newUser); // Menambahkan user baru ke akhir list
    printf("Akun dengan username '%s' telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}

#include <stdio.h>
int main() {
    int choice;
    do {
        printf("1. Register User\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
        }
    } while (choice != 2);

    return 0;
}
