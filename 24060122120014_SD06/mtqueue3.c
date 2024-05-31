#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

/* Program   : mtqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model III: head memutar searah jarum jam */
/* NIM/Nama  : /24060122120014/Rachmad Rifa'i */
/* Tanggal   : 06 Oktober 2023 */
/***********************************/

int main(){
    //Kamus lokal
    tqueue3 A;
    char E;

    //Algoritma
    createQueue3(&A);
    enqueue3(&A, 'e');
    enqueue3(&A, 'f');
    enqueue3(&A, 'g');
    enqueue3(&A, 'h');
    enqueue3(&A, 'i');
    dequeue3(&A, &E);
    enqueue3(&A, 't');
    dequeue3(&A, &E);
    enqueue3E(&A, 'f');
    printf("head : %d\n", head3(A));
    printf("tail : %d\n", tail3(A));
    printf("isi head : %c\n", infoHead3(A));
    printf("isi tail : %c\n", infoTail3(A));

    printQueue3(A);
    printf("\n");
    viewQueue3(A);

    return 0;
}
