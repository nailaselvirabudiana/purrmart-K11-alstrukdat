#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

int main() {

    printf("Masukkan teks yang diakhiri dengan ENTER:\n");
    STARTWORD();


    while (!isEndWord()) {

        printf("Kata yang dibaca: ");
        printWord(currentWord);
        printf("\n");


        char *str = Word2str(currentWord);
        printf("String yang dikonversi: %s\n", str);


        if (isKataInteger(currentWord)) {
            int num = Word2int(currentWord);
            printf("Integer yang dikonversi: %d\n", num);
        } else {
            printf("Bukan integer yang valid.\n");
        }


        ADVWORD();
    }


    Word kata1 = str2Word("Hello");
    Word kata2 = str2Word("World");
    Word kataGabungan = ConcatWord(kata1, kata2);
    printf("Kata gabungan: ");
    printWord(kataGabungan);
    printf("\n");


    Word kataClone = CloneWord(kata1);
    printf("Kloning kata: ");
    printWord(kataClone);
    printf("\n");

}