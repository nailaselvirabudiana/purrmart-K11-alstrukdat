#include <stdio.h>
#include "list.h"

int main() {

    List userList = MakeListUser();

    User user1 = {"Alice", "password123", 1000};
    User user2 = {"Bob", "qwerty", 500};
    User user3 = {"Charlie", "123456", 1500};


    printf("List awal:\n");
    DisplayListUser(userList);

    printf("\nMenambahkan pengguna:\n");
    InsertLastUser(&userList, user1);
    InsertLastUser(&userList, user2);
    InsertLastUser(&userList, user3);


    printf("\nList setelah penambahan:\n");
    DisplayListUser(userList);


    printf("\nMengakses pengguna kedua:\n");
    User retrievedUser = GetUser(userList, 1); 
    printf("Username: %s, Password: %s, Uang: %d\n", retrievedUser.nama, retrievedUser.password, retrievedUser.uang);


    printf("\nMencari pengguna dengan nama 'Bob':\n");
    if (SearchUser(userList, user2)) {
        printf("Pengguna ditemukan!\n");
    } else {
        printf("Pengguna tidak ditemukan.\n");
    }


    printf("\nPanjang list: %d\n", LengthUser(userList));


    printf("\nApakah list kosong? %s\n", IsEmptyUser(userList) ? "Ya" : "Tidak");

    return 0;
}