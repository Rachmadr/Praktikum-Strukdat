/* File : mpohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 & Rachmad Rifa'i */
/* Tanggal : 08 Desember 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "list1.h"

int main()
{
    /* Kamus Lokal */
    bintree3 P, Q, R, S, T, U;
    List1 L1, L2, L3, LL;

    /* Algoritme */
    printf("POHON3\n");
    U = Tree3(S, 'a', false, NIL, NIL);
    T = Tree3(S, 'n', false, NIL, NIL);
    R = Tree3(Q, 'r', false, NIL, NIL);
    S = Tree3(P, 'i', false, T, U);
    Q = Tree3(P, 'u', false, NIL, R);
    P = Tree3(NIL, 'f', false, Q, S);
    PrintPrefix(P);

    printf("\nJumlah node pohon P: %d", NbElmTree(P));
    printf("\nJumlah daun pohon P: %d", NbDaun(P));
    printf("\nTinggi pohon P: %d", Tinggi(P));
    printf("\nLevel pohon P: %d", Level(P));
    printf("\nBanyaknya node pada level tertentu pohon P: %d", CountLevelT(P, 3));

    printf("\n\nLIST");
    CreateList(&L1);
    CreateList(&L2);

    InsertVFirst(&L1, 'n');
    InsertVFirst(&L1, 'i');
    InsertVFirst(&L1, 'j');
    printf("\nList 1: ");
    PrintList(L1);

    InsertVFirst(&L2, 'e');
    InsertVFirst(&L2, 'a');
    InsertVFirst(&L2, 't');
    printf("\nList 2: ");
    PrintList(L2);

    printf("\nList L3-fconcat: ");
    L3 = fconcat(L1, L2);
    PrintList(L3);

    printf("\nList L1-pconcat: ");
    pconcat(&L1, L2);
    PrintList(L1);


    printf("\n\nLINEARISASI");
    LL = linearPrefix(P);
    printf("\nLinear Prefix: ");
    PrintList(LL);

    LL = linearPosfix(P);
    printf("\nLinear Posfix: ");
    PrintList(LL);

    LL = linearInfix(P);
    printf("\nLinear Infix: ");
    PrintList(LL);

    //LL = GetInfoLevel(P,3);
    LL = linearBreadthFS(P);
    printf("\nLinear BFS: ");
    PrintList(LL);


    //printAllPaths(P);
}
