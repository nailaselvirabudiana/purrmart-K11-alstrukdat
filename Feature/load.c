#include <stdio.h>
#include <stdlib.h>
#include "load.h"

// Untuk membentuk path file
void constructFilePath(char*filepath, char*basepath, char*filename){
    int i = 0;
    while(basepath[i] != '\0'){
        filepath[i] = basepath[i];
        i++;
    }
    int j = 0;
    while(filename[j] != '\0'){
        filepath[i] = filename[j];
        i++;
        j++;
    }
    filepath[i] = '\0';
}

// Hanya untuk debugging
void printFileContents(FILE *file) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Menampilkan karakter ke layar
    }
}

// Untuk membaca file
void loadFile(char*filename){
    char filepath[100];
    constructFilePath(filepath, "./save/", filename);
    ArrayDin store = MakeArrayDin();
    ArrayDin user = MakeArrayDin();
    STARTFILE(filepath);
    if (currentFile != NULL){
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        printf("Isi file %s:\n", filename); // Untuk debug
        printFileContents(currentFile); // Untuk debug
        END();
    }
    else{
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
    }

}
