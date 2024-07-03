#include <stdio.h>
#include <stdlib.h>
struct dugum{
int veri;
struct dugum* ileri;
};
typedef struct dugum Dugum;
typedef Dugum* Dugumptr;

Dugumptr yeniDugum(int x){
    Dugumptr dugum=(Dugumptr)malloc(sizeof(Dugum));
    dugum->veri=x;
    dugum->ileri=NULL;
    return dugum;
}

struct liste{
Dugumptr bas;
Dugumptr son;
};
typedef struct liste Liste;
typedef Liste* Listeptr;
Listeptr yeniListe(){
Listeptr liste=(Listeptr)malloc(sizeof(Liste));
liste->bas=NULL;
liste->son=NULL;
}

void listeninBasinaEkle(Listeptr liste,Dugumptr yeni){
    if(liste->bas==NULL)
       liste->son=yeni;
    yeni->ileri=liste->bas;
    liste->bas=yeni;
}






    int listeuzunluk(Listeptr liste){
    Dugumptr temp=liste->bas;
    int sayac;
    while(temp){
        sayac++;
        temp=temp->ileri;

    }
    return sayac;
}




    void yazdir(Listeptr liste){
    Dugumptr temp=liste->bas;
    while(temp){
        printf("%d ->",temp->veri);
        temp=temp->ileri;
    }
}

    void silbastan(Listeptr liste){
    liste->bas=liste->bas->ileri;
    }








