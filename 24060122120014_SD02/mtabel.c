#include <stdio.h>
#include "tabel.h"

/* Deskripsi : driver ADT tabel integer*/
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 8 September 2023 */

int main() {
	/*kamus*/
	Tabel A;
	int Pos, Byk;

	/*algoritma*/
	createTable(&A);

    populate1(&A, 4);
	A.size = 9;
	A.wadah[1] = 4;
	A.wadah[2] = 4;
	A.wadah[3] = 7;
	A.wadah[4] = 2;
	A.wadah[5] = 2;
	A.wadah[6] = 3;
	A.wadah[7] = 5;
	A.wadah[8] = 8;
	A.wadah[9] = 1;
	addXTable(&A, 3);
    populate2(&A);

	printTable(A);

	viewTable(A);

	printf("Size tabel = %d\n", getSize(A));

	printf("Wadah kosong dalam tabel = %d\n", countEmpty(A));

	if(isEmptyTable(A)){
        printf("Tabel Kosong\n");
	}else{
        printf("Tabel Tidak Kosong\n");
	}

	if(isFullTable(A)){
        printf("Tabel Penuh\n");
	}else{
        printf("Tabel Tidak Penuh\n");
	}

	searchX1(A, 10, &Pos);
	countX(A, 1, &Byk);
	printf("\nsumEl = %d\n", SumEl(A));
	printf("rata rata = %d \n", AverageEl(A));
    printf("Max = %d\n", getMaxEl(A));
    printf("Min = %d\n", getMinEl(A));

    delXTable(&A, 4);
    delAllXTable(&A, 4);
    printf("%d", Modus(A));
    printf("\n");
    printTable(A);
    printf("Size tabel = %d\n", getSize(A));

	return 0;
}
