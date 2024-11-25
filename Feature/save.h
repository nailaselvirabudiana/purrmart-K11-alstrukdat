#ifndef SAVE_H
#define SAVE_H

#include "../ADT/store/store.h"
#include "../ADT/queue/queue.h"
#include "load.h"
#include "../ADT/list/list.h"
#include "user.h"

// Fungsi untuk menulis data ke dalam file
void writeToFile(FILE *file, ArrayDin *store, List *user);

// Menyimpan file
void saveFile(const char *filename, ArrayDin *store, List *user);

#endif