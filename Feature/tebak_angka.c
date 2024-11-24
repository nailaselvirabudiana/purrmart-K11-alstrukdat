#include <stdio.h>
#include "tebak_angka.h"
#include "../ADT/random/random.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"

void tebak_angka(){
    int x = Random();
    int i = 10;
    for(i; i>0; i--){
        printf("\n");
        printf("Tebak angka: ");
        START();
        int y = 0;
        while(!EOP){
            switch(currentChar){
                case '1': y = (y*10) + 1; break;
                case '2': y = (y*10) + 2; break;
                case '3': y = (y*10) + 3; break;
                case '4': y = (y*10) + 4; break;
                case '5': y = (y*10) + 5; break;
                case '6': y = (y*10) + 6; break;
                case '7': y = (y*10) + 7; break;
                case '8': y = (y*10) + 8; break;
                case '9': y = (y*10) + 9; break;
                case '0': y = (y*10) + 0; break;
                default: break;
            }
            ADV();
        }
        if(y > x){
            printf("Tebakanmu lebih besar!\n");
        }
        if(y < x){
            printf("Tebakanmu lebih kecil!\n");
        }
        if(y == x){
            printf("Tebakanmu Benar! ");
            int reward = i * 50;
            printf("+%d rupiah telah ditambahkan ke akun anda.", reward);
            break;
        }
    }
}