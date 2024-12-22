#include "map.h"
#include "../barang/barang.h"

int main() {
    Map myMap;
    CreateEmptyMap(&myMap);

    CurrentBarang barang1 = CreateInfoBarang(str2Word("Apple"), 5000);
    CurrentBarang barang2 = CreateInfoBarang(str2Word("Banana"), 2000);
    CurrentBarang barang3 = CreateInfoBarang(str2Word("Orange"), 3000);

    InsertMap(&myMap, barang1, 10);
    InsertMap(&myMap, barang2, 20);
    InsertMap(&myMap, barang3, 15);

    // PrintMap(myMap);

    printf("Value of Apple: %d\n", ValueMap(myMap, barang1));
    printf("Value of Banana: %d\n", ValueMap(myMap, barang2));
    printf("Value of Orange: %d\n", ValueMap(myMap, barang3));

    PrintMap(myMap);

    DeleteMap(&myMap, barang2);
    ubahValueMap(&myMap, barang1, 20);
    printf("Value after deletion: %d\n", ValueMap(myMap, barang2));
    printf("Value after update: %d\n", ValueMap(myMap, barang1));   

    PrintMap(myMap);

    return 0;
}


