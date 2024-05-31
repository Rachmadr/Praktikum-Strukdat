/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120014 & Rachmad Rifa'i */
/* Tanggal : 01 Desember 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N){
    /* Kamus Lokal */

    /* Algoritma */
    if(!IsEmptyTree(P)){
        if(N == 1){
            printf("%c; ", info(P));
        }
        else{
            PrintLevel(left(P), N-1);
            PrintLevel(right(P), N-1);
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca }*/
bintree BuildBalanceTree(int n){
    /* Kamus Lokal */
    infotype X;
    bintree P;

    /* Algoritma */
    if(n == 0){
        P = NIL;
    }
    else if(n == 1){
        printf("Masukkan node : ");
        scanf(" %c", &X);
        P = Tree(X, NIL, NIL);
    }
    else if(n > 1){
        printf("Masukkan node : ");
        scanf(" %c", &X);
        P = Tree(X, BuildBalanceTree(n/2), BuildBalanceTree((n-1)/2));
    }
    return P;
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    /* Kamus Lokal */

    /* Algoritma */
    return abs(NbElm(left(P)) - NbElm(right(P))) <= 1;
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    //printf("a");
    if(IsEmptyTree(*P)){
        //printf("c\n");
        *P = Tree(X,NIL,NIL);
    }
    else{
        //printf("b");
        if(IsUnerRight(*P) || IsDaun(*P)){
            left(*P) = Tree(X,NIL,NIL);
        }
        else{
            AddDaunTerkiri(&left(*P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri){
    /* Kamus Lokal */

    /* Algoritma */
    if((*P) != NIL){
        if(IsDaun(*P)){
            if(info(*P) == X){
                if(Kiri){
                    left(*P) = Tree(Y,NIL,NIL);
                }
                else{
                    right(*P) = Tree(Y,NIL,NIL);
                }
            }
        }
        else{
            AddDaun(&left(*P), X, Y, Kiri);
            AddDaun(&right(*P), X, Y, Kiri);
        }
    }

}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
//ASUMSI JIKA DAUN AKAN MENAMBAHKAN DI KIRI
void InsertX(bintree *P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    if(!SearchX(*P, X)){
        if(IsEmptyTree(*P)){
            *P = Tree(X,NIL,NIL);
        }
        else if(IsDaun(*P)){
            left(*P) = Tree(X,NIL,NIL);
        }
        else{
            InsertX(&left(*P),X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X){
    /* Kamus Lokal */

    /* Algoritma */
    if(*P != NIL){
        if(IsDaun(*P)){
            (*X) = info(*P);
            Dealokasi(&(*P));
            (*P) = NIL;
        }
        else if(left(*P)!=NIL&&right(*P)!=NIL){
                if(NbElm(left(*P)) >= NbElm(right(*P))){
                    DelDaunTerkiri(&left(*P), &(*X));
                }
                else{
                    DelDaunTerkiri(&right(*P), &(*X));
                }
        }
        else{
            if(IsUnerLeft(*P)){
                DelDaunTerkiri(&left(*P), &(*X));
            }
            else if(IsUnerRight(*P)){
                DelDaunTerkiri(&right(*P), &(*X));
            }
        }
    }

}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    if(*P != NIL){
        if(IsDaun(*P) && info(*P) == X){
            (*P) = NIL;
        }
        else{
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
    /* Kamus Lokal */
    bintree Q;
    infotype temp;

    /* Algoritma */
    if(!IsEmptyTree(*P)){
        if(info(*P) == X){
            if(IsDaun(*P)){
                (*P) = NIL;
            }
            else if(IsUnerLeft(*P)){
                Q = (*P);
                (*P) = left(*P);
                Dealokasi(Q);
            }
            else if(IsUnerRight(*P)){\
                Q = (*P);
                (*P) = right(*P);
                Dealokasi(Q);
            }
            else{
                DelDaunTerkiri(&right(*P), &temp);
                info(*P) = temp;
            }
        }
        else{
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    /* Kamus Lokal */

    /* Algoritma */
    if(!IsEmptyTree(*P)){
        if(info(*P) == X){
            info(*P) = Y;
        }
        UpdateAllX(&left(*P),X,Y);
        UpdateAllX(&right(*P),X,Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
char maxTree(bintree P){
    /* Kamus Lokal */
    char max;
    char leftmax;
    char rightmax;

    /* Algoritma */
    if(IsEmptyTree(P)){
        return max;
    }
    else{
        max = info(P);
        leftmax = maxTree(left(P));
        rightmax = maxTree(right(P));
        if(leftmax > max){
            max = leftmax;
        }
        if(rightmax > max){
            max = rightmax;
        }
        return max;
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
char minTree(bintree P){
    /* Kamus Lokal */
    char min;
    char leftmin;
    char rightmin;

    /* Algoritma */
    if(IsEmptyTree(P)){
        return '\0';
    }
    else{
        min = info(P);
        leftmin = minTree(left(P));
        rightmin = minTree(right(P));
        if(leftmin != '\0' && leftmin < min){
            min = leftmin;
        }
        if(rightmin != '\0' && rightmin < min){
            min = rightmin;
        }
        return min;

    }

}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
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

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree *P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
    if(IsEmptyTree(*P)){
        *P = Tree(X,NIL,NIL);
    }
    else{
        if(X < info(*P)){
            InsSearch(&left(*P),X);
        }
        else if(X > info(*P)){
            InsSearch(&right(*P),X);
        }
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
    /* Kamus Lokal */

    /* Algoritma */
}
