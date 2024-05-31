/* Program   : mtqueue.c */
/* Deskripsi : Main ADT Tqueue */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 22 September 2023 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "tqueue.h"
#include "boolean.h"

int main()
{
    //Kamus lokal
    tqueue A;
    tqueue B;
    char E;

    //Algoritma
    createQueue(&A);
    createQueue(&B);

    printf("===PRINT QUEUE KOSONG===\n");
    printQueue(A);
    printf("\nindex head = %d",Head(A));
    printf("\nnilai head = %c",infoHead(A));
    printf("\nindex tail = %d",Tail(A));
    printf("\nnilai tail = %c",infoTail(A));
//    printf("\n========================\n");

    printf("\n========ENQUEUE========\n");
    enqueue(&A, 'a');
    enqueue(&A, 'b');
    enqueue(&A, 'c');
    printQueue(A);
//    printf("\nindex head = %d",Head(A));
//    printf("\nnilai head = %c",infoHead(A));
    printf("\nindex tail = %d",Tail(A));
//    printf("\nnilai tail = %c",infoTail(A));
//    printf("\n=======================\n");

    printf("\n========DEQUEUE========\n");
    dequeue(&A, &E);
    printQueue(A);
//    printf("\nindex head = %d",Head(A));
//    printf("\nnilai head = %c",infoHead(A));
    printf("\nindex tail = %d",Tail(A));
//    printf("\nnilai tail = %c",infoTail(A));
    printf("\nNilai dikeluarkan = %c",E);
//    printf("\n========================\n");

    printf("\n=======VIEW TABEL=======\n");
    viewQueue(A);
//    printf("\n========================\n");

    printf("\n=======MAX LENGTH=======\n");
//    printQueue(A);
//    printf("\n");
//    printQueue(B);
    printf("size queue terpanjang : %d",maxlength(A,B));
//    printf("\n========================\n");


    printf("\n========ENQUEUE2========\n");
//    enqueue(&A, 'a');
//    enqueue(&A, 'b');
//    enqueue(&B, 'x');
    enqueue2(&A, &B, 'k');
    printf("[QUEUE A] : ");
    printQueue(A);
    printf("\n[QUEUE B] : ");
    printQueue(B);
//    printf("\n========================\n");

    printf("\n========DEQUEUE2========\n");
    dequeue2(&A, &B, &E);
    printf("[QUEUE A] : ");
    printQueue(A);
    printf("\n[QUEUE B] : ");
    printQueue(B);
    printf("\nNilai dikeluarkan = %c",E);
    printf("\n========================\n");

    return 0;
}
