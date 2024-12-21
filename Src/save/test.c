#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
    #ifdef _WIN32
        system("cls");  // Untuk Windows
    #else
        system("clear");  // Untuk Linux/Unix
    #endif
}

int main() {
    printf("Sebelum membersihkan layar\n");
    getchar();  // Tunggu input
    clear_screen();
    printf("Setelah membersihkan layar\n");
    return 0;
}
