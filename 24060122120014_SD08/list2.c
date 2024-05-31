/* File : list2.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Rachmad Rifa'i */
/* Tanggal : 10 November 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include "boolean.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:list2)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList (list2 *L){
    //Kamus lokal

    //Algoritme
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:list2) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (list2 L){
    //Kamus lokal

    //Algoritme
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:list2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(list2 L){
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
    printf("\n");
}

/*function NbElm(L:list2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(list2 L){
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
    (*P) = (address) malloc (sizeof(ElmList2));
} //representasi fisik prosedur
//address Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //Kamus lokal

    //Algoritme
    free(*P);
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(list2 *L, infotype V ){
    //Kamus lokal
    address P;

    //Algoritme
    Alokasi(&P);
    if(P != NIL){
        info(P) = V;
        prev(P) = NIL;
        if(IsEmptyList(*L)){
            next(P) = NIL;
        }
        else{
            next(P) = First(*L);
            prev(First(*L)) = P;
        }
        First(*L) = P;
    }
}

/*Procedure InsertVLast(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(list2 *L, infotype V ){
    //Kamus lokal
    address P;
    address last;

    //Algoritme
    Alokasi(&P);
    if(P != NIL){
        info(P) = V;
        next(P) = NIL;
        if(IsEmptyList(*L)){
            prev(P) = NIL;
            First(*L) = P;
        }
        else{
            last = First(*L);
            while(next(last) != NIL){
                last = next(last);
            }
            prev(P) = last;
            next(last) = P;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(list2 *L, infotype *V){
    //Kamus lokal
    address P;

    //Algoritme
    P = First(*L);
    if(P != NIL){
        (*V) = info(P);
        First(*L) = next(P);
        if(next(P) != NIL){
            prev(First(*L)) = NIL;
        }
        Dealokasi(P);
    }
}

/*Procedure DeleteVLast(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(list2 *L, infotype *V){
    //Kamus lokal
    address last;

    //Algoritme
    last = First(*L);
    if(last != NIL){
        while(next(last) != NIL){
            last = next(last);
        }
        (*V) = info(last);
        if(prev(last) == NIL){
            First(*L) = NIL;
        }
        else{
            next(prev(last)) = NIL;
        }
        Dealokasi(&last);
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(list2 *L, infotype X, infotype *V){
    //Kamus lokal
    address A;

    //Algoritme
    SearchX((*L), X, &A);
    if(A != NIL){
        (*V) = info(A);
        if(NbElm(*L) == 1){
            First(*L) = NIL;
        }
        else{
            if(next(A) == NIL){
                next(prev(A)) = NIL;
            }
            else{
                if(prev(A) == NIL){
                    prev(next(A)) = NIL;
                    First(*L) = next(A);
                }
                else{
                    next(prev(A)) = next(A);
                    prev(next(A)) = prev(A);
                }
            }
        }
        Dealokasi(&A);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:list2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(list2 L, infotype X, address *A){
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
/*Procedure UpdateX(input/output L:list2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(list2 *L, infotype X, infotype Y){
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

/*Procedure Invers(input/output L:list2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(list2 *L){
    //Kamus Lokal
    address P;
    list2 LB;

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
/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(list2 *L, infotype X, infotype V){
    //Kamus lokal
    address P;
    address A;

    //Algoritme
    if(First(*L) != NIL){
        SearchX((*L), X, &A);
        if(A != NIL){
            Alokasi(&P);
            if(P != NIL){
                info(P) = V;
                prev(P) = A;
                if(next(A) == NIL){
                    next(P) = NIL;
                }
                else{
                    next(P) = next(A);
                    prev(next(A)) = P;
                }
                next(A) = P;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(list2 *L, infotype X, infotype V){
    //Kamus lokal
    address P;
    address A;

    //Algoritme
    if(First(*L) != NIL){
        SearchX((*L), X, &A);
        if(A != NIL){
            Alokasi(&P);
            if(P != NIL){
                info(P) = V;
                next(P) = A;
                if(prev(A) == NIL){
                    prev(P) = NIL;
                    First(*L) = P;
                }
                else{
                    prev(P) = prev(A);
                    next(prev(A)) = P;
                }
                prev(A) = P;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(list2 *L, infotype X, infotype *V){
    //Kamus lokal
    address A;
    address P;

    //Algoritme
    if(First(*L) != NIL){
        SearchX((*L), X, &A);
        if(A != NIL){
            if(next(A) != NIL){
                P = next(A);
                (*V) = info(P);
                if(next(P) == NIL){
                    next(prev(P)) = NIL;
                }
                else{
                    next(prev(P)) = next(P);
                    prev(next(P)) = prev(P);
                }
                Dealokasi(&P);
            }
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(list2 *L, infotype X, infotype *V){
    //Kamus lokal
    address A;
    address P;

    //Algoritme
    if(First(*L) != NIL){
        SearchX((*L), X, &A);
        if(A != NIL){
            if(prev(A) != NIL){
                P = prev(A);
                (*V) = info(P);
                if(prev(P) == NIL){
                    prev(next(P)) = NIL;
                    First(*L) = next(P);
                }
                else{
                    prev(next(P)) = prev(P);
                    next(prev(P)) = next(P);
                }
                Dealokasi(&P);
            }
        }
    }
}

/*function CountX(L:list2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(list2 L, infotype X){
    //Kamus Lokal
    address P;
    int cx;

    //Algoritme
    P = First(L);
    cx = 0;
    while(P != NIL){
        if(info(P) == X){
            cx++;
        }
        P = next(P);
    }
    return cx;
}

/*function FrekuensiX(L:list2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(list2 L, infotype X){
    //Kamus Lokal
    int cx;
    float freq;

    //Algoritme
    freq = 0;
    if(!(IsEmptyList(L))){
        cx = CountX(L, X);
        freq = cx/(float)NbElm(L);
    }
    return freq;
}

/*function Modus(L:list2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(list2 L){
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

/*Procedure SearchAllX(input L:list2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,2) menampilkan angka 1,6,9 */
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,8) menampilkan angka 0 */
void SearchAllX(list2 L, infotype X) {
    //Kamus lokal
    address P;
    int idx;

    //Algoritme
    if (!IsEmptyList(L)) {
        idx = 0;
        P = First(L);
        while (P != NIL) {
            idx++;
            if (info(P) == X) {
                printf("%d; ", idx);
            }
            P = next(P);
        }
    }
}
