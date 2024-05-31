/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 01 September 2023 */
/***********************************/
#include <stdio.h>
#include <math.h>
#include "titik.h"

void makeTitik(Titik *T){
/*{I.S.: -}*/
/*{F.S.: T terdefinisi}*/
/*{proses: mengisi nilai komponen absis dan ordinat T dengan 0}*/

    //Kamus Lokal

    //ALgoritma
    (*T).absis = 0;
    (*T).ordinat = 0;
}

/**********SELEKTOR*/
int getAbsis(Titik T){
/*{mengembalikan nilai komponen absis T}*/
    //Kamus Lokal

    //ALgoritma
    return T.absis;
}

int getOrdinat(Titik T){
/*{mengembalikan nilai komponen ordinat T}*/
    //Kamus Lokal

    //ALgoritma
    return T.ordinat;
}

/*********MUTATOR*/
void setAbsis(Titik *T, int xx){
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.absis=xx}*/
/*{proses: mengisi nilai komponen absis T}*/
    //Kamus Lokal

    //ALgoritma
    (*T).absis = xx;
}

void setOrdinat(Titik *T, int yy){
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.ordinat=yy}*/
/*{proses: mengisi nilai komponen ordinat T}*/
    //Kamus Lokal

    //ALgoritma
    (*T).ordinat = yy;
}

/*********PREDIKAT*/
boolean isOrigin(Titik T){
/*{mengembalikan true jika Titik T ada di persilangan sumbu X dan Y}*/
    //Kamus Lokal

    //ALgoritma
    return (T.absis == 0 && T.ordinat == 0);
}

/*********SUBRUTIN LAIN*/
void geserXY(Titik *T, int dx, int dy){
/*{I.S.: T terdefinisi}*/
/*{F.S.: T bergeser sejauh (dx,dy)}*/
/*{proses: mengubah nilai komponen absis dan ordinat T}*/
    //Kamus Lokal

    //ALgoritma
    (*T).absis += dx;
    (*T).ordinat += dy;
}

void refleksiSumbuX(Titik *T){
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu X }*/
/*{proses: mengubah nilai komponen ordinat T}*/
    //Kamus Lokal

    //ALgoritma
    (*T).ordinat *= -1;
}

void refleksiSumbuY(Titik *T){
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu Y }*/
/*{proses: mengubah nilai komponen absis T}*/
    //Kamus Lokal

    //ALgoritma
    (*T).absis *= -1;
}

int Kuadran(Titik T){
/*{mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4}*/
/*{asumsi: bila titik memotong sumbu, maka nilai 0 dianggap positif}*/
    //Kamus Lokal

    //ALgoritma
    if(T.absis >= 0 && T.ordinat >= 0){
        return 1;
    }else if(T.absis < 0 && T.ordinat >= 0){
        return 2;
    }else if(T.absis < 0 && T.ordinat < 0){
        return 3;
    }else if(T.absis >= 0 && T.ordinat < 0){
        return 4;
    }else{
        return "Origin";
    }
}

float Jarak(Titik T1, Titik T2){
/*{mengembalikan jarak euclidian titik T1 dan T2}*/
/*{asumsi: aplikasikan rumus Pitagoras dan fungsi akar sqrt}*/
    //Kamus lokal

    //Algoritma
    return sqrt(pow(getAbsis(T1)-getAbsis(T2),2)+ pow((getOrdinat(T1)-getOrdinat(T2)),2));
}
