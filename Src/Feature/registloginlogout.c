#include <stdio.h>
#include "user.h"
#include "auth.h"
#include "../ADT/list/list.h"

int main() {
    List users = MakeListUser(); // Inisialisasi list user

    int choice;
    boolean exitProgram = false;

    while (!exitProgram) {
        printf("\n=== PURRMART Menu ===\n");
        printf("1. Registrasi\n");
        printf("2. Login\n");
        printf("3. Logout\n");
        printf("4. Tampilkan Daftar User\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        getchar(); // Menghilangkan newline setelah input

        switch (choice) {
            case 1: // Registrasi user baru
                printf("\n=== Registrasi User ===\n");
                registerUser(&users);
                break;

            case 2: // Login
                if (isLoggedIn) {
                    printf("\nAnda sudah login sebagai %s.\n", LoggedInUser.nama);
                } else {
                    printf("\n=== Login ===\n");
                    login(&users);
                }
                break;

            case 3: // Logout
                printf("\n=== Logout ===\n");
                logout();
                break;

            case 4: // Tampilkan daftar user
                printf("\n=== Daftar User ===\n");
                DisplayListUser(users);
                break;

            case 5: // Keluar program
                printf("\nKeluar dari program. Sampai jumpa!\n");
                exitProgram = true;
                break;

            default:
                printf("\nOpsi tidak valid. Silakan pilih lagi.\n");
                break;
        }
    }

    return 0;
}