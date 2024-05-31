/* File : list2.h */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Rachmad Rifa'i */
/* Tanggal : 10 November 2023 */
#ifndef list2_H
#define list2_H

#include "boolean.h"
#define NIL NULL
#define First(L) (L).First
#define info(P)  (P)->info
#define prev(P)  (P)->prev
#define next(P)  (P)->next

/* typedef infotype = character */
typedef char infotype; /* elemen bertipe character */
/* typedef address = pointer to ElmList */
typedef struct tElmList2* address; /* Representasi address dengan pointer */
/* typedef ElmList =< info:infotype, next:address > */
typedef struct tElmList2
{ address  prev;
  infotype info;
  address  next;
} ElmList2;
/* typedef list2 =< First:address>*/
typedef struct { address First; } list2;

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:list2)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList (list2 *L);

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:list2) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (list2 L);

/*PENELUSURAN*/
/*procedure PrintList(input L:list2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(list2 L);

/*function NbElm(L:list2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(list2 L);

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:address) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk address P} */
void Alokasi (address *P); //representasi fisik prosedur
//address Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P);

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(list2 *L, infotype V );

/*Procedure InsertVLast(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(list2 *L, infotype V );

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(list2 *L, infotype *V);

/*Procedure DeleteVLast(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(list2 *L, infotype *V);

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(list2 *L, infotype X, infotype *V);

/*** PENCARIAN ***/
/*Procedure SearchX(input L:list2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(list2 L, infotype X, address *A);

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:list2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(list2 *L, infotype X, infotype Y);

/*Procedure Invers(input/output L:list2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(list2 *L);

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(list2 *L, infotype X, infotype V);

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(list2 *L, infotype X, infotype V);

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(list2 *L, infotype X, infotype *V);

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(list2 *L, infotype X, infotype *V);

/*function CountX(L:list2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(list2 L, infotype X);

/*function FrekuensiX(L:list2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(list2 L, infotype X);

/*function Modus(L:list2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(list2 L);

/*Procedure SearchAllX(input L:list2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,2) menampilkan angka 1,6,9 */
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,8) menampilkan angka 0 */
void SearchAllX(list2 L, infotype X);

#endif
