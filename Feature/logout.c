#include "logout.h"
#include "../ADT/userauth/userauth.h"
#include <stdio.h>

void logout() {
    if (!isLoggedIn) {
        printf("Anda belum login.\n");
    } else {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", loggedInUser.TabWord);
        isLoggedIn = false;
    }
}