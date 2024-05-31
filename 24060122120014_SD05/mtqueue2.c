/* Program   : mtqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 29 September 2023 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "tqueue2.h"
#include "boolean.h"

int main()
{
    //Kamus lokal
    tqueue2 A;
    tqueue2 B;
    char E;

    //Algoritma
    createQueue2(&A);
    createQueue2(&B);

    printf("\n=====QUEUE2 A=====\n");
    enqueue2(&A, 'a');
    enqueue2(&A, 'b');
    enqueue2(&A, 'c');
    dequeue2(&A, &E);
    printQueue2(A);
    printf("\nhead : %d", head2(A));
    printf("\ntail : %d", tail2(A));
    printf("\ninfo head : %c", infoHead2(A));
    printf("\ninfo tail : %c", infoTail2(A));
    printf("\nsize A : %d\n", sizeQueue2(A));

    printf("\n=====QUEUE2 A setelah enqueue2N=====\n");
//    enqueue2N(&A, 3);
    printQueue2(A);
    printf("\nhead : %d", head2(A));
    printf("\ntail : %d", tail2(A));
    printf("\ninfo head : %c", infoHead2(A));
    printf("\ninfo tail : %c", infoTail2(A));
    printf("\nsize A : %d\n", sizeQueue2(A));

    printf("\n=====QUEUE2 B=====\n");
    enqueue2(&B, 'b');
    enqueue2(&B, 'c');
    printQueue2(B);
    printf("\nhead : %d", head2(B));
    printf("\ntail : %d", tail2(B));
    printf("\ninfo head : %c", infoHead2(B));
    printf("\ninfo tail : %c", infoTail2(B));
    printf("\nsize B : %d\n", sizeQueue2(B));

    if(isEqualQueue2(A,B)){
        printf("\nQueue A dan B sama");
    }
    else{
        printf("\nQueue A dan B tidak sama");
    }

    return 0;
}
