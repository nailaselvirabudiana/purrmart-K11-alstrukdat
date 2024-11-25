#include <stdio.h>
#include "queue.h"


void CreateQueue(Queue *q){

    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean queueisEmpty(Queue q){
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean queueisFull(Queue q){
    return queuelength(q) == CAPACITY;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int queuelength(Queue q){
    if (queueisEmpty(q)) {
        return 0;
    }
    else if (IDX_TAIL(q) < IDX_HEAD(q)) {
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
    }
    else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1 ;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
/* PRAPRAKTIKUM
void enqueue(Queue *q, BarangElType val); */
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void enqueue(Queue *q, BarangElType val){
    if (queueisEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1 ) % CAPACITY;
    }
    TAIL(*q) = val;

}

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, BarangElType *val){
    *val = HEAD(*q);

    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q) {
    printf("[");
    if (!queueisEmpty(q)) {
        if (IDX_HEAD(q) <= IDX_TAIL(q)) {
            for (int i = IDX_HEAD(q); i < IDX_TAIL(q); i++) {
                printf("{Nama: ");
                printWord(q.buffer[i].name);
                printf(", Harga: %d}", q.buffer[i].price);
                printf(", ");
            }
            // Print last element without comma
            printf("{Nama: ");
            printWord(q.buffer[IDX_TAIL(q)].name);
            printf(", Harga: %d}", q.buffer[IDX_TAIL(q)].price);
        } else {
            for (int i = IDX_HEAD(q); i < CAPACITY; i++) {
                printf("{Nama: ");
                printWord(q.buffer[i].name);
                printf(", Harga: %d}", q.buffer[i].price);
                printf(", ");
            }
            for (int i = 0; i < IDX_TAIL(q); i++) {
                printf("{Nama: ");
                printWord(q.buffer[i].name);
                printf(", Harga: %d}", q.buffer[i].price);
                printf(", ");
            }
            // Print last element without comma
            printf("{Nama: ");
            printWord(q.buffer[IDX_TAIL(q)].name);
            printf(", Harga: %d}", q.buffer[IDX_TAIL(q)].price);
        }
    }
    printf("]\n");
}

/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */