/* Program   : tqueue.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 22 September 2023 */
/***********************************/


#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '$', head=tail=0 }*/
void createQueue(tqueue *Q){
    //Kamus lokal
    int i;

    //Algoritma
    (*Q).head=0;
    (*Q).tail=0;
    for(i=1;i<=5;i++){
        (*Q).wadah[i] = '$';
    }
}

int Head(tqueue Q){
    //Kamus lokal

    //Algoritma
    return Q.head;
}

int Tail(tqueue Q){
    //Kamus lokal

    //Algoritma
    return Q.tail;
}

/*function infoHead(Q:tQueue)-> character
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q){
    //Kamus lokal

    //Algoritma
    if(isEmptyQueue(Q)){
        return ' ';
    }
    else{
        return Q.wadah[Head(Q)];
    }
}



/*function infoTail(Q:tQueue)-> character
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q){
    //Kamus lokal

    //Algoritma
    if(isEmptyQueue(Q)){
        return ' ';
    }
    else{
        return Q.wadah[Tail(Q)];
    }
}

/*function sizeQueue(Q:tQueue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    //Kamus lokal

    //Algoritma
    return Tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=1;i<=5-1;i++){
        printf("%c; ", Q.wadah[i]);
    }
    printf("%c", Q.wadah[5]);
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=1;i<=Tail(Q)-1;i++){
        printf("%c; ", Q.wadah[i]);
    }
    printf("%c", Q.wadah[Tail(Q)]);
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    return Tail(Q)==0;
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    return Tail(Q)==5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    return Tail(Q)==1;
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
    //Kamus lokal

    //Algoritma
    if(isFullQueue(*Q)){
        printf("Q penuh");
    }
    else{
        if(isEmptyQueue(*Q)){
            (*Q).head++;
        }
        (*Q).tail++;
        (*Q).wadah[Tail(*Q)] = E;
    }
}

/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead(Q) atau E=' ' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
    //Kamus lokal
    int i;

    //Algoritma
    if(isEmptyQueue(*Q)){
        printf("Q kosong");
    }
    else{
        (*E) = infoHead(*Q);
        if(isOneElement(*Q)){
            (*Q).head--;
        }
        else{
            for(i=1;i<=Tail(*Q)-1;i++){
                (*Q).wadah[i] = (*Q).wadah[i+1];
            }
        }
        (*Q).wadah[Tail(*Q)] = '$';
        (*Q).tail--;
    }
}

/*tambahan, dikerjakan bila cukup waktu */


/*function maxlength(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int maxlength(tqueue Q1, tqueue Q2){
    if(sizeQueue(Q1)>=sizeQueue(Q2)){
        return sizeQueue(Q1);
    }
    else{
        return sizeQueue(Q2);
    }
}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char E){
    //Kamus lokal

    //Algoritma
    if(sizeQueue(*Q1)<=sizeQueue(*Q2)){
        enqueue(&(*Q1),E);
    }
    else{
        enqueue(&(*Q2),E);
    }
}

/*procedure deQueue2( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2 atau E=' ' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *E){
    //Kamus lokal

    //Algoritma
    if(sizeQueue(*Q1)>=sizeQueue(*Q2)){
        dequeue(&(*Q1),&(*E));
    }
    else{
        dequeue(&(*Q2),&(*E));
    }
}
