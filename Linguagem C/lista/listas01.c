#include <stdio.h>
#include <stdlib.h>


typedef struct elementoLista lista;

struct elementoLista{
    int item;
    lista* prox;
};

typedef struct primeiroElemento{
    lista* prim;
}pItem;


pItem* criar(void){
    pItem* l= (pItem*)malloc(sizeof(pItem));
    l->prim= NULL;
    return l;
}

void insereIn(pItem* l, int n);
void insereFim(pItem* l, int n);
void imprimir(pItem* l);
void removerItem(pItem* l, int n);
int buscaItem(pItem* l, int n);
void liberarLista(pItem* l);

int main(){
    int n;

    //Inicia a lista:
    pItem* l;
    l= criar();
    
    //Insere elementos no inicio da lista:
    printf("Insira um elemento na lista:\n");
    scanf("%d", &n);
    while(n != 0){
    insereIn(l, n);
    printf("Insira um elemento no inicio da lista:\n");
    scanf("%d", &n);}

    printf("excluir o seguinte item da lista:\n");
    scanf("%d", &n);
    removerItem(l,n);
    
    imprimir(l);
    
    printf("Excluindo a lista:");
    liberarLista(l);
    imprimir(l);
    return 0;
}

void insereIn(pItem* l, int n){
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= l->prim;
    l->prim= novo;
}

void insereFim(pItem* l, int n){
    if(l->prim == NULL){
        insereIn(l,n);}
    else{
        lista* novo= (lista*) malloc(sizeof(lista));
        novo->item= n;
        novo->prox= NULL;

        lista* aux= l->prim;
        while(aux->prox != NULL){
            aux= aux->prox;
        }
        aux->prox= novo;}
}

void imprimir(pItem* l){
    if(l->prim == NULL){
        printf("\nlista vazia...");}
    else{
        for(lista* aux= l->prim; aux != NULL; aux= aux->prox){
            printf("%d ", aux->item);}
        printf("\n");}
}

void removerItem(pItem* l, int n){
    lista* ant = NULL;
    lista* aux = l->prim;

    while (aux != NULL && aux->item != n) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("O item nao existe na lista\n");
        return;
    }

    if (ant == NULL) { // item está no primeiro nó
        l->prim = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
}


int buscaItem(pItem* l, int n){
    for(lista* aux= l->prim; aux != NULL; aux= aux->prox){
        if(aux->item == n)
        return 1;
    }
    return 0;
}

void liberarLista(pItem* l){
    lista* aux= l->prim;

    while(aux != NULL){
        lista* tem= aux->prox;
        free(aux);
        aux= tem;
    }
    l->prim= NULL;
}