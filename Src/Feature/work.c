#include <stdio.h>
#include <time.h>
#include "work.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/delay/delay.h"

int work(){
    printf("Daftar Pekerjaan:\n");
    printf("    1. Evil Lab Assistant (Pendapatan=100, durasi=14s)\n");
    printf("    2. OWCA Hiring Manager (Pendapatan=4200, durasi=21s)\n");
    printf("    3. Cikapundunginator Caretaker (Pendapatan=7000, durasi=30s)\n");
    printf("    4. Mewing Specialist (Pendapatan=10000, durasi=22s)\n");
    printf("    5. Inator Connoisseur (Pendapatan=997, durasi=15s)\n");
    printf("\n");
    printf("Masukkan Pekerjaan yang dipilih: ");
    STARTWORD();

    int Case;
    char Evil[] = "Evil", Lab[] = "Lab", Assistant[] = "Assistant";
    char OWCA[] = "OWCA", Hiring[] = "Hiring", Manager[] = "Manager";
    char Cikapundunginator[] = "Cikapundunginator", Caretaker[] = "Caretaker";
    char Mewing[] = "Mewing", Specialist[] = "Specialist";
    char Inator[] = "Inator", Connoisseur[] = "Connoisseur";

    if(Word2int(currentWord) == 1){
        Case = 1;
    }else if(Word2int(currentWord) == 2){
        Case = 2;
    }else if(Word2int(currentWord) == 3){
        Case = 3;
    }else if(Word2int(currentWord) == 4){
        Case = 4;
    }else if(Word2int(currentWord) == 5){
        Case = 5;
    }else if(StringCompare(str2Word(Evil), currentWord)){
        ADVWORD();
        if(StringCompare(str2Word(Lab), currentWord)){
            ADVWORD();
            if(StringCompare(str2Word(Assistant), currentWord)){
                Case = 1;
            }
        }
    }else if(StringCompare(str2Word(OWCA), currentWord)){
        ADVWORD();
        if(StringCompare(str2Word(Hiring), currentWord)){
            ADVWORD();
            if(StringCompare(str2Word(Manager), currentWord)){
                Case = 2;
            }
        }
    }else if(StringCompare(str2Word(Cikapundunginator), currentWord)){
        ADVWORD();
        if(StringCompare(str2Word(Caretaker), currentWord)){
            Case = 3;
        }
    }else if(StringCompare(str2Word(Mewing), currentWord)){
        ADVWORD();
        if(StringCompare(str2Word(Specialist), currentWord)){
            Case = 4;
        }
    }else if(StringCompare(str2Word(Inator), currentWord)){
        ADVWORD();
        if(StringCompare(str2Word(Connoisseur), currentWord)){
            Case = 5;
        }
    }else{
        printf("Input invalid!\n");
        return 0;
    }
    
    switch(Case){
    case 1:
        printf("Anda sedang bekerja sebagai Evil Lab Assistant... harap tunggu.\n");
        wait_for_seconds(14);
        printf("Pekerjaan selesai, +100 rupiah telah ditambahkan ke akun anda.");
        return 100;
        break;    
    case 2:
        printf("Anda sedang bekerja sebagai OWCA Hiring Manager... harap tunggu.\n");
        wait_for_seconds(21);
        printf("Pekerjaan selesai, +4200 rupiah telah ditambahkan ke akun anda.");
        return 4200;
        break;    
    case 3:
        printf("Anda sedang bekerja sebagai Cikapundunginator Caretaker... harap tunggu.\n");
        wait_for_seconds(30);
        printf("Pekerjaan selesai, +7000 rupiah telah ditambahkan ke akun anda.");
        return 7000;
        break;    
    case 4:
        printf("Anda sedang bekerja sebagai Mewing Specialist... harap tunggu.\n");
        wait_for_seconds(22);
        printf("Pekerjaan selesai, +10000 rupiah telah ditambahkan ke akun anda.");
        return 10000;
        break;    
    case 5:
        printf("Anda sedang bekerja sebagai Inator Connoisseur... harap tunggu.\n");
        wait_for_seconds(15);
        printf("Pekerjaan selesai, +997 rupiah telah ditambahkan ke akun anda.");
        return 997;
        break;    
    }
}