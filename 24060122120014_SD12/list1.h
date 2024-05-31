/* File : list1.h */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 / Rachmad Rifa'i */
/* Tanggal : 03 November 2023 */
#ifndef list1_H
#define list1_H

#include "boolean.h"
#define NIL NULL
#define First(L) (L).First
#define info(P)  (P)->info
#define next(P)  (P)->next

/* typedef infotype = character */
typedef char infotype; /* elemen bertipe character */
/* typedef address = pointer to ElmList */
typedef struct tElmList *address; /* Representasi address dengan pointer */
/* typedef ElmList =< info:infotype, next:address > */
typedef struct tElmList
{ infotype info;
  address next;
} ElmList;
/* typedef List1 =< First:address>*/
typedef struct { address First; } List1;

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList (List1 *L);

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L);

/*PENELUSURAN*/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List1 L);

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L);

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:address) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk address P} */
void Alokasi (address *P);

/* procedure Dealokasi (P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P);

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V );

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V );

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V);

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V);

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A);

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y);

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List1 *L);

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X);

/*function FrekeuensiX(L:List1) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekeuensiX(List1 L, infotype X);

/*function Modus(L:List1) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List1 L);

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X);

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=VA 	Zsebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA );

#endif // list1_H
