#include <stdio.h>
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "register.h"
#include "../ADT/array/array.h"

extern TabKata arrusers;
extern TabKata arrpassword;

void registerUser() {
    printf(">> REGISTER\n");

    printf("Username: ");
    STARTINPUT();
    Word username = currentWord;
    boolean found;

    if (isMember(arrusers, username)) {
        printf("Akun dengan username %s sudah terdaftar. Silakan lakukan REGISTER ulang.\n", Word2str(username));
        return;
    }

    printf("Password: ");
    STARTINPUT();
    Word password = currentWord;

    AddElmt(&arrusers, username);
    AddElmt(&arrpassword, password);

    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", Word2str(username));
}