#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "user.h"
#include "../ADT/mesinkata/mesinkata.h"


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

void MakeList(UserList* list){
    list->count = 0;
    list->ActiveUserIndex = -1;
}

void cpStr(char* dest, const char* src, int maxLen) {
    int i = 0;
    while (i < maxLen - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

void addUser(UserList* list, const char* nama, const char* password) {
    if (list->count < NMax) {
        User* newUser = &list->users[list->count];

        cpStr(newUser->nama, nama, NMax);
        cpStr(newUser->password, password, NMax);
        newUser->uang = 0;
        list->count++;
        list->ActiveUserIndex = list->count - 1;
    } else {
        printf("User list is full. Cannot add more users.\n");
    }
}

void printUsers(const UserList* list)
{
    for (int i = 0; i < list->count; i++)
    {
        printf("User %d:\n", i + 1);
        printf("Nama: %s\n", list->users[i].nama);
        printf("Password: %s\n", list->users[i].password);
        printf("Uang: %d\n\n", list->users[i].uang);
    }
}

void addMoney(UserList* list, int amount) {
    // Check if there is an active user
    if (list->ActiveUserIndex == -1) {
        printf("No active user selected.\n");
        return;
    }
    
    // Get the active user
    User* activeUser = &list->users[list->ActiveUserIndex];
    
    // Add the specified amount to the active user's uang
    activeUser->uang += amount;
    
    printf("Added %d rupiah to the active user's account.\n", amount);
}

void setActiveUser(UserList* list, int index) {
    if (index >= 0 && index < list->count) {
        list->ActiveUserIndex = index;
        printf("Active user set to: %s\n", list->users[index].nama);
    } else {
        printf("Invalid user index.\n");
    }
}

// Function to get the active user
User* getActiveUser(UserList* list) {
    if (list->ActiveUserIndex == -1) {
        return NULL;
    }
    return &list->users[list->ActiveUserIndex];
}

int main() {
    UserList userList = {{}, 0, -1}; // Inisialisasi UserList kosong dengan count=0 dan ActiveUserIndex=-1

    // Tambahkan beberapa pengguna ke dalam UserList
    addUser(&userList, "Alice", "password123");
    addUser(&userList, "Bob", "securepass");
    addUser(&userList, "Charlie", "qwerty");

    // Cetak semua pengguna
    printf("=== Daftar Pengguna ===\n");
    printUsers(&userList);

    // Set pengguna aktif ke pengguna kedua (Bob)
    printf("\n=== Set Active User ===\n");
    setActiveUser(&userList, 1);

    // Tambah uang ke pengguna aktif
    printf("\n=== Tambah Uang ===\n");
    addMoney(&userList, 500);

    // Ambil data pengguna aktif dan cetak informasi mereka
    printf("\n=== Informasi Pengguna Aktif ===\n");
    User* activeUser = getActiveUser(&userList);
    if (activeUser != NULL) {
        printf("Pengguna Aktif:\n");
        printf("Nama: %s\n", activeUser->nama);
        printf("Password: %s\n", activeUser->password);
        printf("Uang: %d\n", activeUser->uang);
    } else {
        printf("Tidak ada pengguna aktif.\n");
    }

    // Set pengguna aktif ke pengguna pertama (Alice) dan tambahkan uang
    printf("\n=== Ganti Pengguna Aktif ===\n");
    setActiveUser(&userList, 0);
    addMoney(&userList, 1000);

    // Cetak kembali semua pengguna untuk memverifikasi perubahan
    printf("\n=== Daftar Pengguna Setelah Perubahan ===\n");
    printUsers(&userList);

    return 0;
}
