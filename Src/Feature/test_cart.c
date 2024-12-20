#include <stdio.h>
#include "cart.h"
#include "../ADT/barang/barang.h"
#include "../ADT/stack/stack.h"
#include "history.h"
#include "profile.h"

int main() {
    Map cart;
    Stack riwayat_pembelian;
    int uang_user = 1000000; // Example user balance
    

    // Initialize the cart and stack
    CreateEmptyMap(&cart);
    CreateEmptyStack(&riwayat_pembelian);

    // Create some sample items

//     Isi riwayat:
// 1. Ayam Goreng Crisbar 1 20
// 2. END_TRANSACTION 1 20
// 3. Meong 1 500
// 4. END_TRANSACTION 1 500
// 5. AK47 1 10
// 6. END_TRANSACTION 1 10
// 7. Lalabu 1 20
// 8. M14 2 15
// 9. END_TRANSACTION 2 35
// 10. Lalabu 1 20
// 11. AK47 8 80
// 12. END_TRANSACTION 2 100
// 13. Lalabu 1 20
// 14. AK47 2 20
// 15. END_TRANSACTION 2 40
   
    CurrentBarang Barang1 = CreateInfoBarang(str2Word("Ayam Goreng Crisbar"), 5000);
    CurrentBarang Barang2 = CreateInfoBarang(str2Word("Banana kukus"), 2000);
    CurrentBarang Barang3= CreateInfoBarang(str2Word("Orange mantap"), 3000);

    // Test adding items to the cart
    printf("Adding items to the cart:\n");
    cart_add(&cart, &Barang1, 30);  // Add 3 Apples
    cart_add(&cart, &Barang2, 50);  // Add 5 Bananas
    cart_add(&cart, &Barang3, 20);  // Add 2 Oranges
    cart_add(&cart, &Barang1, 20);  // Add 2 more Apples
    printf("sukses\n");
    cart_pay(&cart, &uang_user, &riwayat_pembelian);

    cart_add(&cart, &Barang2, 30); 

    // Print purchase history
    // printf("\nPurchase history:\n");
    // CartItem item;
    // while (!IsEmptyStack(riwayat_pembelian)) {
    //     Pop(&riwayat_pembelian, &item);
    //     printf("%d x %s (Total: %d)\n", item.quantity, Word2str(item.item.name), item.quantity * item.item.price);
    // }


    cart_pay(&cart, &uang_user, &riwayat_pembelian);
    
    PrintStack(riwayat_pembelian);


    show_history(riwayat_pembelian,2);


    return 0;
}