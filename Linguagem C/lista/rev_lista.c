#include <stdio.h>
#include <stdlib.h>

typedef struct ListaNo{
    int item;
    struct ListaNo* ant;
    struct ListaNo* prox;
}Lista;

typedef struct Litem{
    Lista* prim;
    Lista* ult;
}Litem;

Litem* criar(void){ //Inicia uma lista
    Litem* l= (Litem*) malloc(sizeof(Litem));
    l->prim= NULL;
    l->ult= NULL;
    return l;
};

void insereIn(Litem* l, int n);
void insereFim(Litem* l, int n);
void removeItem(Litem* l, int n);
void liberar_lista(Litem* l);
void imprime(Litem* l);

int main(){
    Litem* l;
    l= criar();

    insereFim(l, 1);
    insereFim(l, 2);
    insereFim(l, 3);
    insereFim(l, 4);

    imprime(l);

    removeItem(l, 3);
    imprime(l);

    liberar_lista(l);
}

void insereIn(Litem* l, int n){
    Lista* novo= (Lista*) malloc(sizeof(Lista));
    novo->item= n;
    novo->ant= NULL;
    novo->prox= l->prim;
    l->prim= novo;
    if(l->ult == NULL){
        l->ult= novo;}
};

void insereFim(Litem* l, int n){
    if(l->prim == NULL){
        insereIn(l,n);}
    else{
        Lista* novo= (Lista*) malloc(sizeof(Lista));
        novo->item= n;
        novo->prox= NULL;
        novo->ant= l->ult;
        l->ult->prox= novo;
        l->ult= novo;}
};

void removeItem(Litem* l, int n){
    Lista* aux= l->prim;
    Lista* ante= NULL;
    while(aux != NULL && aux->item != n){
        ante= aux;
        aux= aux->prox;}
    
    if(aux == NULL){
        printf("O item nao esta na lista");}
    else{
        if(ante == NULL){
            l->prim= aux->prox;}
        else{
            ante= aux->prox;}
        free(aux);}
}


void imprime(Litem* l){
    if(l->prim == NULL){
        printf("lista vazia\n");}
    else{
        for(Lista* aux= l->prim; aux != NULL; aux= aux->prox){
        printf("%d ", aux->item);}
        printf("\n");}
}

void liberar_lista(Litem* l){
    Lista* aux= l->prim;
    while(aux != NULL){
        Lista* temp= aux->prox;
        free(aux);
        aux= temp;
    }
    l->prim= NULL;
    l->ult= NULL;
    imprime(l);
    free(l);
}