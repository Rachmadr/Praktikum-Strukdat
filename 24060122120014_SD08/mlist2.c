/* File : mlist2.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Rachmad Rifa'i */
/* Tanggal : 10 November 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main(){
    //Kamus lokal
    list2 L2;
    char V;
    address A;

    //Algoritme
    CreateList(&L2);

    printf("InsertVFirst : ");
    InsertVFirst(&L2, 'u');
    InsertVFirst(&L2, 'z');
    InsertVFirst(&L2, 'f');
    InsertVFirst(&L2, 'y');
    PrintList(L2);

    printf("\nInsertVLast : ");
    InsertVLast(&L2, 'x');
    InsertVLast(&L2, 'h');
    InsertVLast(&L2, 'i');
    InsertVLast(&L2, 'l');
    PrintList(L2);
    printf("Jumlah Elemen : %d\n", NbElm(L2));

    printf("\nDeleteVFirst : ");
    DeleteVFirst(&L2, &V);
    PrintList(L2);
    printf("V : %c\n", V);

    printf("\nDeleteVLast : ");
    DeleteVLast(&L2, &V);
    PrintList(L2);
    printf("V : %c\n", V);

    printf("\nDeleteX : ");
    DeleteX(&L2, 'u', &V);
    DeleteX(&L2, 'b', &V);
    PrintList(L2);
    printf("V : %c\n", V);

    SearchX(L2, 'i', &A);
    printf("\nSearch : %p", A);

    printf("\n\nUpdateX : ");
    UpdateX(&L2, 'h', 'z');
    PrintList(L2);

    printf("\nInvers : ");
    Invers(&L2);
    PrintList(L2);

    printf("\nInsertVAfterX : ");
    InsertVAfterX(&L2, 'z', 'i');
    PrintList(L2);

    printf("\nInsertVBeforeX : ");
    InsertVBeforeX(&L2, 'i', 'o');
    PrintList(L2);

    printf("\nDeleteVAfterX : ");
    DeleteVAfterX(&L2, 'i', &V);
    PrintList(L2);
    printf("V : %c\n", V);

    printf("\nDeleteVBeforeX : ");
    DeleteVBeforeX(&L2, 'f', &V);
    PrintList(L2);
    printf("V : %c\n", V);

    printf("\n[CountX]Banyaknya huruf : %d", CountX(L2, 'i'));

    printf("\n[FrekuensiX]Frekuensi huruf : %f", FrekuensiX(L2, 'i'));

    printf("\n[Modus]Modus : %c\n", Modus(L2));

    printf("\nSearchAllX : ");
    SearchAllX(L2, 'z');
    printf("\n");


    return 0;
}
