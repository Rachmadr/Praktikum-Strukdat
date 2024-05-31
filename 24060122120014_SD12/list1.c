/* File : list1.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 / Rachmad Rifa'i */
/* Tanggal : 03 November 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "boolean.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
    //Kamus lokal

    //Algoritme
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
    //Kamus lokal

    //Algoritme
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List1 L){
    //Kamus lokal
    address P;

    //Algoritme
    if(IsEmptyList(L)){
        printf("KOSONG!");
    }
    else{
        P = First(L);
        while(P != NIL){
            printf("%c; ", info(P));
            P = next(P);
        }
    }
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
    //Kamus lokal
    address P;
    int len;

    //Algoritme
    len = 0;
    P = First(L);
    while(P != NIL){
        len++;
        P = next(P);
    }
    return len;
}

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:address) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk address P} */
void Alokasi (address *P){
    //Kamus lokal

    //Algoritme
    (*P) = (address) malloc (sizeof(ElmList));
}

/* procedure Dealokasi (P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //Kamus lokal

    //Algoritme
    free(*P);
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
    //Kamus lokal
    address P;

    //Algoritme
    Alokasi(&P);
    if(P != NIL){
        P->info = V;
        P->next = First(*L);
        First(*L) = P;
    }
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
    //Kamus lokal
    address P;
    address last;

    //Algoritme
    Alokasi(&P);
    P->info = V;
    P->next = NIL;
    if(P != NIL){
        if(First(*L) == NIL){
            First(*L) = P;
        }
        else{
            last = First(*L);
            while(next(last) != NIL){
                last = next(last);
            }
            next(last) = P;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
    //Kamus lokal
    address P;

    //Algoritme
    if(IsEmptyList(*L)){
        printf("List Kosong");
    }
    else{
        if(First(*L) != NIL){
            P = First(*L);
            (*V) = info(P);
            First(*L) = next(P);
            next(P) = NIL;
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
    //Kamus lokal
    address last;
    address before;

    //Algoritme
    if(IsEmptyList(*L)){
        printf("List Kosong");
    }
    else{
        if(NbElm(*L) == 1){
            DeleteVFirst(&(*L), &(*V));
        }else{
            if(First(*L) != NIL){
                last = First(*L);
                while(next(last) != NIL){
                    before = last;
                    last = next(last);
                }
            (*V) = info(last);
            next(before) = NIL;
            Dealokasi(&last);
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
    //Kamus Lokal
    address P;

    //Algoritme
    P = First(L);
    (*A) = NIL;
    while(P != NIL && (*A) == NIL){
        if(info(P) == X){
            (*A) = P;
        }
        P = next(P);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
    //Kamus Lokal
    address P;

    //Algoritme
    if(!(IsEmptyList(*L))){
        SearchX(*L, X, &P);
        if(P != NIL){
            info(P) = Y;
        }
        else{
            printf("tidak ditemukan nilai %c", X);
        }
    }
    else{
        printf("List Kosong");
    }
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List1 *L){
    //Kamus Lokal
    address P;
    List1 LB;

    //Algoritme
    if(!(IsEmptyList(*L))){
        if(NbElm > 1){
            CreateList(&LB);
            P = First(*L);
            while(P != NIL){
                InsertVFirst(&LB, info(P));
                P = next(P);
            }
            (*L) = LB;
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X){
    //Kamus Lokal
    address P;
    int countx;

    //Algoritme
    P = First(L);
    countx = 0;
    while(P != NIL){
        if(info(P) == X){
            countx++;
        }
        P = next(P);
    }
    return countx;
}

/*function FrekeuensiX(L:List1) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekeuensiX(List1 L, infotype X){
    //Kamus Lokal
    int countx;
    float freq;

    //Algoritme
    freq = 0;
    if(!(IsEmptyList(L))){
        countx = CountX(L, X);
        freq = countx/(float)NbElm(L);
    }
    return freq;
}

/*function Modus(L:List1) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List1 L){
    //Kamus Lokal
    address P;
    int x;
    int countx;
    char mod;

    //Algoritme
    P = First(L);
    mod = NIL;
    while(P != NIL){
        x = CountX(L, info(P));
        if (x > countx){
            countx = x;
            mod = info(P);
        }
        P = next(P);
    }
    return mod;
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
    //Kamus Lokal
    address P;

    //Algoritme
    P = First(L);
    while(P != NIL){
        if(info(P) == X){
            printf("%p\n", P);
        }
        P = next(P);
    }
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=VA 	Zsebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ){
    //Kamus Lokal
    address adsV;
    address P;

    //Algoritme
    if(!(IsEmptyList(*L))){
        SearchX(*L, V, &adsV);
        if(adsV != NIL){
            Alokasi(&P);
            P->info = VA;
            P->next = next(adsV);
            next(adsV) = P;
        }
        else{
            printf("tidak ditemukan nilai %c", V);
        }
    }
    else{
        printf("List Kosong");
    }

}
