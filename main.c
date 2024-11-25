#include <stdio.h>
#include <stdlib.h>
#include "Feature/work.h"
#include "Feature/wordl3.h"
#include "Feature/tebak_angka.h"
#include "Feature/login.h"
#include "Feature/register.h"
#include "Feature/logout.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/array/array.h"
#include "ADT/userauth/userauth.h"
#include "ADT/list_dinamis/list_dinamis.h"
#include "ADT/queue/queue.h"
#include "ADT/barang/barang.h"
#include "ADT/store/store.h"

TabKata arrusers;
TabKata arrpassword;

int main(){
    ArrayDin store = MakeArrayDin(10);
    Queue request_queue;
    CreateQueue(&request_queue);

    MakeEmpty(&arrusers);
    MakeEmpty(&arrpassword);
    char Login[] = "LOGIN";
    char Logout[] = "LOGOUT";
    char Register[] = "REGISTER";
    char Work[] = "WORK";
    char Challenge[] = "CHALLENGE";
    char Tebak[] = "Tebak";
    char Angka[] = "Angka"; 
    char Wordl3[] = "WORDL399";
    char Store[] = "STORE";
    char List[] = "LIST";
    char Request[] = "REQUEST";
    char Supply[] = "SUPPLY";
    char Remove[] = "REMOVE";
    char Help[] = "HELP";
    char Load[] = "LOAD";
    char Save[] = "SAVE";
    char Quit[] = "QUIT";
    printf("=====[PURRMART]=====\n");
    printf("    1. START\n");
    printf("    2. LOAD\n");
    printf("    3. QUIT\n");
    printf("Ketik \"HELP\" for more information\n");

    printf(">> ");
    STARTWORD();
    char Start[] = "START";
    while(true){
        if(StringCompare(str2Word(Start), currentWord)){
            break;
        }else if(StringCompare(str2Word(Help), currentWord)){
            printf("=====[ Welcome Menu Help PURRMART]=====\n");
            printf("    1. START -> Untuk masuk sesi baru\n");
            printf("    2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
            printf("    3. QUIT -> Untuk keluar dari program\n");
            printf(">> ");
            STARTWORD();
        }else if(StringCompare(str2Word(Quit), currentWord)){
            return 0;
        }else if(StringCompare(str2Word(Load), currentWord)){
            //
        }else{
            printf(">> ");
            STARTWORD();
        }
    }
    printf("=====[Welcome To PURRMART]=====\n");
    printf("    1. REGISTER\n");
    printf("    2. LOGIN\n");
    printf("    3. LOGOUT\n");
    printf("    4. QUIT\n");
    printf("Ketik \"HELP\" for more information \n");
    printf(">> ");
    STARTWORD();
    while(Word2str(currentWord) != Quit){
        if(StringCompare(str2Word(Register), currentWord)){
            registerUser();
            printf("\n>> ");
            STARTWORD();
        }
        if(StringCompare(str2Word(Login), currentWord)){
            login();
            printf("=====[PURRMART LOBBY]=====\n");
            printf("    1. WORK\n");
            printf("    2. WORK CHALLENGE\n");
            printf("    3. STORE LIST\n");
            printf("    4. STORE REQUEST\n");
            printf("    5. STORE SUPPLY \n");
            printf("    6. STORE REMOV\n");
            printf("    7. STORE LOGOUT\n");
            printf("    8. STORE SAVE\n");
            printf("    9. QUIT\n");
            printf("Ketik \"HELP\" for more information \n");
            printf("\n>> ");
            STARTWORD();
        }
        if(StringCompare(str2Word(Logout), currentWord)){
            logout();
            printf("\n>> ");
            STARTWORD();
        }
        if(StringCompare(str2Word(Quit), currentWord)){
            return 0;
        }
        if(StringCompare(str2Word(Help), currentWord)){
            if(!isLoggedIn){
                printf("=====[ Login Menu Help PURRMART]=====\n");
                printf("    1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
                printf("    2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
                printf("    3. LOGOUT -> Untuk keluar dari akun yang sudah login\n");
                printf("    3. QUIT -> Untuk keluar dari program\n");
                printf(">> ");
                STARTWORD();
            }else{
                printf("=====[ Menu Help PURRMART]=====\n");
                printf("    1. WORK -> Untuk bekerja\n");
                printf("    2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
                printf("    3. STORE LIST -> Untuk melihat barang-barang di toko\n");
                printf("    4. STORE REQUEST -> Untuk melihat barang-barang di toko\n");
                printf("    5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
                printf("    6. STORE REMOVE -> Untuk menghapus barang\n");
                printf("    7. STORE LOGOUT -> Untuk keluar dari sesi\n");
                printf("    8. STORE SAVE -> Untuk menyimpan state ke dalam file\n");
                printf("    9. QUIT -> Untuk keluar dari program\n");
                printf(">> ");
                STARTWORD();
            }
        }
        if(isLoggedIn){

            if(StringCompare(str2Word(Register), currentWord)){
                registerUser();
                printf("\n>> ");
                STARTWORD();
            }
            else if(StringCompare(str2Word(Login), currentWord)){
                login();
                printf("\n>> ");
                STARTWORD();
            }
            else if(StringCompare(str2Word(Logout), currentWord)){
                logout();
                printf("\n>> ");
                STARTWORD();
            }
            else if((StringCompare(str2Word(Work), currentWord))){
                if(currentChar == '\n'){
                    work();
                    printf("\n>> ");
                    STARTWORD();
                }else{
                    ADVWORD();
                    if(StringCompare(str2Word(Challenge), currentWord)){
                        printf("Daftar challenge ayng tersedia:\n");
                        printf("1. Tebak Angka (biaya main=200)\n");
                        printf("2. WORDL399 (biaya main=500)\n");
                        printf("\n");
                        printf("Masukkan challenge yang hendak dimainkan: ");
                        STARTWORD();
                        if(StringCompare(str2Word(Tebak), currentWord)){
                            ADVWORD();
                            if(StringCompare(str2Word(Angka), currentWord)){
                                tebak_angka();
                                printf("\n>> ");
                                STARTWORD();
                            }
                        }
                        if(StringCompare(str2Word(Wordl3), currentWord)){
                            wordl3();
                            printf("\n>> ");
                            STARTWORD();
                        }
                    }
                }
            }
            else if(StringCompare(str2Word(Store), currentWord)){
                ADVWORD();
                if (StringCompare(str2Word(List), currentWord)) {
                    store_list(store);
                    printf("\n>> ");
                    STARTWORD();
                } else if (StringCompare(str2Word(Request), currentWord)) {
                    handle_store_request(&request_queue, store);
                    printf(">> ");
                    STARTWORD();
                } else if (StringCompare(str2Word(Supply), currentWord)) {
                    handle_store_supply(&store, &request_queue);
                    printf("\n>> ");
                    STARTWORD();
                } else if (StringCompare(str2Word(Remove), currentWord)) {
                    handle_store_remove(&store);
                    printf(">> ");
                    STARTWORD();
                } else if(StringCompare(str2Word(Quit), currentWord)){
                    return 0;
                }
            } else {
                printf("Command Tidak tersedia, coba lagi\n");\
                printf(">> ");
                STARTWORD();
            }
            
        }else{
            printf("Anda belum login.\n>> ");
            STARTWORD();
        }
    }
    return 0;
}