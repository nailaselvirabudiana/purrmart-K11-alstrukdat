#ifndef USER_H
#define USER_H

#define NMax 50

#include "boolean.h"
#include "stack.h"
#include "map.h"
#include "linkedlist.h"

typedef struct {
    char nama[NMax];    // Nama pengguna
    char password[NMax]; // Password pengguna
    int uang;
    Map cart;           
    Stack riwayat_pembelian;
    List wishlist;
} User;

// Fungsi-fungsi terkait User
User CreateUser(char *nama, char *password, int uang, Stack riwayat_pembelian, Map cart, List wishlist);
void PrintUser(User user);
boolean compareString(char *a, char *b);
void cpStr(char* dest, const char* src, int maxLen);



#endif