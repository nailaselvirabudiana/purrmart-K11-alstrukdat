#include <stdio.h>
#include <stdlib.h>
#include "Feature/work.h"
#include "Feature/wordl3.h"
#include "Feature/tebak_angka.h"
#include "Feature/auth.h"
#include "Feature/user.h"
#include "Feature/load.h"
#include "Feature/save.h"
#include "Feature/wishlist.h"
#include "ADT/linkedlist/linkedlist.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/list/list.h"
#include "ADT/list_dinamis/list_dinamis.h"
#include "ADT/queue/queue.h"
#include "ADT/barang/barang.h"
#include "ADT/store/store.h"
#include "Feature/quantumwordl3.h"

int main(){
    ArrayDin store = MakeArrayDin();
    Queue request_queue;
    List user = MakeListUser();
    CreateQueue(&request_queue);
    Linkedlist wishlist;
    

    char Login[] = "LOGIN";
    char Logout[] = "LOGOUT";
    char Register[] = "REGISTER";
    char Work[] = "WORK";
    char Challenge[] = "CHALLENGE";
    char Tebak[] = "Tebak";
    char Angka[] = "Angka"; 
    char Wordl3[] = "WORDL399";
    char quant[] = "QuantumWordl3";
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

    boolean masuk = false;
    boolean islogin = false;

    while ( !masuk ){
        printf(">> ");
        STARTWORD();
        char Start[] = "START";
        while (true) {
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
                STARTWORD();
                char* file;
                file = Word2str(currentWord);
                loadFile(file,&store,&user);
                masuk = true;
                // return 0;
                break;
            }
            else {
                printf("Masukkan command lain");
                printf("\n>> ");
                STARTWORD();
            }
        }

    while (!islogin){
        printf("=====[Welcome To PURRMART]=====\n");
        printf("    1. REGISTER\n");
        printf("    2. LOGIN\n");
        printf("    3. LOGOUT\n");
        printf("    4. QUIT\n");
        printf(">> ");
        STARTWORD();

        if (StringCompare(currentWord, str2Word(Register))){
            registerUser(&user);
            DisplayListUser(user);
        }
        else if (StringCompare(currentWord, str2Word(Login))){
            int a = 0;
            a += login(&user);
            printf("%d", a);
            if (a == 1){
                islogin = true;
            }
        
        }
        else if (StringCompare(currentWord, str2Word(Quit))){
            break;
        }
        else {
            printf("Masukkan perintah yang valid\n");
            // STARTWORD();
        }
    }        

    while(Word2str(currentWord) != Quit){
        
        printf("=====[PURRMART LOBBY]=====\n");
        printf("    1. WORK\n");
        printf("    2. WORK CHALLENGE\n");
        printf("    3. STORE LIST\n");
        printf("    4. STORE REQUEST\n");
        printf("    5. STORE SUPPLY \n");
        printf("    6. STORE REMOV\n");
        printf("    7. STORE LOGOUT\n");
        printf("    8. QUIT\n");
        printf("Ketik \"HELP\" for more information \n");
        printf(">> ");
        STARTWORD();
            if((StringCompare(str2Word(Work), currentWord))){
                if(currentChar == '\n'){
                    user.A->uang += work();
                    // printf("\n>> ");
                    
                }else{
                    ADVWORD();
                    if(StringCompare(str2Word(Challenge), currentWord)){
                        printf("Daftar challenge ayng tersedia:\n");
                        printf("1. Tebak Angka (biaya main=200)\n");
                        printf("2. WORDL399 (biaya main=500)\n");
                        printf("3. QuantumWordl3 (biaya main = 1000)\n");
                        printf("\n");
                        printf("Masukkan challenge yang hendak dimainkan: ");
                        
                        if(StringCompare(str2Word(Tebak), currentWord)){
                            ADVWORD();
                            if(StringCompare(str2Word(Angka), currentWord)){
                                user.A->uang += tebak_angka();
                                // printf("\n>> ");
                                
                            }
                        }
                        if(StringCompare(str2Word(Wordl3), currentWord)){
                            user.A->uang += wordl3();
                            // printf("\n>> ");
                            
                        }
                        if(StringCompare(str2Word(quant), currentWord)){
                            user.A->uang += QuantumWordle();
                            // printf("\n>> ");
                            
                            
                        }
                    }
                } 
            }else if(StringCompare(str2Word(Store), currentWord)){
                ADVWORD();
                if (StringCompare(str2Word(List), currentWord)) {
                    store_list(store);
                    // printf("\n>> ");
                    
                } else if (StringCompare(str2Word(Request), currentWord)) {
                    handle_store_request(&request_queue, store);
                    // printf("\n>> ");
                    
                } else if (StringCompare(str2Word(Supply), currentWord)) {
                    handle_store_supply(&store, &request_queue);
                    // printf("\n>> ");
                    
                } else if (StringCompare(str2Word(Remove), currentWord)) {
                    handle_store_remove(&store);
                    // printf("\n>> ");
                    
                } else {
                    printf("Command Tidak tersedia, coba lagi\n");\
                    // printf(">> ");
                    
                }
        }else if (StringCompare(str2Word(Quit), currentWord)) {
            printf("Save atau tidak ? (YES/NO)");
            STARTWORD();
            if (StringCompare(str2Word("YES"), currentWord)){
                STARTWORD();
                char* filename = Word2str(currentWord);
                saveFile(filename, &store, &user );
            }
            return 0;
        }
        
        
        
        else {
            printf("Perintah tidak valid\n");
        }
        
    }
    return 0;
}
}        