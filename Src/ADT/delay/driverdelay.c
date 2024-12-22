#include <stdio.h>
#include "delay.h"



int main() {
    int duration;

    printf("Masukkan durasi (detik) untuk animasi loading: ");
    scanf("%d", &duration);

    printf("Memulai animasi loading selama %d detik...\n", duration);
    wait_for_seconds(duration);
    printf("Animasi loading selesai!\n");

    printf("Masukkan durasi (detik) untuk sleep: ");
    scanf("%d", &duration);

    printf("Program akan sleep selama %d detik...\n", duration);
    sleep(duration);
    printf("Sleep selesai!\n");

    return 0;
}
