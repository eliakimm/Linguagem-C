#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct filaNo fila;

 struct filaNo{
    char nome[50];
    int item;
    fila* prox;
 };

typedef struct primElemento{
    fila* prim;
    fila* ult;
}fItem;

fItem* criar(void){
    fItem* f= (fItem*) malloc(sizeof(fItem));
    f->prim= NULL;
    f->ult= NULL;
    return f;
}

void insere(fItem* f, int n, char* nome);
void imprimir(fItem* f);
void liberar(fItem* f);
int dequeue(fItem* f);
int isempty(fItem* f);

int main(){
    fItem* f;
    f= criar();

    insere(f,2, "eliakim pereira");
    insere(f,6, "eliakim pereira");
    insere(f,4, "eliakim pereira");
    insere(f,3, "eliakim pereira");

    printf("\n");

    dequeue(f);
    imprimir(f);
    liberar(f);

    return 0;
}

int isempty(fItem* f){
    return (f->prim == NULL);
}

void imprimir(fItem* f){
    for(fila* aux= f->prim; aux != NULL; aux= aux->prox){
        printf("nome: %s", aux->nome);
    }
}

void insere(fItem* f, int n, char* nome){
    fila* novo= (fila*) malloc(sizeof(fila));
    novo->item= n;
    novo->prox= NULL;
    strcpy(novo->nome,nome);
    if(f->prim == NULL){
        f->prim=novo;}
    else{
        f->ult->prox= novo;
    }
    f->ult= novo;
}

int dequeue(fItem* f){
    int n;
    fila* aux= f->prim;
    if(isempty(f)){
        printf("lista vazia mano\n");}
    else{
        n= aux->item;
        f->prim= aux->prox;
    }

    if(f->prim==NULL){
        f->ult= NULL;}

    free(aux);
    return n;
}

void liberar(fItem* f){
    fila* aux= f->prim;

    while(aux != NULL){
        fila* tem= aux->prox;
        free(aux);
        aux= tem;
    }
    free(f);
}