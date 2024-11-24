#ifndef LOAD_H
#define LOAD_H

#include "barang.h"
#include "user.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

void constructfilepath(char*filepath, char*basepath, char*filename);

void printFileContents(FILE *file);

void loadFile(char*filename);

#endif
