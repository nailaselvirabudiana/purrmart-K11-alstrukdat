#include <stdio.h>
#include "queue.h"

int main() {

    Queue q;
    CreateQueue(&q);

    if (queueisEmpty(q)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }


    printf("The length of the queue is %d.\n", queuelength(q));


    BarangElType barang1;
    BarangElType barang2;
    BarangElType barang3;

    barang1.name = str2Word("ayam goreng");
    barang2.name = str2Word("ayam bakar");
    barang3.name = str2Word("ayam rebus");


    enqueue(&q, barang1);
    printf("Enqueued: ");
    printWord(barang1.name);
    printf("\n");

    enqueue(&q, barang2);
    printf("Enqueued: ");
    printWord(barang2.name);
    printf("\n");

    enqueue(&q, barang3);
    printf("Enqueued: ");
    printWord(barang3.name);
    printf("\n");


    if (queueisFull(q)) {
        printf("The queue is full.\n");
    } else {
        printf("The queue is not full.\n");
    }

    printf("The length of the queue is %d.\n", queuelength(q));

 
    printf("Queue contents:\n");
    displayQueue(q);
    printf("\n");

    dequeue(&q, &barang1);
    printf("Dequeued: ");
    printWord(barang1.name);
    printf("\n");
    displayQueue(q);
    printf("\n");

    dequeue(&q, &barang2);
    printf("Dequeued: ");
    printWord(barang2.name);
    printf("\n");
    displayQueue(q);
    printf("\n");

    dequeue(&q, &barang3);
    printf("Dequeued: ");
    printWord(barang3.name);
    printf("\n");
    displayQueue(q);
    printf("\n");


    printf("The length of the queue is %d.\n", queuelength(q));

    return 0;
}