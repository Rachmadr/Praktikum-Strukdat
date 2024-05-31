/* File : list3.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Rachmad Rifa'i */
/* Tanggal : 18 November 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"
#include "boolean.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
    /* Kamus Lokal */

    /* Algoritme */
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    /* Kamus Lokal */

    /* Algoritme */
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List3 L){
    /* Kamus Lokal */
    address P;  //penjelajah

    /* Algoritme */
    P = First(L);
    if(P != NIL){   //list tidak kosong
        do{
            printf("%c; ", info(P));
            P = next(P);
        }while(P!=First(L));    //until P = First(L)
        printf("\n");
    }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    /* Kamus Lokal */
    address P;  //penjelajah
    int len;    //banyaknya elemen

    /* Algoritme */
    len = 0;
    P = First(L);
    if(P != NIL){   //list tidak kosong
        do{
            len++;
            P = next(P);
        }while(P != First(L));  //until P = First(L)
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
    /* Kamus Lokal */

    /* Algoritme */
    (*P) = (address) malloc (sizeof(ElmList3));
} //representasi fisik prosedur
//address Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    /* Kamus Lokal */

    /* Algoritme */
    free(*P);
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
    /* Kamus Lokal */
    address P;      //elemen baru
    address last;   //elemen terakhir

    /* Algoritme */
    Alokasi(&P);
    if(P != NIL){   //alokasi berhasil
        info(P) = V;
        if(IsEmptyList(*L)){    //kasus list kosong
            First(*L) = P;
            next(P) = First(*L);
        }
        else{   //kasus list tidak kosong
            //mencari elemen terakhir
            last = First(*L);
            while(next(last) != First(*L)){
                last = next(last);
            }
            //next(last) = First(L)

            next(P) = First(*L);
            First(*L) = P;
            next(last) = First(*L);
        }
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    /* Kamus Lokal */
    address P;      //elemen baru
    address last;   //elemen terakhir

    /* Algoritme */
    Alokasi(&P);
    if(P != NIL){   //alokasi berhasil
        info(P) = V;
        if(IsEmptyList(*L)){    //kasus list kosong
            First(*L) = P;
            next(P) = First(*L);
        }
        else{   //kasus list tidak kosong
            //mencari elemen terakhir
            last = First(*L);
            while(next(last) != First(*L)){
                last = next(last);
            }
            //next(last) = First(L)
            next(last) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    /* Kamus Lokal */
    address P;      //elemen yang dihapus; elemen pertama
    address last;   //elemen terakhir

    /* Algoritme */
    if(!IsEmptyList(*L)){   //kasus tidak kosong
        P = First(*L);
        (*V) = info(P);
        if(NbElm(*L) == 1){ //kasus satu elemen
            First(*L) = NIL;
        }
        else{   //NbElm(L) != 1; kasus lebih dari satu elemen
            //mencari elemen terakhir
            last = First(*L);
            while(next(last) != First(*L)){
                last = next(last);
            }
            //next(last) = First(L)
            First(*L) = next(P);
            next(last) = First(*L);
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    /* Kamus Lokal */
    address last;   //elemen yang dihapus; elemen terakhir
    address prec;   //elemen sebelum elemen terkahir

    /* Algoritme */
    if(!IsEmptyList(*L)){   //kasus list tidak kosong
        last = First(*L);
        (*V) = info(last);
        if(NbElm(*L) == 1){ //kasus satu elemen
            First(*L) = NIL;
        }
        else{   //NbElm != 1; kasus lebih dari satu elemen
            //mencari elemen terakhir dan satu elemen sebelumnya
            last = First(*L);
            while(next(last) != First(*L)){
                prec = last;
                last = next(last);
            }
            //next(last) = First(L)
            next(prec) = First(*L);
        }
        Dealokasi(&last);
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(List3 *L, infotype X, infotype *V){
    /* Kamus Lokal */
    address A;      //X; elemen yang dihapus
    address prec;   //satu elemen sebelum X
    address last;   //elemen terakhir

    /* Algoritme */
    SearchX(*L, X, &A);
    if(A != NIL){   //X ditemukan
        (*V) = info(A);
        if(NbElm(*L)==1){   //kasus satu elemen
            First(*L) = NIL;
        }
        else{   //kasus lebih dari satu elemen
            //mencari elemen terakhir
            last = First(*L);
            while(next(last) != First(*L)){
                last = next(last);
            }
            //next(last) = First(L)
            if(A==First(*L)){   //kasus X di elemen pertama
                First(*L) = next(A);
                next(last) = First(*L);
            }
            else{   //A != First(L)
                //mencari satu elemen sebelum X
                prec = First(*L);
                do{
                    prec = next(prec);
                }while(next(prec) != A); //until next(prec) = A
                if(next(A) == First(*L)){   //kasus X elemen terakhir
                    next(prec) = First(*L);
                }
                else{   //kasus X ditengah
                    next(prec) = next(A);
                }
            }
        }
        Dealokasi(&A);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
    /* Kamus Lokal */
    address P;  //penjelajah

    /* Algoritme */
    (*A) = NIL;
    P = First(L);
    do{
        if(info(P) == X){
            (*A) = P;
        }
        P = next(P);
    }while(P!=First(L) && (*A)==NIL); //until P = First(L) AND A != NIL
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    /* Kamus Lokal */
    address A;  //X

    /* Algoritme */
    if(!IsEmptyList(*L)){   //list tidak kosong
        SearchX((*L),X,&A);
        if(A != NIL){
            info(A) = Y;
        }
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
    /* Kamus Lokal */
    address P;  //penjelajah
    List3 LB;   //list bantu

    /* Algoritme */
    if(!(IsEmptyList(*L))){ //list tidak kosong
        if(NbElm(*L) > 1){
            CreateList(&LB);
            P = First(*L);
            do{
                InsertVFirst(&LB, info(P));
                P = next(P);
            }while(P != First(*L)); //until P = First(L)
            (*L) = LB;
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    /* Kamus Lokal */
    address P;  //penjelajah
    int cx;     //jumlah X

    /* Algoritme */
    cx = 0;
    P = First(L);
    do{
        if(info(P) == X){
            cx++;
        }
        P = next(P);
    }while(P != First(L));  //until P = First(L)
    return cx;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    /* Kamus Lokal */
    int cx;     //jumlah X
    float freq; //frekuensi x

    /* Algoritme */
    freq = 0;
    if(!(IsEmptyList(L))){
        cx = CountX(L, X);
        freq = cx/(float)NbElm(L);
    }
    return freq;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    /* Kamus Lokal */
    address P;  //penjelajah
    int x;      //banyak x
    int countx; //banyak x sebelumnya
    char mod;   //modus

    /* Algoritme */
    P = First(L);
    mod = NIL;
    do{
        x = CountX(L, info(P));
        if (x > countx){
            countx = x;
            mod = info(P);
        }
        P = next(P);
    }while(P != First(L));  //until P = First(L)
    return mod;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    /* Kamus Lokal */
    address P;  //penjelajah
    int cv;     //jumlah huruf vokal

    /* Algoritme */
    P = First(L);
    cv = 0;
    do{
        if(info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o'){
            cv++;
        }
        P = next(P);
    }while(P != First(L));  //until P = First(L)
    return cv;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    /* Kamus Lokal */
    address P;  //penjelajah
    int cng;    //jumlah n yang diikuti g

    /* Algoritme */
    P = First(L);
    cng = 0;
    do{
        if(info(P) == 'n' && info(next(P)) == 'g'){
            cng++;
        }
        P = next(P);
    }while(P != First(L));  //until P = First(L)
    return cng;
}

/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    /* Kamus Lokal */
    address P;  //elemen baru
    address A;  //X

    /* Algoritme */
    SearchX(*L, X, &A);
    if(A != NIL){   //X ditemukan
        Alokasi(&P);
        if(P != NIL){   //Alokasi berhasil
            info(P) = V;
            if(next(A) == First(*L)){   //Kasus satu elemen dan X pada elemen terakhir
                next(A) = P;
                next(P) = First(*L);
            }
            else{   //(next(A) != First(L)); Kasus X ditengah list
                next(P) = next(A);
                next(A) = P;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    /* Kamus Lokal */
    address P;      //elemen baru
    address A;      //X
    address prec;   //elemen sebelum X
    address last;   //elemen terakhir

    /* Algoritme */
    SearchX(*L, X, &A);
    if(A != NIL){   //X ditemukan
        Alokasi(&P);
        if(P != NIL){   //alokasi berhasil
            info(P) = V;
            //mencari last
            last = First(*L);
            while(next(last) != First(*L)){
                last = next(last);
            }
            //next(last) = First(L)
            if(A == First(*L)){ //kasus X elemen pertama
                next(P) = A;
                First(*L) = P;
                next(last) = First(*L);
            }
            else{   //A != First(L)
                prec = First(*L);
                do{
                    prec = next(prec);
                }while(next(prec) != A);    //until next(prec) = A
                next(prec) = P;
                next(P) = A;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    /* Kamus Lokal */
    address del;    //elemen yang dihapus
    address A;      //X

    /* Algoritme */
    SearchX(*L, X, &A);
    if(A != NIL){   //X ditemukan
        if(NbElm(*L) > 1){  //list harus berisi lebih dari satu elemen
            del = next(A);
            (*V) = info(del);
            if(del == First(*L)){   //elemen yang dihapus adalah First(L)
                First(*L) = next(del);
                next(A) = First(*L);
            }
            else{   //del != First(L)
                if(next(del) == First(*L)){ //yang dihapus elemen terakhir
                    next(A) = First(*L);
                }
                else{   //next(del) != First(L); yang dihapus ditengah
                    next(A) = next(del);
                }
            }
            Dealokasi(&del);
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    /* Kamus Lokal */
    address del;    //elemen yang dihapus
    address A;      //X
    address prec;   //elemen sebelum X
    address prec2;  //elemen sebelum dari sebelum X
    address last;   //elemen terakhir

    /* Algoritme */
    SearchX(*L, X, &A);
    if(A != NIL){   //X ditemukan
        if(NbElm(*L) > 1 && A != First(*L)){    //elemen harus lebih dari satu dan X bukan First(L)
            prec = First(*L);
            do{
                prec = next(prec);
            }while(next(prec) != A); //until next(prec) = A
            del = prec;
            (*V) = info(del);
            if(del == First(*L)){   //prev(X) = First(L)
                last = First(*L);
                    while(next(last) != First(*L)){
                    last = next(last);
                }
                //next(last) = First(L)
                First(*L) = A;
                next(last) = First(*L);
            }
            else{
                prec2 = First(*L);
                do{
                    prec2 = next(prec2);
                }while(next(prec2) != prec);    //next(prec2) = prec
                next(prec2) = next(prec);
            }
            Dealokasi(&del);
        }
    }
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,2) menampilkan angka 1,6,9 */
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,8) menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
    /* Kamus Lokal */
    address P;  //penjelajah
    int idx;    //index

    /* Algoritme */
    idx = 0;
    P = First(L);
    do{
        idx++;
        if (info(P) == X){
            printf("%d; ", idx);
        }
        P = next(P);
    }while(P!=First(L));    //until P = First(L)
}
