#ifndef graph_H
#define graph_H
# include "../ADT/mesinkarakter/mesinkarakter.h"
# include "../ADT/mesinkata/mesinkata.h"
# include "../ADT/boolean.h"

#define MAX 10
#define INF 99999 // Representasi jarak tak hingga



void printPath(int path[], int size);

void buildTree(int current, int depth);

int isDuplicateEdge(int u, int v);



void OptimasiRute();

#endif
