#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista{
    ListaNo* prim;
};

struct listano{
    int item;
    ListaNo* prox;
};

Lista* cria(void){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->prim = NULL;

    return l;
}

void criaNo(Lista* l, int i){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->item = i;
    novo->prox = l->prim;
    l->prim = novo;
}

int busca(Lista* l, int i){
    for(ListaNo* p = l->prim; p != NULL; p = p->prox){
        if(p->item == i){
            return 1;
        }
    }
    return 0;
}

void imprime(Lista* l){
    for(ListaNo* p = l->prim; p != NULL; p = p->prox){
        printf("Item = %d\n", p->item);
    }
}

int vazia(Lista* l){
    return (l->prim == NULL);
}

void liberarLista(Lista* l){

    ListaNo* p = l->prim;

    while (p != NULL){
        ListaNo* t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}

void excluirElemento(Lista* l, int e){

    ListaNo* ant = NULL;
    ListaNo* p = l->prim;

    while(p != NULL && p->item != e){
        ant = p;
        p = p->prox;
    }

    if(p != NULL){
        if (ant == NULL){
            l->prim = p->prox;
        }else{
            ant->prox = p->prox;
        }
        free(p);
    }
}

int main(void){

    Lista* lista = cria();
    criaNo(lista, 23);
    criaNo(lista, 45);
    criaNo(lista, 56);
    criaNo(lista, 78);

    printf("Lista com elementos inseridos \n");
    imprime(lista);

    excluirElemento(lista, 78);
    
    printf("Lista após exclusão do 78. \n");
    imprime(lista);

    excluirElemento(lista, 45);

    printf("Lista após exclusão do 45. \n");
    imprime(lista);

    liberarLista(lista);
    printf("Lista liberada!!!!! \n");
    vazia(lista);
    imprime(lista);

    return 0;
}