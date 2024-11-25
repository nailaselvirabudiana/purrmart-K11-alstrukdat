#include <stdio.h>
// #include <string.h>
#include "list.h"

// Konstruktor
List MakeList() {
    List L;
    User emptyUser = {"", "", -9999}; // Mark sebagai User kosong
    for (int i = 0; i < MaxEl; i++) {
        L.A[i] = emptyUser; // Mengisi array dengan Mark
    }
    return L;
}

boolean IsEmpty(List L) {
    return (L.A[0].uang == -9999); // Cek apakah elemen pertama adalah Mark
}

int Length(List L) {
    int i = 0;
    while (L.A[i].uang != -9999 && i < MaxEl) { // Mark sebagai penanda
        i++;
    }
    return i;
}

UserEltype Get(List L, IdxType i) {
    return L.A[i];
}

void Set(List *L, IdxType i, UserEltype v) {
    (*L).A[i] = v;
}

IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
    int i = FirstIdx(L);
    while ((i < MaxEl) && (L.A[i + 1].uang != -9999)) {
        i++;
    }
    return i;
}

boolean IsIdxValid(List L, IdxType i) {
    return (0 <= i) && (i < MaxEl);
}

boolean IsIdxEff(List L, IdxType i) {
    return (FirstIdx(L) <= i) && (i <= LastIdx(L));
}


boolean Search(List L, UserEltype X) {
    int i = FirstIdx(L);
    boolean found = false;
    while (i <= LastIdx(L) && !found) {
        if (compareString(L.A[i].nama, X.nama) == true &&
            compareString(L.A[i].password, X.password) == true &&
            L.A[i].uang == X.uang) {
            found = true;
        }
        i++;
    }
    return found;
}

void InsertFirst(List *L, UserEltype X) {
    int i = LastIdx(*L);
    while (i >= 0) {
        Set(L, i + 1, Get(*L, i));
        i--;
    }
    Set(L, 0, X);
}

void InsertAt(List *L, UserEltype X, IdxType i) {
    int j = LastIdx(*L);
    while (j >= i) {
        Set(L, j + 1, Get(*L, j));
        j--;
    }
    Set(L, i, X);
}

void InsertLast(List *L, UserEltype X) {
    if (IsEmpty(*L)) {
        InsertFirst(L, X);
    } else {
        Set(L, LastIdx(*L) + 1, X);
    }
}

void DeleteFirst(List *L) {
    int i = 0;
	User emptyUser = {"", "", -9999};
    while (i < LastIdx(*L)) {
        (*L).A[i] = (*L).A[i + 1];
        i++;
    }
    (*L).A[i] = emptyUser;
}

void DeleteAt(List *L, IdxType i) {
	User emptyUser = {"", "", -9999}; // Mark sebagai User kosong
    while (i < LastIdx(*L)) {
        (*L).A[i] = (*L).A[i + 1];
        i++;
    }
    (*L).A[i] = emptyUser;
}

void DeleteLast(List *L) {
    User emptyUser = {"", "", -9999}; // Mark sebagai User kosong
	(*L).A[LastIdx(*L)] = emptyUser;
}

List Concat(List L1, List L2) {
    List L3 = MakeList();
    int idx = 0;
    for (int i = 0; i <= LastIdx(L1); i++) {
        Set(&L3, idx++, L1.A[i]);
    }
    for (int i = 0; i <= LastIdx(L2); i++) {
        Set(&L3, idx++, L2.A[i]);
    }
    return L3;
}

boolean IsEqual(List L1, List L2) {
    if (Length(L1) != Length(L2)) {
        return false;
    }
    for (int i = 0; i < Length(L1); i++) {
        if (compareString(L1.A[i].nama, L2.A[i].nama) != true ||
            compareString(L1.A[i].password, L2.A[i].password) != true ||
            L1.A[i].uang != L2.A[i].uang) {
            return false;
        }
    }
    return true;
}


#include <stdio.h>

#include <stdio.h>
#include "list.h"

int main() {
    // Membuat dua List kosong
    List L1 = MakeList();
    List L2 = MakeList();

    // Membuat beberapa User
    User u1 = {"user1", "pass1", 1000};
    User u2 = {"user2", "pass2", 2000};
    User u3 = {"user3", "pass3", 3000};
    User u4 = {"user4", "pass4", 4000};

    // Menambahkan User ke List L1
    InsertLast(&L1, u1);
    InsertLast(&L1, u2);

    // Menambahkan User ke List L2
    InsertLast(&L2, u3);
    InsertLast(&L2, u4);

    // Menampilkan isi List L1
    printf("Isi List L1:\n");
    for (int i = 0; i < Length(L1); i++) {
        User u = Get(L1, i);
        printf("Nama: %s, Password: %s, Uang: %d\n", u.nama, u.password, u.uang);
    }

    // Menampilkan isi List L2
    printf("\nIsi List L2:\n");
    for (int i = 0; i < Length(L2); i++) {
        User u = Get(L2, i);
        printf("Nama: %s, Password: %s, Uang: %d\n", u.nama, u.password, u.uang);
    }

    // Menggabungkan List L1 dan L2
    List L3 = Concat(L1, L2);

    // Menampilkan isi List L3
    printf("\nIsi List L3 (gabungan L1 dan L2):\n");
    for (int i = 0; i < Length(L3); i++) {
        User u = Get(L3, i);
        printf("Nama: %s, Password: %s, Uang: %d\n", u.nama, u.password, u.uang);
    }

    // Mencari User dalam List L3
    User searchUser = {"user2", "pass2", 2000};
    if (Search(L3, searchUser)) {
        printf("\nUser ditemukan dalam List L3: %s\n", searchUser.nama);
    } else {
        printf("\nUser tidak ditemukan dalam List L3: %s\n", searchUser.nama);
    }

    // Menghapus elemen pertama di List L3
    DeleteFirst(&L3);

    // Menampilkan isi List L3 setelah penghapusan
    printf("\nIsi List L3 setelah penghapusan elemen pertama:\n");
    for (int i = 0; i < Length(L3); i++) {
        User u = Get(L3, i);
        printf("Nama: %s, Password: %s, Uang: %d\n", u.nama, u.password, u.uang);
    }

    // Menambahkan User baru ke List L3 di indeks tertentu
    User newUser = {"newUser", "newPass", 5000};
    InsertAt(&L3, newUser, 1);

    // Menampilkan isi List L3 setelah penambahan
    printf("\nIsi List L3 setelah penambahan User baru di indeks 1:\n");
    for (int i = 0; i < Length(L3); i++) {
        User u = Get(L3, i);
        printf("Nama: %s, Password: %s, Uang: %d\n", u.nama, u.password, u.uang);
    }

    // Menghapus elemen di indeks tertentu di List L3
    DeleteAt(&L3, 1);

    // Menampilkan isi List L3 setelah penghapusan di indeks tertentu
    printf("\nIsi List L3 setelah penghapusan di indeks 1:\n");
    for (int i = 0; i < Length(L3); i++) {
        User u = Get(L3, i);
        printf("Nama: %s, Password: %s, Uang: %d\n", u.nama, u.password, u.uang);
    }

    return 0;
}
