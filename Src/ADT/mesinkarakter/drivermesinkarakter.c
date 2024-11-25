
#include <stdio.h>
#include "ADT/mesinkarakter/mesinkarakter.h"

#define MAX_LENGTH 1000  // Define the maximum length of the string


int main() {
    /*START MESINKATA UNTUK MEMULAI*/
    char str[MAX_LENGTH];

    // Start reading characters
    printf("Enter characters, end with '.':\n");
    START();

    int length = panjangKarakter(str);

    printf("The string you entered is: %s\n", str);
    printf("The length of the string is: %d\n", length);

    

    /*LOOP TESTING*/

    while (length != 5) {
        printf("The length of the string must be 5. Please try again.\n");
        START();
        length = panjangKarakter(str);
    }

    END();

    printf("The string is: %s\n", str);
    printf("The string you entered is: %s\n", str);
    printf("The length of the string is: %d\n", length);

    return 0;
}

// while(){
//     START
//     ...
//     salah
//     bener break; 
// }
