#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilMapai NilMap */
{
    M->Count = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilMapai NilMap */
{
    return M.Count == NilMap;
}

boolean IsFullMap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilMapai MaxEl */
{
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k) {
    if (IsEmptyMap(M)) {
        return Undefined;
    }

    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (compareWord(M.Elements[idx].Key.name, k.name)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    if (found) {
        return M.Elements[idx].Value;
    }
    else {
        return Undefined;
    }
}

void InsertMap(Map *cart, CurrentBarang key, int value) {
    if (cart->Count < MaxEl) {  // Ensure capacity check
        cart->Elements[cart->Count].Key = key;  // Ensure safe assignment
        cart->Elements[cart->Count].Value = value;
        cart->Count++;
    } else {
        printf("Map is full!\n");
    }
}

void DeleteMap(Map *M, keytype k) {
    if (IsEmptyMap(*M)) {
        return;
    }

    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M->Count) {
        if (compareWord(M->Elements[idx].Key.name, k.name)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    if (found) {
        for (int i = idx; i < M->Count - 1; i++) {
            M->Elements[i] = M->Elements[i + 1];
        }
        M->Count--;
    }
}

boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (compareWord(M.Elements[idx].Key.name,k.name)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return found;
}


/* Fungsi untuk mencetak isi Map */
void PrintMap(Map M) {
    if (IsEmptyMap(M)) {
        printf("Cart is empty.\n");
        return;
    }
    for (address i = 0; i < M.Count; i++) {
        char* key = Word2str(M.Elements[i].Key.name);
        printf("%s: %d\n", key, M.Elements[i].Value);
    }
}

void ubahValueMap(Map *M, keytype k, valuetype v) {
    if (IsEmptyMap(*M)) {
        return;
    }

    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M->Count) {
        if (compareWord(M->Elements[idx].Key.name, k.name)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    if (found) {
        M->Elements[idx].Value = v;
    }
}