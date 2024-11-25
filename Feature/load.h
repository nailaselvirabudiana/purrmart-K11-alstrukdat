#ifndef LOAD_H
#define LOAD_H

#include "../ADT/barang/barang.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/list_dinamis/list_dinamis.h"
#include "../ADT/list/list.h"
#include "../ADT/queue/queue.h"

void loadFile(const char *filename, ArrayDin store, List money, List arrusers, List arrpassword);

#endif