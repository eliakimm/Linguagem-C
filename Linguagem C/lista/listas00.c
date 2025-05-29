#include <stdio.h>
#include <stdlib.h>

typedef struct elementoLista lista;

struct elementoLista{
    int item;
    struct elementoLista* prox;
};

void insereIn(lista* cabeca, int n);
void insereFim(lista* cabeca, int n);
void imprimir(lista* cabeca);
void remover(lista* cabeca, int v);


int main(){
    int n;
    lista cabeca;
    cabeca.prox= NULL;
    while(n != 0){
        printf("Inserir elementos no inicio da lista:\n");
        scanf("%d", &n);
        insereIn(&cabeca, n);
    }

    printf("esse elemento sera inserido no fim da lista:\n");
    scanf("%d", &n);
    insereFim(&cabeca,n);

    imprimir(&cabeca);

    printf("Esse item sera removida da lista:\n");
    scanf("%d", &n);

}


//Iserir elemento no inicio da lista:
void insereIn(lista* cabeca, int n){
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= cabeca->prox;
    cabeca->prox= novo;
}

void insereFim(lista* cabeca, int n){
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= NULL;
    //pegando o primeiro elemento da lista:
    lista* atual= cabeca;
    while(atual->prox != NULL){
        atual= atual->prox;
    }
    atual->prox= novo;
}

void imprimir(lista* cabeca){
    for(lista* aux= cabeca->prox; aux != NULL; aux= aux->prox){
        printf("%d ", aux->item);
    }
}

void remover(lista* cabeca, int n){
    lista* ant;
    lista* aux= cabeca;
    while(aux->prox != NULL && aux->item != n){
        ant= aux;
        aux= aux->prox;
    }

    if(aux != NULL){
        if(ant == NULL){
            if(ant == NULL)
        }
    }
}