#include <stdio.h>
#include "login.h"
#include "../ADT/userauth/userauth.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/array/array.h"

extern TabKata arrusers;
extern TabKata arrpassword;

void login() {
    if (isLoggedIn) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", loggedInUser.TabWord);
        return;
    }
    printf("Username: ");
    STARTINPUT();
    Word username = currentWord;

    printf("Password: ");
    STARTINPUT();
    Word password = currentWord;

    for (int i = 0; i < arrusers.Neff; i++) {
        if (StringCompare(arrusers.TI[i], username) && StringCompare(arrpassword.TI[i], password)) {
            isLoggedIn = true;
            loggedInUser = username;
            printf("Anda telah login ke PURRMART sebagai %s.\n", Word2str(username));
            return;
        }
    }
    printf("Username atau password salah.\n");
}