#include <stdio.h>
#include <stdlib.h>

// Daftar include Feature
#include "Feature/work.h"
#include "Feature/wordl3.h"
#include "Feature/tebak_angka.h"
#include "Feature/auth.h"
#include "Feature/user.h"
#include "Feature/load.h"
#include "Feature/save.h"
#include "Feature/wishlist.h"
#include "Feature/quantumwordl3.h"
#include "Feature/cart.h"
#include "Feature/history.h"




// Daftar include ADT
#include "ADT/linkedlist/linkedlist.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/list/list.h"
#include "ADT/list_dinamis/list_dinamis.h"
#include "ADT/queue/queue.h"
#include "ADT/barang/barang.h"
#include "ADT/store/store.h"

int main(){
    ArrayDin store = MakeArrayDin();
    Queue request_queue;
    List user = MakeListUser();
    CreateQueue(&request_queue);
    Linkedlist wishlist;
    CreateEmpty(&wishlist);

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
    char Cart[] = "CART";
    char Wishlist[] = "WISHLIST";
    char Add[] = "ADD";
    char Swap[]  = "SWAP";
    char Clear[] = "CLEAR";
    char Show[] = "SHOW";
    char Pay[] = "PAY";
    char History[] = "HISTORY";
    char Profile[] = "PROFILE";

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
            if (a == 1){
                islogin = true;
            }
        }
        else if (StringCompare(currentWord, str2Word(Quit))){
            break;
        }
        else {
            printf("Masukkan perintah yang valid\n");
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
        printf("    8. PROFILE\n");
        printf("    9. CART ADD\n");
        printf("    10. CART REMOVE\n");
        printf("    11. CART SHOW\n");
        printf("    12. CART PAY\n");
        printf("    13. HISTORY\n");
        printf("    14. WISHLIST ADD\n");
        printf("    15. WISHLIST SWAP\n");
        printf("    16. WISHLIST REMOVE\n");
        printf("    17. WISHLIST CLEAR\n");
        printf("    18. WISHLIST SHOW\n");
        printf("    19. QUIT\n");
        printf("Ketik \"HELP\" for more information \n");
        printf(">> ");
        STARTWORD();
            if((StringCompare(str2Word(Work), currentWord))){
                if(currentChar == '\n'){
                    user.A->uang += work();
                    
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
                                if(user.A->uang < 200){
                                    printf("Uang tidak cukup\n");
                                }else{
                                    user.A->uang -= 200;
                                    user.A->uang += tebak_angka();
                                }
                            }
                        }
                        if(StringCompare(str2Word(Wordl3), currentWord)){
                            if(user.A->uang < 500){
                                printf("Uang tidak cukup\n");
                            }else{
                                user.A->uang -= 500;
                                user.A->uang += wordl3();
                            }
                            
                        }
                        if(StringCompare(str2Word(quant), currentWord)){
                            if(user.A->uang < 1000){
                                printf("Uang tidak cukup\n");
                            }else{
                                user.A->uang -= 1000;
                                user.A->uang += QuantumWordle();
                            }
                        }
                    }
                } 
            }else if(StringCompare(str2Word(Store), currentWord)){
                ADVWORD();
                if (StringCompare(str2Word(List), currentWord)) {
                    store_list(store);
                    
                } else if (StringCompare(str2Word(Request), currentWord)) {
                    handle_store_request(&request_queue, store);
                    
                } else if (StringCompare(str2Word(Supply), currentWord)) {
                    handle_store_supply(&store, &request_queue);
                    
                } else if (StringCompare(str2Word(Remove), currentWord)) {
                    handle_store_remove(&store);
                    
                } else {
                    printf("Command Tidak tersedia, coba lagi\n");\
                    
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
        }else if(StringCompare(str2Word(Wishlist), currentWord)) {
            ADVWORD();
            if(StringCompare(str2Word(Add), currentWord)){
                WishlistAdd(store, &wishlist);
            }else if(StringCompare(str2Word(Swap), currentWord)){ //kalau ini salah harusnya di spacing
                ADVWORD();
                int swap1 = Word2int(currentWord);
                ADVWORD();
                int swap2 = Word2int(currentWord);
                WishlistSwap(&wishlist, swap1, swap2);
            }else if(StringCompare(str2Word(Remove), currentWord)){
                if(currentChar == '\n'){
                    WishlistRemove(&wishlist);
                }else{
                    ADVWORD();
                    int iremove = Word2int(currentWord);
                    WishlistRemovePos(&wishlist, iremove);
                }
            }else if(StringCompare(str2Word(Clear), currentWord)){
                WishlistClear(&wishlist);
            }else if(StringCompare(str2Word(Show), currentWord)){
                WishlistShow(wishlist);
            }
        }else if(StringCompare(str2Word(Profile), currentWord)){
            profile(user);
        } else if (StringCompare(str2Word(Cart), currentWord)) {
            ADVWORD();
            if (StringCompare(str2Word(Add), currentWord)) {
                ADVWORD();
                Word stuffName;
                stuffName = currentWord;
                ADVWORD();
                Word angka;
                angka = currentWord;

                while(!EOP){
                    stuffName = ConcatWord(stuffName, str2Word(" "));
                    stuffName = ConcatWord(stuffName, angka);
                    // stuffName += " " + lastString;
                    ADVWORD();
                    angka = currentWord;
                }

                IdxType P = SearchNameArrayDin(store, stuffName);
                if(P == -1){
                    printf("Barang tidak ada di store\n");
                }else{
                    CurrentBarang barang = store.A[P];
                    cart_add(&user.A->cart, &barang, Word2int(angka));

                }
            } else if (StringCompare(str2Word(Remove), currentWord)) {
                ADVWORD();
                Word stuffName;
                stuffName = currentWord;
                ADVWORD();
                Word angka;
                angka = currentWord;

                IdxType P = SearchNameArrayDin(store, stuffName);
                if(P == -1){
                    printf("Barang tidak ada di keranjang\n");
                }else{
                    CurrentBarang barang = store.A[P];
                    cart_remove(&user.A->cart, &barang, Word2int(angka));
                }
            } else if (StringCompare(str2Word(Pay), currentWord)) {
                ADVWORD();
                Word input;
                input = currentWord;
                cart_pay(&user.A->cart, &user.A->uang, &user.A->riwayat_pembelian, input);
            } else if (StringCompare(str2Word(Show), currentWord)) {
                printCart(user.A->cart);
            }
        } else if (StringCompare(str2Word(History), currentWord)) { 
            ADVWORD();
            int n = Word2int(currentWord);
            show_history(user.A->riwayat_pembelian, n);
        } 



        else {
            printf("Perintah tidak valid\n");
        }
        
    }
    return 0;
}
}        