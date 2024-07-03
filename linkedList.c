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
void listeninSonunaEkle(Listeptr liste,Dugumptr yeni){
    if(liste->bas==NULL)
        liste->son=yeni;
    else
        liste->son->ileri=yeni;
    liste->son=yeni;
}



    void arayaElemanEkle(Dugumptr onceki,Dugumptr yeni){
    yeni->ileri=onceki->ileri;
    onceki->ileri=yeni;
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



   void silaradan(Listeptr liste, Dugumptr node) {
    Dugumptr temp = liste->bas;
    Dugumptr once = NULL;

    // Silinecek düðümün öncesini bul
    while (temp->ileri != node) {
        once = temp;
        temp = temp->ileri;
    }

    // Silinecek düðümü listeden çýkar
    once->ileri = node->ileri;
    free(node);
}


void sondanSil(Listeptr liste){
Dugumptr temp,once;
temp=liste->bas;
once=NULL;
while(temp->ileri!=NULL){
once=temp;
temp=temp->ileri;}
if(once==NULL){
    liste->bas=NULL;}
    else{
        once->ileri=NULL;}
liste->son=once;
}
    int main()
    {
    Dugumptr d1,d2,d3,d4,d5;
    d1=yeniDugum(20);
    d2=yeniDugum(30);
    d3=yeniDugum(40);
    d4=yeniDugum(50);
    d5=yeniDugum(60);
    Listeptr liste1;
    liste1=yeniListe();
    listeninBasinaEkle(liste1,d1);
    listeninBasinaEkle(liste1,d2);
    listeninBasinaEkle(liste1,d3);
    listeninBasinaEkle(liste1,d4);
    listeninBasinaEkle(liste1,d5);
    yazdir(liste1);
    listeBasiSil(liste1);
    yazdir(liste1);
    listeAradanSil(liste1,d4);
    yazdir(liste1);

    printf("Hello world!\n");
    return 0;
}
