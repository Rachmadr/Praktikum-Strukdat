/* File : mlist3.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Rachmad Rifa'i */
/* Tanggal : 18 November 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

int main()
{
    /* Kamus Lokal */
    List3 L3;
    char V;
    address A;

    /* ALgoritme */
    CreateList(&L3);

    printf("InsertVFirst : ");
    InsertVFirst(&L3, 'u');
    InsertVFirst(&L3, 'x');
    InsertVFirst(&L3, 'i');
    PrintList(L3);

    printf("InsertVLast : ");
    InsertVLast(&L3, 'r');
    InsertVLast(&L3, 'y');
    InsertVLast(&L3, 'n');
    InsertVLast(&L3, 'g');
    InsertVLast(&L3, 'u');
    InsertVLast(&L3, 'a');
    PrintList(L3);

    printf("InsertVAfterX : ");
    InsertVAfterX(&L3, 'i', 'w');
    InsertVAfterX(&L3, 'a', 'h');
    PrintList(L3);

    printf("InsertVBeforeX : ");
    InsertVBeforeX(&L3, 'i', 'o');
    InsertVBeforeX(&L3, 'a', 'z');
    PrintList(L3);
    printf("Banyak elemen : %d\n", NbElm(L3));

    printf("\nDeleteVFirst : ");
    DeleteVFirst(&L3, &V);
    DeleteVFirst(&L3, &V);
    PrintList(L3);

    printf("DeleteVLast : ");
    DeleteVLast(&L3, &V);
    DeleteVLast(&L3, &V);
    PrintList(L3);

    printf("DeleteX : ");
    DeleteX(&L3, 'x', &V);
    PrintList(L3);

    SearchX(L3, 'r', &A);
    printf("\nSearch : %p\n", A);

    printf("\ncountX = %d", CountX(L3, 'w'));
    printf("\nFreqX = %f", FrekuensiX(L3, 'g'));
    printf("\ncountvocal = %d", CountVocal(L3));
    printf("\ncountNG = %d", CountNG(L3));
    printf("\nmod = %c", Modus(L3));

    printf("\n\nDeleteVAfterX : ");
    DeleteVAfterX(&L3, 'n', &V);
    PrintList(L3);
    printf("DeleteVBeforeX : ");
    DeleteVBeforeX(&L3, 'n', &V);
    PrintList(L3);

    printf("SearchAllX : ");
    SearchAllX(L3, 'u');

    printf("\n\nList :");
    PrintList(L3);
    printf("Invers :");
    Invers(&L3);
    PrintList(L3);

    return 0;
}
