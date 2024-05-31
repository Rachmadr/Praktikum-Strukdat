/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 / Rachmad Rifa'i */
/* Tanggal : 24 November 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk bintree P} */
void Alokasi (bintree *P){
    /* Kamus Lokal */

    /* Algoritma */
    (*P) = (bintree) malloc (sizeof(node));

} //representasi fisik prosedur
//bintree Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:bintree) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P){
    /* Kamus Lokal */

    /* Algoritma */
    free(*P);
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right){
    /* Kamus Lokal */
    bintree P;

    /* Algoritma */
    Alokasi(&P);
    if(P != NIL){
        info(P) = akar;
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return info(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return (left(P) == NIL) && (right(P) == NIL);
}

/* function IsBiner (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return (P != NIL) && (left(P) != NIL) && (right(P) != NIL);
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return (P != NIL) && (left(P) != NIL) && (right(P) == NIL);
}

/* function IsUnerRight(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return (P != NIL) && (left(P) == NIL) && (right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(P == NIL){
        printf("( )");
    }
    else{
        printf("%c (", info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(P)){
        return 0;
    }
    else{
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(!IsBiner(P)){
        return 1;
    }
    else{
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
    /* Kamus Lokal */

    /* Algoritma */
//    return (a+b+abs(a-b))/2;
    return (a > b) ? a : b;
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(P) || NbElm(P) == 1){
        return 0;
    }
    else{
        return 1 + max2(Tinggi(left(P)),Tinggi(right(P)));
    }
}

int Tingkat(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(P)){
        return 0;
    }
    else{
        return 1 + max2(Tingkat(left(P)),Tingkat(right(P)));
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(P)){
        return false;
    }
    else{
        if(info(P) == X){
            return true;
        }
        else{
            return SearchX(left(P), X) || SearchX(right(P), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    /* Kamus Lokal */

    /* Algoritma */
    if(!IsEmptyTree(*P)){
        if(info(*P) == X){
            info(*P) = Y;
        }
        else{
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(P)){
        return 0;
    }
    else{
        if(info(P)==X){
            return 1 + CountX(left(P), X) + CountX(right(P), X);
        }
        else{
            return CountX(left(P), X) + CountX(right(P), X);
        }
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsUnerLeft(P)){
        return true;
    }
    else{
        return IsSkewLeft(left(P));
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsUnerRight(P)){
        return true;
    }
    else{
        return IsSkewRight(right(P));
    }
}

/* procedure PrintPref(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPref(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if(P == NIL){
        printf("( )");
    }
    else{
        printf("%c", info(P));
        if(right(P) != NIL || left(P) != NIL){
            printf(" (");
            PrintPref(left(P));
            if(right(P)!= NIL){
                printf(", ");
                PrintPref(right(P));
            }
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    /* Kamus Lokal */
    boolean found;

    /* Algoritma */
    if(SearchX(P, X)){
        if(info(P) == X){
            return 1;
        }
        else{
            return max2(1+LevelX(left(P),X), 1+LevelX(right(P),X));
        }

    }

}


/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(P)){
        return 0;
    }
    else if(T == 1){
        return 1;
    }
    else{
        return CountLevelT(left(P), (T - 1)) + CountLevelT(right(P), (T - 1));
    }
}


/*function GetDaunTerkiri(bintree P)-> infotype
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    if (P == NIL){
        return '#';
    }
    else if(IsDaun(P)){
        return info(P);
    }
    else{
        return GetDaunTerkiri(left(P));
    }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    if(!IsEmptyTree(P)){
        return CountX(P, X)/(float)NbElm(P);
    }
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(L)){
        return 0;
    }
    else{
        if(tolower(info(L) == 'a') || tolower(info(L) == 'i') || tolower(info(L) == 'u') || tolower(info(L) == 'e') || tolower(info(L) == 'o')){
            return 1 + CountVocal(left(L)) + CountVocal(right(L));
        }
        else{
            return CountVocal(left(L)) + CountVocal(right(L));
        }
    }
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P);
