/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060122120014/Rachmad Rifa'i */
/* Tanggal   : 29 September 2023 */
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/
void createQueue2(tqueue2 *Q){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=1;i<=5;i++){
        (*Q).wadah[i]='#';
    }
    (*Q).head=0;
    (*Q).tail=0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[head2(Q)];
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[tail2(Q)];
}

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return tail2(Q)==0 && head2(Q)==0;
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return tail2(Q)==5 && head2(Q)==1;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return tail2(Q)==head2(Q);
}


/*function sizeQueue2(Q:tQueue2)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    if(isEmptyQueue2(Q)){
        return 0;
    }
    else{
        return tail2(Q)-head2(Q)+1;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=1;i<=5-1;i++){
        printf("%c; ", Q.wadah[i]);
    }
    printf("%c", Q.wadah[5]);
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=head2(Q);i<=tail2(Q)-1;i++){
        printf("%c; ", Q.wadah[i]);
    }
    printf("%c", Q.wadah[tail2(Q)]);
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return tail2(Q)==5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
    //Kamus lokal
    int i;

    //Algoritma
    if(isTailStop(*Q) && head2(*Q)>1){
        for(i=head2(*Q);i<=tail2(*Q);i++){
            (*Q).wadah[i-head2(*Q)+1] = (*Q).wadah[i];
            (*Q).wadah[i]='#';
        }
        (*Q).tail = sizeQueue2(*Q);
        (*Q).head = 1;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas,
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    //Kamus lokal

    //Algoritma
    if(isFullQueue2(*Q)){
        printf("\nAntrian penuh\n");
    }
    else{
        if(isTailStop(*Q)){
            resetHead(&(*Q));
        }
        if(isEmptyQueue2(*Q)){
            (*Q).head++;
        }
        (*Q).tail++;
        (*Q).wadah[tail2(*Q)] = E;
    }
}

/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen,
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    //Kamus lokal

    //Algoritma
    if(isEmptyQueue2(*Q)){
        (*E) = '@';
        printf("Antrian kosong");
    }
    else{
        (*E) = infoHead2(*Q);
        (*Q).wadah[head2(*Q)]='#';
        if(isOneElement2(*Q)){
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else{
            (*Q).head++;
        }
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas,
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    //Kamus lokal
    int i;
    char E;

    //Algoritma
    if(isFullQueue2(*Q)){
        printf("Antrian penuh");
    }
    else{
        if((N<=5-sizeQueue2(*Q))&&N>0){
            for(i=1;i<=N;i++){
                if(isTailStop(*Q)){
                    resetHead(&(*Q));
                }
                printf("\nMasukkan elemen : ");
                scanf(" %c", &E);
                enqueue2(&(*Q),E);
            }
        }
        else{
            printf("N melebihi batas");
        }
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2){
    //Kamus lokal
    int i;
    int j;
    int h1,h2;
    int counter;

    //Algoritma
    counter=0;
    h1 = head2(Q1);
    h2 = head2(Q2);
    if(isEmptyQueue2(Q1) || isEmptyQueue2(Q2)){
        return false;
    }
    else{
        if(sizeQueue2(Q1)!=sizeQueue2(Q2)){
            return false;
        }
        else{
            for(i=1;i<=5;i++){
                if(Q1.wadah[h1]==Q2.wadah[h2] && Q1.wadah[h1]!='#' && Q2.wadah[h2]!='#'){
                    counter++;
                }
                h1++;
                h2++;
//                for(j=head2(Q2);j<=tail2(Q2);j++){
//                    if(Q1.wadah[i]==Q2.wadah[j]){
//                        counter++;
//                    }
//                }
            }
        }
        printf("\ncounter = %d\n",counter);
        if(counter==sizeQueue2(Q1)){
            return true;
        }
        else{
            return false;
        }
    }

}
