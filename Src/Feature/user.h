#ifndef USER_H
#define USER_H

#define NMax 50

#include "../ADT/boolean.h"
#include "../ADT/stack/stack.h"
#include "../ADT/map/map.h"
#include "../linkedlist/linkedlist.h"

typedef struct {
    char nama[NMax];    // Nama pengguna
    char password[NMax]; // Password pengguna
    int uang;
    Map cart;           
    Stack riwayat_pembelian;
    Linkedlist wishlist;
} User;

// Fungsi-fungsi terkait User
User CreateUser(char *nama, char *password, int uang, Stack riwayat_pembelian, Map cart, Linkedlist wishlist);
void PrintUser(User user);
boolean compareString(char *a, char *b);
void cpStr(char* dest, const char* src, int maxLen);



#endif