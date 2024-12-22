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
#include "Feature/profile.h"
#include "Feature/hiasan.h"
#include "Feature/graph.h"



// Daftar include ADT
#include "ADT/linkedlist/linkedlist.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/list/list.h"
#include "ADT/list_dinamis/list_dinamis.h"
#include "ADT/stack/stack.h"
#include "ADT/setmap/map.h"
#include "ADT/queue/queue.h"
#include "ADT/barang/barang.h"
#include "ADT/store/store.h"


boolean isLoggedIn = false;


void clear_screen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}


int main(){

    ArrayDin store = MakeArrayDin();
    List Listuser = MakeListUser();
    Queue request_queue;
    CreateQueue(&request_queue);

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
    char DFS[] = "OPTIMASIRUTE";

    opening();
    printf("\t\t\t ==============================[SELAMAT DATANG DI PURRMART]==============================\t\t\t\n");
    printf("\t\t\t                                       1. START                      \t\t\t\n");
    printf("\t\t\t                                       2. LOAD                       \t\t\t\n");
    printf("\t\t\t                                       3. QUIT                       \t\t\t\n");
    printf("\t\t\t                          Ketik \"HELP\" for more information        \t\t\t\n");


    boolean masuk = false;


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
                clear_screen();
                return 0;
            }else if(StringCompare(str2Word(Load), currentWord)){
                STARTWORD();
                char* file; Word folder; Word filename;
                folder = str2Word("save/");
                filename = currentWord;
                file = Word2str(ConcatWord(folder, currentWord));
                loadFile(file,&store,&Listuser);
                masuk = true;
                break;
            }
            else {
                printf("Masukkan command lain");
                printf("\n>> ");
                STARTWORD();
            }
        }

    while (true) {
        while (!isLoggedIn){
            printf("=====[Welcome To PURRMART]=====\n");
            printf("    1. REGISTER\n");
            printf("    2. LOGIN\n");
            printf("    3. LOGOUT\n");
            printf("    4. QUIT\n");
            printf(">> ");
            STARTWORD();

            if (StringCompare(currentWord, str2Word(Register))){
                registerUser(&Listuser);
                sleep(1);
                clear_screen();
            }
            else if (StringCompare(currentWord, str2Word(Login))){
                int a = 0;
                a += login(&Listuser);
                if (a == 1){
                    isLoggedIn = true;
                }
                sleep(1);
                clear_screen();
            }
            else if (StringCompare(currentWord, str2Word(Logout))){
                clear_screen();
                logout();
            }
            else if (StringCompare(currentWord, str2Word(Quit))){
                isLoggedIn = false;
                printf("Sampai jumpa kembali !");
                sleep(1);
                clear_screen();
                return 0;
            }
            else {
                clear_screen();
                printf("Masukkan perintah yang valid\n");
            }
        }        

        while(isLoggedIn) {
            
            printf("=====[PURRMART LOBBY]=====\n");
            printf("    1. WORK\n");
            printf("    2. WORK CHALLENGE\n");
            printf("    3. STORE LIST\n");
            printf("    4. STORE REQUEST\n");
            printf("    5. STORE SUPPLY \n");
            printf("    6. STORE REMOVE\n");
            printf("    7. PROFILE\n");
            printf("    8. CART ADD\n");
            printf("    9. CART REMOVE\n");
            printf("    10. CART SHOW\n");
            printf("    11. CART PAY\n");
            printf("    12. HISTORY\n");
            printf("    13. WISHLIST ADD\n");
            printf("    14. WISHLIST SWAP\n");
            printf("    15. WISHLIST REMOVE\n");
            printf("    16. WISHLIST CLEAR\n");
            printf("    17. WISHLIST SHOW\n");
            printf("    18. OPTIMASIRUTE\n");
            printf("    19. LOGOUT\n");
            printf("    20. QUIT\n");
            printf("Ketik \"HELP\" for more information \n");
            printf(">> ");
            STARTWORD();
                if((StringCompare(str2Word(Work), currentWord))){
                    clear_screen();
                    if(currentChar == '\n'){
                        LoggedInUser.uang += work();
                    sleep(3);
                    clear_screen();
                    }else{
                        ADVWORD();
                        if(StringCompare(str2Word(Challenge), currentWord)){
                            clear_screen();
                            printf("Daftar challenge yang tersedia:\n");
                            printf("1. Tebak Angka (biaya main=200)\n");
                            printf("2. WORDL399 (biaya main=500)\n");
                            printf("3. QuantumWordl3 (biaya main = 1000)\n");
                            printf("\n");
                            printf("Masukkan challenge yang hendak dimainkan: ");

                            STARTWORD();
                            
                            if(StringCompare(str2Word(Tebak), currentWord)){
                                ADVWORD();
                                if(StringCompare(str2Word(Angka), currentWord)){
                                    if(LoggedInUser.uang < 200){
                                        printf("Uang tidak cukup\n");
                                    }else{
                                        LoggedInUser.uang -= 200;
                                        LoggedInUser.uang += tebak_angka();
                                    }
                                    // clear_screen();
                                }
                                
                            }
                            if(StringCompare(str2Word(Wordl3), currentWord)){
                                if(LoggedInUser.uang < 500){
                                    printf("Uang tidak cukup\n");
                                }else{
                                    LoggedInUser.uang -= 500;
                                    LoggedInUser.uang += wordl3();
                                }
                                // clear_screen();
                                
                            }
                            if(StringCompare(str2Word(quant), currentWord)){
                                if(LoggedInUser.uang < 1000){
                                    printf("Uang tidak cukup\n");
                                }else{
                                    LoggedInUser.uang -= 1000;
                                    LoggedInUser.uang += QuantumWordle();
                                }
                                // clear_screen();
                            }
                        }
                    } 
                }else if(StringCompare(str2Word(Store), currentWord)){
                    clear_screen();
                    ADVWORD();
                    if (StringCompare(str2Word(List), currentWord)) {
                        store_list(store);
                        // clear_screen();
                        
                    } else if (StringCompare(str2Word(Request), currentWord)) {
                        handle_store_request(&request_queue, store);
                        // clear_screen();
                        
                    } else if (StringCompare(str2Word(Supply), currentWord)) {
                        handle_store_supply(&store, &request_queue);
                        // clear_screen();
                        
                    } else if (StringCompare(str2Word(Remove), currentWord)) {
                        handle_store_remove(&store);
                        // clear_screen();
                        
                    } else {
                        printf("Command Tidak tersedia, coba lagi\n");
                        clear_screen();
                    }
                }

                else if (StringCompare(str2Word(Help), currentWord)) {
                    clear_screen();
                    printf("=====[ Menu Help PURRMART]=====\n");
                    printf("    1. WORK -> Untuk bekerja\n");
                    printf("    2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
                    printf("    3. STORE LIST -> Untuk melihat barang-barang di toko\n");
                    printf("    4. STORE REQUEST -> Untuk meminta penambahan barang\n");
                    printf("    5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
                    printf("    6. STORE REMOVE -> Untuk menghapus barang\n");
                    printf("    7. PROFILE -> Untuk melihat profil\n");
                    printf("    8. CART ADD -> Untuk menambahkan barang ke keranjang (Masukkan command \"CART ADD <barang> <Jumlah>\")\n");
                    printf("    9. CART REMOVE -> Untuk menghapus barang dari keranjang (Masukkan command \"CART ADD <barang> <Jumlah>\")\n");
                    printf("    10. CART SHOW -> Untuk melihat isi keranjang\n");
                    printf("    11. CART PAY -> Untuk membayar barang dalam keranjang\n");
                    printf("    12. HISTORY -> Untuk melihat riwayat pembelian\n");
                    printf("    13. WISHLIST ADD -> Untuk menambahkan barang ke wishlist\n");
                    printf("    14. WISHLIST SWAP -> Untuk menukar barang di wishlist\n");
                    printf("    15. WISHLIST REMOVE -> Untuk menghapus barang dari wishlist\n");
                    printf("    16. WISHLIST CLEAR -> Untuk mengosongkan wishlist\n");
                    printf("    17. WISHLIST SHOW -> Untuk melihat isi wishlist\n");
                    printf("    18. OPTIMASIRUTE -> Untuk mengoptimalkan rute\n");
                    printf("    19. LOGOUT -> Untuk keluar dari akun yang digunakan\n");
                    printf("    20. QUIT -> Untuk keluar dari purryMart\n");
                    sleep(5);
                    clear_screen();
                }

            else if (StringCompare(str2Word(Quit), currentWord)) {
                clear_screen();
                printf("Save atau tidak ? (YES/NO)");
                STARTWORD();
                if (StringCompare(str2Word("YES"), currentWord)){
                    STARTWORD();
                    char* file; Word folder; Word filename;
                    folder = str2Word("save/");
                    filename = currentWord;
                    file = Word2str(ConcatWord(folder, currentWord));
                    saveFile(file, &store, &Listuser);
                }
                clear_screen();
                return 0;
            }else if(StringCompare(str2Word(Wishlist), currentWord)) {
                clear_screen();
                ADVWORD();
                if(StringCompare(str2Word(Add), currentWord)){
                    WishlistAdd(store, &LoggedInUser.wishlist);
                    clear_screen();
                }else if(StringCompare(str2Word(Swap), currentWord)){ //kalau ini salah harusnya di spacing
                    ADVWORD();
                    int swap1 = Word2int(currentWord);
                    ADVWORD();
                    int swap2 = Word2int(currentWord);
                    WishlistSwap(&LoggedInUser.wishlist, swap1, swap2);
                    clear_screen();
                    
                }else if(StringCompare(str2Word(Remove), currentWord)){
                    if(currentChar == '\n'){
                        WishlistRemove(&LoggedInUser.wishlist);
                        sleep(1);
                        clear_screen();
                    }else{
                        ADVWORD();
                        int iremove = Word2int(currentWord);
                        WishlistRemovePos(&LoggedInUser.wishlist, iremove);
                        sleep(1);
                        clear_screen();
                    }
                }else if(StringCompare(str2Word(Clear), currentWord)){
                    WishlistClear(&LoggedInUser.wishlist);
                    clear_screen();
                }else if(StringCompare(str2Word(Show), currentWord)){
                    WishlistShow(LoggedInUser.wishlist);
                    sleep(2);
                }
            }else if(StringCompare(str2Word(Profile), currentWord)){
                clear_screen();
                profile(LoggedInUser);
                sleep(2);
            } else if (StringCompare(str2Word(Cart), currentWord)) {
                clear_screen();
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
                        cart_add(&LoggedInUser.cart, &barang, Word2int(angka));

                    }
                    sleep(1);
                    clear_screen();
                } else if (StringCompare(str2Word(Remove), currentWord)) {
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

                    CurrentBarang cart_barang;
                    cart_barang.name = stuffName;
                    
                    cart_remove(&LoggedInUser.cart, &cart_barang, Word2int(angka));
                    sleep(1);
                } else if (StringCompare(str2Word(Pay), currentWord)) {
                    cart_pay(&LoggedInUser.cart, &LoggedInUser.uang, &LoggedInUser.riwayat_pembelian);
                    sleep(0.5);
                    clear_screen();
                } else if (StringCompare(str2Word(Show), currentWord)) {
                    clear_screen();
                    printCart(LoggedInUser.cart);
                    sleep(0.5);
                }
            } else if (StringCompare(str2Word(History), currentWord)) { 
                clear_screen();
                ADVWORD();
                if (currentWord.Length == 0){
                    printf("input tidak valid");
                } else {
                int n = Word2int(currentWord);
                show_history(LoggedInUser.riwayat_pembelian, n); }
                sleep(2);
            }  else if (StringCompare(str2Word("OPTIMASIRUTE"), currentWord)){
                clear_screen();
                OptimasiRute();
                sleep(2);
            } 
            else if (StringCompare(str2Word(Logout),currentWord)) { 
                clear_screen();
                logout();
                sleep(0.5);
            } 
            else {
                clear_screen();
                printf("Perintah tidak valid\n");
            }
        }
    }
    
    return 0;

    }   
}