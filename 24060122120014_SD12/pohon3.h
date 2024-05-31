/* File : pohon3.h */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 & Rachmad Rifa'i */
/* Tanggal : 08 Desember 2023 */
#ifndef pohon3_H
#define pohon3_H

#include "boolean.h"
#include "list1.h"
#define NIL NULL
#define akar(P)    (P)->info
#define parent(P)  (P)->parent
#define info(P)    (P)->info
#define visited(P) (P)->visited
#define left(P)    (P)->left
#define right(P)   (P)->right
#define list1       List1

/* typedef infotype = character */
typedef char infotype; /* elemen bertipe character */
/* typedef bintree3 = pointer to tnode */
typedef struct tnode3* bintree3; /* Representasi bintree3 dengan pointer */
/* typedef node =< info:infotype, left:bintree3, right:bintree3 > */
typedef struct tnode3
{   bintree3  parent;
    infotype info;
    boolean  visited;
    bintree3  left;
    bintree3  right;
} node3;
/* DEFINISI bintree3 kosong = NIL = ( ) ))*/

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree3) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk bintree3 P} */
void Alokasi3 (bintree3 *P); //representasi fisik prosedur
//bintree3 Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:bintree3) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian bintree3 P} */
//void Dealokasi3 (bintree3 *P);

/********** PEMBUATAN bintree3 KOSONG ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan);

/****** SELEKTOR *****/

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P);

/* function IsDaun (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P);

/* function IsBiner (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P);

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P);

/* function IsUnerRight(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P);

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree3 P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree3 P);

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P);

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P);

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b);

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P);

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P);

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T);

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure concat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void pconcat(list1 *Asli, list1 Tambahan);

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
list1 fconcat(list1 Asli, list1 Tambahan);

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
list1 linearPrefix(bintree3 P);

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
list1 linearPosfix(bintree3 P);

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
list1 linearInfix(bintree3 P);


//FUNGSI BANTUAN
/*function GetInfoLevel(P:bintree3, N:integer) -> list1
{menghasilkan list node dari P pada level tertentu}*/
list1 GetInfoLevel(bintree3 P, int N);

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
list1 linearBreadthFS(bintree3 P);


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX(bintree3 P, infotype X);

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X);

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P);



#endif
