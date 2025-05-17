#include <stdio.h>
#include <stdlib.h>


typedef struct elementoLista lista;

struct elementoLista{
    int item;
    lista* prox;
};

void insereIn(lista* prim, int n);
void insereFim(lista* prim, int n);
void imprimir(lista* prim);
void removerItem(lista* prim, int n);
int buscaItem(lista* prim, int n);
void liberarLista(lista* prim);

int main(){
    int n, res;

    //Cria o primeiro elemento/cabeça da lista:
    lista prim;
    prim.prox= NULL;
    
    //Insere elementos no inicio da lista:
    printf("Insira um elemento na lista:\n");
    scanf("%d", &n);
    while(n != 0){
    insereIn(&prim, n);
    printf("Insira um elemento no inicio da lista:\n");
    scanf("%d", &n);}

    //imprimir lista:
    imprimir(&prim);

    //Insere elementos no fim da lista:
    printf("Insira um elemento no fim da lista:\n");
    scanf("%d", &n);
    while(n != 0){
    insereFim(&prim, n);
    printf("Insira um elemento no fim da lista:\n");
    scanf("%d", &n);}

    //imprimir lista:
    imprimir(&prim);

    //remover elemento:
    printf("\nRemover o seguinte elemento:\n");
    scanf("%d", &n);
    removerItem(&prim, n);
    imprimir(&prim);

    //buscar por item na lista:
    printf("\nBuscar o seguinte elemento na lista:\n");
    scanf("%d", &n); 
    res= buscaItem(&prim, n);
    if(res == 1){
        printf("O item esta na lista\n");
    }else{
        printf("Item nao encontrado\n");
    }
    return 0;
}

void insereIn(lista* prim, int n){
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= prim->prox;
    prim->prox= novo;
}

void insereFim(lista* prim, int n){
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= NULL;

    lista* aux= prim;
    while(aux->prox != NULL){
        aux= aux->prox;
    }
    aux->prox= novo;
}

void imprimir(lista* prim){
    for(lista* aux= prim->prox; aux != NULL; aux= aux->prox){
        printf("%d ", aux->item);
    }
}

void removerItem(lista* prim, int n){
    lista* ant;
    lista* aux= prim;
    while(aux->item != n){
        ant= aux;
        aux= aux->prox;
    }
    if(aux != NULL){
        if(ant == NULL){
            prim= aux->prox;
        }
        else{
            ant->prox= aux->prox;
        }
    }
    free(aux);
}

int buscaItem(lista* prim, int n){
    for(lista* aux= prim; aux != NULL; aux= aux->prox){
        if(aux->item == n)
        return 1;
    }
    return 0;
}

void liberarLista(lista* prim){
    lista* aux= prim;

    while(aux != NULL){
        lista* tem= aux->prox;
        free(aux);
        aux= tem;
    }
    free(prim);
}