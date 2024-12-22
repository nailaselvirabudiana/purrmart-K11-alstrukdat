#ifndef LOAD_H
#define LOAD_H

#include "../ADT/barang/barang.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/list_dinamis/list_dinamis.h"
#include "../ADT/list/list.h"
#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/setmap/map.h"
#include "user.h"

void loadFile(const char *filename, ArrayDin *store, List *user);

#endif