/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 15 September 2023 */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    //kamus lokal
    int i;

    //algoritma
    for(i=1;i<=10;i++){
        (*T).wadah[i] = '#';
        (*T).top = 0;
    }
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top (Tstack T){
    return T.top;
}
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
char infotop (Tstack T){
    return (T.top == 0) ? '#' : T.wadah[T.top];
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    //kamus lokal

    //algoritma
    if(top(T)==0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    //kamus lokal

    //algoritma
    if(top(T)==10){
        return true;
    }
    else{
        return false;
    }
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    //kamus lokal

    //algoritma
    if(isFullStack(*T)){
        printf("\nStack penuh\n");
    }
    else{
        (*T).top += 1;
        (*T).wadah[top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
        //kamus lokal

    //algoritma
    if(isEmptyStack(*T)){
        printf("\nStack kosong\n");
    }
    else{
        (*X) = infotop(*T);
        (*T).wadah[top(*T)] = '#';
        (*T).top -= 1;
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    //kamus lokal
    int i;

    //algoritma
    for(i=1;i<=10;i++){
        printf("%c; ", T.wadah[i]);
    }
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    //kamus lokal
    int i;

    //algoritma
    for(i=1;i<=top(T);i++){
        printf("%c; ", T.wadah[i]);
    }
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */


/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    //kamus lokal
    int i;
    char E;

    //algoritma
    i = 1;
    if(isFullStack(*T)){
        printf("Stack penuh");
    }
    else{
        printf("Memasukan elemen sebanyak %d kali\n", N);
        while((i<=N) && !(isFullStack(*T))){
            printf("[pushN] Masukan elemen : ");
            scanf(" %c", &E);
            push(&(*T), E);
            i++;
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    //kamus lokal
    int i;

    //algoritma
    if(isFullStack(*T)){
        for(i=1;i<=10;i++){
        (*T).wadah[i] = '#';
        (*T).top = 0;
        }
    }
    else{
        push(&(*T), E);
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    //kamus lokal
    char X;

    //algoritma
    if(isFullStack(*T)){
        printf("Stack penuh");
    }
    else{
        if(E == (*T).wadah[top(*T)]){
            pop(&(*T), &X);
        }
        else{
            push(&(*T), E);
        }
    }
}

