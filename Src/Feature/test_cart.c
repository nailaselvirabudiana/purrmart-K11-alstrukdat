#include <stdio.h>
#include "cart.h"
#include "../ADT/barang/barang.h"
#include "../ADT/stack/stack.h"
#include "history.h"

int main() {
    Map cart;
    Stack riwayat_pembelian;
    int uang_user = 1000000; // Example user balance

    // Initialize the cart and stack
    CreateEmptyMap(&cart);
    CreateEmptyStack(&riwayat_pembelian);

    // Create some sample items
   
    CurrentBarang Barang1 = CreateInfoBarang(str2Word("Apple goreng"), 5000);
    CurrentBarang Barang2 = CreateInfoBarang(str2Word("Banana kukus"), 2000);
    CurrentBarang Barang3= CreateInfoBarang(str2Word("Orange mantap"), 3000);

    // Test adding items to the cart
    printf("Adding items to the cart:\n");
    cart_add(&cart, &Barang1, 30);  // Add 3 Apples
    // cart_add(&cart, &Barang2, 50);  // Add 5 Bananas
    // cart_add(&cart, &Barang3, 20);  // Add 2 Oranges
    // cart_add(&cart, &Barang1, 20);  // Add 2 more Apples
    printf("sukses\n");
    cart_pay(&cart, &uang_user, &riwayat_pembelian, str2Word("Ya"));

    cart_add(&cart, &Barang2, 30); 

    // Print purchase history
    // printf("\nPurchase history:\n");
    // CartItem item;
    // while (!IsEmptyStack(riwayat_pembelian)) {
    //     Pop(&riwayat_pembelian, &item);
    //     printf("%d x %s (Total: %d)\n", item.quantity, Word2str(item.item.name), item.quantity * item.item.price);
    // }


    cart_pay(&cart, &uang_user, &riwayat_pembelian, str2Word("Ya"));
    
    PrintStack(riwayat_pembelian);


    show_history(riwayat_pembelian,2);


    return 0;
}