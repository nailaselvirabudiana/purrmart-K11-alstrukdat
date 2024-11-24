#ifndef SAVE_H
#define SAVE_H

#include "store.h"
#include "queue.h"
#include "load.h"
#include "array.h"

// Fungsi untuk menulis data ke dalam file
void writeToFile(FILE *file, ArrayDin *store, TabKata *arrusers, TabKata *arrpassword);

// Menyimpan file
void saveFile(char *filename, ArrayDin *store, TabKata *arrusers, TabKata *arrpassword);

#endif
