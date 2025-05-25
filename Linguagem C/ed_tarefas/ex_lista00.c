#include <stdio.h>
#include <stdlib.h>

typedef struct elementoLista lista;

struct elementoLista{
    int item;
    lista* prox;
    lista* ant;
};

typedef struct primeiroElemento{
    lista* prim;
    lista* ult;
}pItem;

pItem* criar(void){
    pItem* l= (pItem*)malloc(sizeof(pItem));
    l->prim= NULL;
    l->ult= NULL;
    return l;
}

void insereIn(pItem* l, int n);
void insereFim(pItem* l, int n);
void imprimir(pItem* l);
void removerItem(pItem* l, char s);
void liberarLista(pItem* l);

int main(){
    int n;
    char op;
    char comando[10];

    //Inicia a lista:
    pItem* l;
    l= criar();

    fgets(comando, sizeof(comando), stdin);
    sscanf(comando, "%s %d", &op, &n);
    while(op != 'X'){
        if(op == 'I'){ //Insere um item no inicio da lista;
            insereIn(l, n);}
        else if(op == 'F'){ //Insere um item no fim da lista;
            insereFim(l,n);}
        else if(op == 'D'){ //Remove o primeiro item da lista;
            removerItem(l, op);}
        else if(op == 'P'){ //Remove o ultimo elemento da lista;
            removerItem(l, op);}
        fgets(comando, sizeof(comando), stdin);
        sscanf(comando, "%s %d", &op, &n);
    }
    printf("\n");
    imprimir(l);
    liberarLista(l);
    return 0;
}

void insereIn(pItem* l, int n){
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= l->prim;
    novo->ant= NULL;
    l->prim= novo;
    if(l->ult == NULL){
        l->ult= novo;
    }
}

void insereFim(pItem* l, int n){
    if(l->prim == NULL){
        insereIn(l,n);}
    else{
        lista* novo= (lista*) malloc(sizeof(lista));
        novo->item= n;
        novo->prox= NULL;
        novo->ant= l->ult;
        l->ult->prox= novo;
        l->ult= novo;}
}

void imprimir(pItem* l){
    for(lista* aux= l->prim; aux != NULL; aux= aux->prox){
        printf("%d\n", aux->item);
    }
}

void removerItem(pItem* l, char s) {
    if (l->prim == NULL || l->ult == NULL) {
        return;
    }

    int num;
    lista* aux;

    if (s == 'D') {  
        aux = l->prim;
        num = aux->item;

        l->prim = aux->prox;
        if (l->prim != NULL)
            l->prim->ant = NULL;
        else
            l->ult = NULL; 

        free(aux);
    } else {  
        aux = l->ult;
        num = aux->item;

        l->ult = aux->ant;
        if (l->ult != NULL)
            l->ult->prox = NULL;
        else
            l->prim = NULL;  

        free(aux);
    }

    printf("%d\n", num);
}

void liberarLista(pItem* l){
    lista* aux= l->prim;

    while(aux != NULL){
        lista* tem= aux->prox;
        free(aux);
        aux= tem;
    }
    free(l);
}