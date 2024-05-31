/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 01 September 2023 */
/***********************************/
#include <stdio.h>
#include <math.h>
#include "titik.h"

int main() {
	//Kamus lokal
	Titik A;
	Titik B;

	//Algoritma
	printf("Halo, ini driver modul Titik \n");

	printf("\nMembuat titik \n");

	makeTitik(&A);
	printf("\nabsis = %d", getAbsis(A));
	printf("\nordinat = %d", getOrdinat(A));


	printf("\nMenentukan absis dan ordinat titik \n");

	setAbsis(&A,3);
	setOrdinat(&A,4);
    printf("\nTitik setelah dilakukan set (%d, %d)\n", getAbsis(A),getOrdinat(A));


    printf("\nMengecek apakah titik merupakan titik origin atau bukan\n");

	if(isOrigin(A)){
        printf("\nTitik merupakan titik origin\n");
	}else{
        printf("\nTitik bukan merupakan titik origin\n");
    }


    printf("\nMenggeser titik \n");

    geserXY(&A, 5, 4);
    printf("\nTitik setelah dilakukan penggeseran (%d, %d)\n", getAbsis(A),getOrdinat(A));


	refleksiSumbuX(&A);
	printf("\nRefleksi pada sumbu X (%d, %d)\n", getAbsis(A),getOrdinat(A));

	refleksiSumbuY(&A);
	printf("\nRefleksi pada sumbu Y (%d, %d)\n", getAbsis(A),getOrdinat(A));

	printf("\nTitik pada kuadran %d\n",Kuadran(A));


	makeTitik(&B);
    setAbsis(&B,4);
	setOrdinat(&B,3);
	printf("\nTitik A (%d, %d)", getAbsis(A),getOrdinat(A));
	printf("\nTitik B (%d, %d)", getAbsis(B),getOrdinat(B));

	printf("\nJarak antara titik A dan titik B adalah %f\n", Jarak(A,B));
	return 0;
}
