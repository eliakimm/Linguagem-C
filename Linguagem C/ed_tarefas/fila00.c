#include <stdio.h>
#include <stdlib.h>

 typedef struct filaNo fila;

 struct filaNo{
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

void insere(fItem* f, int n);
void imprimir(fItem* f);
int dequeue(fItem* f);
int isempty(fItem* f);

int main(){
    fItem* f;
    f= criar();

    insere(f,2);
    insere(f,5);
    insere(f,7);
    insere(f,4);
    imprimir(f);

    printf("\n");

    dequeue(f);
    imprimir(f);

    return 0;
}

int isempty(fItem* f){
    return (f->prim == NULL);
}

void imprimir(fItem* f){
    for(fila* aux= f->prim; aux != NULL; aux= aux->prox){
        printf(" <-- %d", aux->item);
    }
}

void insere(fItem* f, int n){
    fila* novo= (fila*) malloc(sizeof(fila));
    novo->item= n;
    novo->prox= NULL;
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