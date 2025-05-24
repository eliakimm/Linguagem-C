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
int removerItem(pItem* l, char s[2]);
int buscaItem(pItem* l, int n);
void liberarLista(pItem* l);

int main(){
    int n;
    char op[2];

    //Inicia a lista:
    pItem* l;
    l= criar();
    
    scanf("%s", op);
    while(op[0] != 'X'){
        if(op[0] == 'I'){
            scanf("%d", &n);
            insereIn(l, n);}
        else if(op[0] == 'F'){
            scanf("%d", &n);
            insereFim(l,n);}
        else if(op[0] == 'D'){
            printf("%d\n", removerItem(l,op));}
        else if(op[0] == 'P'){
        printf("%d\n", removerItem(l,op));}
        imprimir(l);
        printf("\n");
        scanf("%s", op);
    }

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
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->item= n;
    novo->prox= NULL;

    lista* aux= l->prim;
    while(aux->prox != NULL){
        aux= aux->prox;
    }
    aux->prox= novo;
}

void imprimir(pItem* l){
    for(lista* aux= l->prim; aux != NULL; aux= aux->prox){
        printf("%d ", aux->item);
    }
}

int removerItem(pItem* l, char s[2]){
    int num;
    lista* ant;
    lista* aux= l->prim;
    if(s[0] == 'D'){
        num= aux->item;
        l->prim= aux->prox;
        free(aux);}
    else{
        while(aux != NULL){
            ant= aux;
            num= ant->item;
            aux= aux->prox;
        }
        
    }

    return num;
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
    free(l);
}