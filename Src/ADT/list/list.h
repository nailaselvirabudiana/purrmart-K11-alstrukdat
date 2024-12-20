#ifndef LIST_H
#define LIST_H

#include "../../Feature/user.h" // Include tipe User
#include "../boolean.h"


#define MaxElUser 10 // Maksimal elemen dalam list
// #define Mark 

typedef int IdxType;
typedef struct {
    User A[MaxElUser];  // Array penyimpan elemen bertipe User
    int Neff;       // Banyaknya elemen efektif
} List;

// Fungsi dan prosedur terkait List
List MakeListUser();
int LengthUser(List L);
boolean IsEmptyUser(List L);
User GetUser(List L, IdxType i);
void SetUser(List *L, IdxType i, User v);
void InsertLastUser(List *L, User X);
boolean SearchUser(List L, User X);
void DisplayListUser (List L);

#endif
