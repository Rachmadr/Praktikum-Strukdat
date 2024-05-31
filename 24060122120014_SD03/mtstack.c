/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 15 September 2023 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

int main()
{	/* kamus main */
	Tstack A; //variabel stack untuk tstack
    Tstack SS; //variabel stack untuk palindrom
	char E; //variabel untuk menyimpan nilai pop
	char kata[100]; //input palindrom
    int p; //panjang kata
    boolean hasil; //hasil pengecekan palindrom
    int i; //counter

	/* algoritma */
	createStack( &A );
    push(&A, 'a');
    push(&A, 'b');
    push(&A, 'c');
    pushZuma(&A, 'c');
    pushBabel1(&A, 'f');
    pushN(&A, 3);
    printStack(A);
    printf("\n");
    viewStack(A);
    printf("\ntop pada index ke-%d", top(A));
    printf("\nisi top = %c", infotop(A));

    printf("\n");
    if(isEmptyStack(A)){
        printf("\nStack kosong\n");
    }
    else{
        printf("\nStack tidak kosong\n");
    }

    pop(&A, &E);
    printStack(A);
    printf("\n");
    viewStack(A);
    printf("\ntop pada index ke-%d", top(A));
    printf("\nisi top = %c", infotop(A));

    if(isFullStack(A)){
        printf("\nStack penuh\n");
    }
    else{
        printf("\nStack tidak penuh\n");
    }


//	Palindorm
    printf("\n\n=====PALINDROM=====\n");
    printf("Masukan kata : ");
	scanf("%s", &kata);
	p = strlen(kata) - 1;
//	printf("%d",p);
	hasil = false;
	if(p > 0){
        createStack(&SS);
        if(p%2==0){
            for(i=0; i<=(p/2)-1;i++){
                push(&SS, kata[i]);
            }
        }
        else{
            for(i=0; i<=(p/2);i++){
                push(&SS, kata[i]);
            }
        }
	}
//	printStack(SS);
//	printf("\n%d\n",i);

    if(p%2==1){
        i--;
    }
    do{
        i++;
        pop(&SS, &E);
//        printf("%c", E);
//        printf("\ni = %d\np = %d\n",i,p);
    }while((E==kata[i]) && (i<p));


//    printf("\n e = %c", E);
//    printf("\n kata[i] = %c", kata[i]);
    if(E==kata[i]){
        hasil = true;
    }

    if(hasil==true){
        printf("'%s' merupakan kata Palindrom", kata);
    }
    else{
        printf("'%s' bukan merupakan kata Palindrom", kata);
    }
    printf("\n===================\n");

	return 0;
}
