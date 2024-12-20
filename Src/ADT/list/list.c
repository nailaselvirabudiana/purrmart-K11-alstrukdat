#include "list.h"
#include <stdio.h>

List MakeListUser() {
    List L ;
    L.Neff = 0;
    return L;
}

int LengthUser(List L) {
    return L.Neff;
}

boolean IsEmptyUser(List L) {
    return L.Neff == 0;
}

User GetUser(List L, IdxType i) {
    return L.A[i];
}

void SetUser(List *L, IdxType i, User v) {
    L->A[i] = v;
}

void InsertLastUser(List *L, User X) {
    if (L->Neff < MaxEl) {
        L->A[L->Neff] = X;
        L->Neff++;
    } else {
        printf("List is full!\n");
    }
}

boolean SearchUser(List L, User X) {
    for (int i = 0; i < L.Neff; i++) {
        if (compareString(L.A[i].nama, X.nama)) {
            return true;
        }
    }
    return false;
}

void DisplayListUser(List L) {
    if (IsEmptyUser(L)) {
        printf("List kosong.\n");
    } else {
        printf("Daftar Pengguna:\n");
        for (int i = 0; i < L.Neff; i++) {
            User user = L.A[i];
            printf("%d. Username: %s, Password: %s, Uang: %d\n", i + 1, user.nama, user.password, user.uang);
        }
    }
}

