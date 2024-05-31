/* File : mpohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 / Rachmad Rifa'i */
/* Tanggal : 24 November 2023*/
#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

int main()
{
    /* Kamus Lokal */
    bintree T;
    bintree U;
    bintree V;

    /* Algoritma */
    T = Tree('a',Tree('b',NIL,Tree('d',NIL,Tree('e',NIL,NIL))),Tree('c',Tree('f',NIL,NIL),Tree('g',NIL,NIL)));
    U = Tree('a',Tree('g',NIL,NIL),NIL);
    V = Tree('a',Tree('e',NIL,NIL),Tree('v',NIL,Tree('u',NIL,NIL)));

    PrintPrefix(T);
    printf("\nakar: %c", GetAkar(T));
    printf("\njumlah daun: %d", NbDaun(T));
    printf("\ntinggi: %d", Tinggi(T));
////    printf("\n%d", Tingkat(T));
    printf("\ncount level: %d", CountLevelT(T, 2));
    printf("\ndaun terkiri: %c", GetDaunTerkiri(T));
    printf("\ncount vocal: %d", CountVocal(T));
    printf("\nfrekuensi: %f\n\n", FrekuensiX(T, 'b'));
    printf("level x: %i\n", LevelX(T, 'd'));

    UpdateX(&T, 'c', 'u');
    PrintPrefix(T);
    printf("\n");
    PrintPref(T);

    if(IsSkewLeft(T)){
        printf("true");
    }else{
        printf("false");
    }


    return 0;
}
