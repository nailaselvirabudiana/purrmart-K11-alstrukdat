#ifndef _user_H_
#define _user_H_

#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"


#define NMax 50

typedef struct
{
    char nama[NMax]; 
    char password[NMax];
    int uang;
} User;

typedef struct
{
    User users[NMax];
    int count;
    int ActiveUserIndex;
}UserList;

boolean compareString(char* a, char* b);
// void MakeList(UserList *list);
void addUser(UserList* list, const char* nama, const char* password);

void cpStr(char* dest, const char* src, int maxLen);

void printUsers(const UserList* list);

void addMoney(UserList* list, int amount);

void setActiveUser(UserList* list, int index); // Function to set the active user

User* getActiveUser(UserList* list); // Function to get the active user

#endif