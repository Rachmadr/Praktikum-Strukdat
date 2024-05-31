/* File : lmain.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 / Rachmad Rifa'i */
/* Tanggal : 03 November 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "List1.h"

int main(){
    //Kamus Lokal
    List1 L;
    address A;
    address B;
    char V;

    //Algoritme
    CreateList(&L);

//    Alokasi(&A);
//    A->info = 'G';
//    A->next = NIL;
//    Alokasi(&B);
//    B->info = 'H';
//    B->next = A;
//    L.First = B;

    printf("==INSERT FIRST==\n");
    InsertVFirst(&L, 'o');
    InsertVFirst(&L, 'i');
    InsertVFirst(&L, 'r');
    InsertVFirst(&L, 'w');
    PrintList(L);
    printf("\nBanyak elemen = %d", NbElm(L));
    printf("\n");

    printf("\n==INSERT LAST==\n");
    InsertVLast(&L, 'a');
    InsertVLast(&L, 'i');
    InsertVLast(&L, 'y');
    PrintList(L);
    printf("\nBanyak elemen = %d", NbElm(L));
    printf("\n");

    printf("\n==DELETE FIRST==\n");
    DeleteVFirst(&L, &V);
    PrintList(L);
    printf("\nV = %c", V);
    printf("\nBanyak elemen = %d", NbElm(L));
    printf("\n");

    printf("\n==DELETE LAST==\n");
    DeleteVLast(&L, &V);
    PrintList(L);
    printf("\nV = %c", V);
    printf("\nBanyak elemen = %d", NbElm(L));
    printf("\n");


//    SearchX(L, 'y', &A);
//    printf("%p\n", A);

    printf("\n==UPDATE X==\n");
    UpdateX(&L, 'o', 'f');
    PrintList(L);
    printf("\n");

    printf("\n==INVERS==\n");
    Invers(&L);
    PrintList(L);
    Invers(&L);
    printf("\n");

    printf("\n[CountX]Banyaknya huruf : %d", CountX(L, 'a'));

    printf("\n[FrekuensiX]Frekuensi huruf : %f.3", FrekeuensiX(L, 'a'));

    printf("\n[Modus]Modus : %c", Modus(L));
    printf("\n");

    printf("\n==SEARCH ALL X==\n");
    SearchAllX(L, 'i');
    printf("\n");

    printf("\n==SEARCH ALL X==\n");
    InsertVAfter(&L, 'o', 'd');
    printf("\n");
    InsertVAfter(&L, 'a', 'e');
    PrintList(L);
    return 0;
}
