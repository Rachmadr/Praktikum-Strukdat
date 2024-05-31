/* File : mpohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 & Rachmad Rifa'i */
/* Tanggal : 01 Desember 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"
#include "pohon1.h"

int main()
{
    /* Kamus Lokal */
    bintree T2;
    bintree Tb; //Tree balance
    bintree Bt;
    char X;

    /* Algoritma */
    T2 = NIL;
    Tb = NIL;
    Bt = NIL;

//    Tb = BuildBalanceTree(6);
//    printf("Balance Tree : ");
//    PrintPrefix(Tb);
//    printf("\nPrint Level : ");
//    PrintLevel(Tb, 3);
//    printf("\n\n");
//
//    // Tree
//    T2 = Tree('l', Tree('h',NIL,NIL), Tree('r',Tree('m',NIL,NIL),Tree('v',NIL,NIL)));
//    printf("\n==Tree==\n");
//    PrintPrefix(T2);
//
//    AddDaun(&T2,'h','i',true);
//    printf("\n\n==Add Daun==\n");
//    PrintPrefix(T2);
//
//    AddDaunTerkiri(&T2, 'd');
//    printf("\n\n==Add Daun Terkiri==\n");
//    PrintPrefix(T2);
//
//    InsertX(&T2, 'j');
//    printf("\n\n==Insert X==\n");
//    PrintPrefix(T2);
//
//    DelDaunTerkiri(&T2, &X);
//    printf("\n\n==Del Daun Terkiri==\n");
//    PrintPrefix(T2);
//
//    DelDaun(&T2, 'v');
//    printf("\n\n==Del Daun==\n");
//    PrintPrefix(T2);
//
//    DeleteX(&T2, 'd');
//    printf("\n\n==Delete X==\n");
//    PrintPrefix(T2);
//
//    UpdateAllX(&Tb,'x','i');
//    printf("\n\n==Update All X==\n");
//    PrintPrefix(Tb);
//
//    printf("\n\nmax = %c \n", maxTree(T2));
//    printf("min = %c \n", minTree(T2));

    printf("\n==InsSearch==\n");
    InsSearch(&Bt, 'k');
    InsSearch(&Bt, 'f');
    InsSearch(&Bt, 'r');
    InsSearch(&Bt, 'a');
    InsSearch(&Bt, 'g');
    PrintPrefix(Bt);

    printf("\n==BSearch==\n");
    if(BSearch(Bt, 'g')){
        printf("ditemukan");
    }
    else{
        printf("tidak ditemukan");
    }



    return 0;
}
