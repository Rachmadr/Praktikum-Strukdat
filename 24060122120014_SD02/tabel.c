#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : realisasi body modul Tabel*/
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 8 September 2023 */

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i=1; i<=10; i++){
        (*T).wadah[i] = -999;
    }
    (*T).size = 0;
}


/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=1; i<=10; i++){
        printf("Elemen ke-%d = %d\n", i, T.wadah[i]);
    }
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    //Kamus lokal
    int i;

    //Algoritma
    if(T.size > 0){
        for(i=1;i<=10;i++){
            if(T.wadah[i]>-999){
                printf("Elemen ke-%d = %d\n", i, T.wadah[i]);
            }
        }
    }else{
        printf("Tabel Kosong\n");
    }
}


/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    //Kamus lokal

    //Algoritma
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    //Kamus lokal

    //Algoritma
    return 10 - T.size;
}


/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    //Kamus lokal

    //Algoritma
    if(T.size == 0){
        return true;
    }else{
        return false;
    }
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    if(T.size == 10){
        return true;
    }else{
        return false;
    }
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    //Kamus lokal
    int i;
    int x;

    //Algoritma
    if(N>=1 && N<=10){
        (*T).size = N;
        for(i=1; i<=N; i++){
            scanf("%d", &x);
            if(x>0){
                (*T).wadah[i]=x;
                x = 0;
            }else{
                printf("Tidak boleh <= 0\n");
                scanf("%d", &(*T).wadah[i]);
            }
        }
    }else{
        printf("N tidak dalam rentang 1 sampai 10\n");
    }
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
    //Kamus lokal
    int i;

    //Algoritma
    (*Pos) = 0;
    for(i=1;i<=T.size;i++){
        if(X==T.wadah[i]){
            (*Pos) = i;
            printf("%d\n", (*Pos));
        }
    }
    if((*Pos)==0){
        (*Pos) = -999;
        printf("%d\n", (*Pos));
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    //Kamus lokal
    int i;

    //Algoritma
    (*Byk) = 0;
    for(i=1; i<=T.size; i++){
        if(X == T.wadah[i]){
            (*Byk) += 1;
        }
    }
    printf("%d", (*Byk));
}

/*function SumEl ( T:Tabel ) -> integer
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
    //Kamus lokal
    int sum;
    int i;

    //ALgoritma
    sum = 0;
    if(isEmptyTable(T)){
        return sum;
    }else{
        for(i=1;i<=T.size;i++){
            if(T.wadah[i]>-999){
                sum += T.wadah[i];
            }
        }
    }
    return sum;
}

/*function AverageEl ( T:Tabel ) -> integer
	{mengembalikan nilai rata-rata elemen pengisi T } */
int AverageEl (Tabel T){
    //Kamus lokal
    float avg;

    //Algoritma
    avg = 0;
    if(isEmptyTable(T)){
        return avg;
    }else{
        avg = SumEl(T)/T.size;
    }
    return avg;
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
    //Kamus lokal
    int max;
    int i;

    //Algoritma
    max = 0;
    if(isEmptyTable(T)){
        return max;
    }else{
        for(i=1;i<=T.size;i++){
            if(T.wadah[i]>max){
                max = T.wadah[i];
            }
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){
    //Kamus lokal
    int min;
    int i;

    //Algoritma
    min = T.wadah[1];
    if(isEmptyTable(T)){
        return min;
    }else{
        for(i=2;i<=T.size;i++){
            if(T.wadah[i]<min){
                min = T.wadah[i];
            }
        }
    }
    return min;
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
    //Kamus lokal
    int X, i;

    //Algoritma
    i = (*T).size+1;
    if(isFullTable(*T)){
        printf("Tabel Penuh");
    }else{
        while(i<=10){
            scanf("%d",&X);
            if(X>0){
                (*T).wadah[i] = X;
                (*T).size += 1;
                i++;
            }else{
                i = 100;
            }
            X = 0;
        }
    }
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    //Kamus Lokal

    //Algoritma
    if(isFullTable(*T)){
        printf("Tabel Penuh\n");
    }else{
        (*T).wadah[(*T).size+1] = X;
        (*T).size += 1;
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
    //Kamus lokal
    int i;
    int j;
    int counter;

    //Algoritma
    counter = 1;
    if (isEmptyTable(*T)){
        printf("Tabel Kosong");
    }else{
        for (i=1;i<=(*T).size;i++){
            if (X == (*T).wadah[i] && counter>0){
                counter -= 1;
                (*T).wadah[i] = (*T).wadah[i+1];
                for(j=i+1;j<(*T).size;j++){
                    (*T).wadah[j] = (*T).wadah[j+1];
                }
            }
        }
        (*T).wadah[(*T).size] = -999;
        (*T).size -= 1;
    }
}


/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    //Kamus lokal
    int i;
    int j;
    //int counter;

    //Algoritma
    //counter = 0;
    i = 1;
    if (isEmptyTable(*T)){
        printf("Tabel Kosong");
    }else{
        while(i<=(*T).size){
            if((*T).wadah[i]==X){
                //counter += 1;
                //printTable(*T);
                for(j=i;j<=(*T).size;j++){
                    (*T).wadah[j] = (*T).wadah[j+1];
                }
                (*T).wadah[(*T).size] = -999;
                (*T).size -= 1;
                i=0;
            }
            i++;
        }
//        printf("c = %d\n", counter);
    }
}

/*function Modus ( T:Tabel ) -> integer
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
    //kamus lokal
    int i;
    int count[100];
    int max;
    int counter;

    //algoritma
    for(i=1;i<=100;i++){
        count[i] = 0;
    }
    max = 0;
    counter = 0;

    for(i=1;i<=T.size;i++){
        count[T.wadah[i]] += 1;
    }

    for(i=1;i<=T.size;i++){
        if(count[T.wadah[i]]>max){
            max = count[T.wadah[i]];
            counter = T.wadah[i];
        }
    }
    return counter;
}



#endif
