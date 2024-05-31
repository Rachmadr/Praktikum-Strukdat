/* File : pohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 & Rachmad Rifa'i */
/* Tanggal : 08 Desember 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "pohon3.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree3) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk bintree3 P} */
void Alokasi3 (bintree3 *P){
    /* Kamus Lokal */

    /* Algoritme */
    *P = (bintree3) malloc (sizeof(node3));
} //representasi fisik prosedur
//bintree3 Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:bintree3) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian bintree3 P} */
void Dealokasi3 (bintree3 *P){
    /* Kamus Lokal */

    /* Algoritme */
    free(*P);
}

/********** PEMBUATAN bintree3 KOSONG ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
    /* Kamus Lokal */
    bintree3 P;

    /* Algoritme */
    Alokasi3(&P);
    if(P != NIL){
        parent(P) = A;
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

/****** SELEKTOR *****/

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    return (P != NIL) && (left(P) == NIL) && (right(P) == NIL);
}

/* function IsBiner (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    return (P != NIL) && (left(P) != NIL) && (right(P) != NIL);
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    return (P != NIL) && (left(P) != NIL) && (right(P) == NIL);
}

/* function IsUnerRight(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    return (P != NIL) && (left(P) == NIL) && (right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree3 P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
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

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    if(IsEmptyTree(P)){
        return 0;
    }
    else{
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
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

    /* Algoritme */
    return (a > b) ? a : b;
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    if(IsEmptyTree(P) || NbElmTree(P) == 1){
        return 0;
    }
    else{
        return 1 + max2(Tinggi(left(P)),Tinggi(right(P)));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    if(IsEmptyTree(P)){
        return 0;
    }
    else{
        return 1 + max2(Level(left(P)), Level(right(P)));
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T){
    /* Kamus Lokal */

    /* Algoritme */
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

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure concat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void pconcat(list1 *Asli, list1 Tambahan){
    /* Kamus Lokal */
    address i;

    /* Algoritme */
    if(!IsEmptyList(Tambahan)){
        i = First(Tambahan);
        do{
            InsertVLast(&(*Asli), info(i));
            i = next(i);
        }while(i != NIL);
    }
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
list1 fconcat(list1 Asli, list1 Tambahan){
    /* Kamus Lokal */
    list1 Baru;
    address i;

    /* Algoritme */
    CreateList(&Baru);
    i = First(Asli);
    if(i != NIL){
        do{
            InsertVLast(&Baru, info(i));
            i = next(i);
        }while(i != NIL);
    }
    i = First(Tambahan);
    if(i != NIL){
        do{
            InsertVLast(&Baru, info(i));
            i = next(i);
        }while(i != NIL);
    }
    return Baru;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
list1 linearPrefix(bintree3 P){
    /* Kamus Lokal */
    list1 L;

    /* Algoritme */
    CreateList(&L);
    if(P != NIL){
        InsertVLast(&L, info(P));
        L = fconcat(L, linearPrefix(left(P)));
        L = fconcat(L, linearPrefix(right(P)));
    }
    return L;

}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
list1 linearPosfix(bintree3 P){
    /* Kamus Lokal */
    list1 L;

    /* Algoritme */
    CreateList(&L);
    if(P != NIL){
        L = fconcat(L, linearPosfix(left(P)));
        L = fconcat(L, linearPosfix(right(P)));
        InsertVLast(&L, info(P));
    }
    return L;
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
list1 linearInfix(bintree3 P){
    /* Kamus Lokal */
    list1 L;

    /* Algoritme */
    CreateList(&L);
    if(P != NIL){
        L = fconcat(L, linearInfix(left(P)));
        InsertVLast(&L, info(P));
        L = fconcat(L, linearInfix(right(P)));
    }
    return L;
}

//FUNGSI BANTUAN
/*function GetInfoLevel(P:bintree3, N:integer) -> list1
{menghasilkan list node dari P pada level tertentu}*/
list1 GetInfoLevel(bintree3 P, int N){
    /* Kamus Lokal */
    list1 L;

    /* Algoritma */
    CreateList(&L);
    if(!IsEmptyTree(P)){
        if(N == 1){
            InsertVLast(&L, info(P));
        }
        else{
            L = fconcat(L, GetInfoLevel(left(P), N-1));
            L = fconcat(L, GetInfoLevel(right(P), N-1));
        }
    }
    return L;
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
list1 linearBreadthFS(bintree3 P){
    /* Kamus Lokal */
    list1 L;
    int i;

    /* Algoritme */
    CreateList(&L);
    if(P != NIL){
        for(i=1; i<=Level(P);i++){
            L = fconcat(L, GetInfoLevel(P,i));
        }
    }
    return L;
}


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

void DFS(bintree3 P, char S){

    if(IsEmptyTree(P)){
        printf("%c",S);
    }
    else{
        if(IsDaun(P)){
            printf("%c%c", S, info(P));
        }
        else{
            DFS(left(P), S+info(P));
            DFS(right(P), S+info(P));
        }
    }
}


/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX(bintree3 P, infotype X){
    /* Kamus Lokal */

    /* Algoritme */
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X){
    /* Kamus Lokal */

    /* Algoritme */
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P){
    /* Kamus Lokal */

    /* Algoritme */
    DFS(P, " ");
}
