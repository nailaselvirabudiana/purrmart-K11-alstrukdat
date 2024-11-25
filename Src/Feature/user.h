#ifndef USER_H
#define USER_H

#define NMax 50

#include "../ADT/boolean.h"

typedef struct {
    char nama[NMax];    // Nama pengguna
    char password[NMax]; // Password pengguna
    int uang;           // Uang pengguna
} User;

// Fungsi-fungsi terkait User
User CreateUser(char *nama, char *password, int uang);
void PrintUser(User user);
boolean compareString(char *a, char *b);
void cpStr(char* dest, const char* src, int maxLen);



#endif