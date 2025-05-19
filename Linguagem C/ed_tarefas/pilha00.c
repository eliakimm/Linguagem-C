#include <stdio.h>
#include <stdlib.h>

typedef struct elementoPilha pilha;

struct elementoPilha{
    int item;
    pilha* prox;
};

typedef struct topoDapilha{
    pilha* topo;
}stack;

//Prototipos das funções:
stack* criar(void);//inicia a pilha;
void imprime(stack* p);//basicamente imprime a pilha kkkkk;
void push(stack* p, int n);//insere itens na pilha;
int pop(stack* p);//remove o item que está no topo da pilha; 
int peek(stack* p);//imprime o topo da pilha.

int main(){
    int n;
    stack* p;
    p= criar();
    printf("Insira um item na pilha:\n");
    scanf("%d", &n);

    //Inserindo itens na pilha:
    while(n != 0){
        push(p, n);
        printf("Insira mais itens na pilha:\n");
        scanf("%d", &n);
    }

    imprime(p);
    //Mostrando o topo da pilha:
    printf("\nO topo da pilha: %d\n", peek(p));

    //Removendo um item da pilha (Só é possivel remover a partir do topo):
    printf("\nRemovendo o topo da pilha: %d\n", pop(p));
    imprime(p);

    return 0;
}


//FUNÇÔES:
stack* criar(void){
    stack* p= (stack*) malloc(sizeof(stack));
    p->topo= NULL;
    return p;
}

void push(stack* p, int n){
    pilha* novo= (pilha*) malloc(sizeof(pilha));
    novo->item= n;
    novo->prox= p->topo;
    p->topo= novo;
};

int pop(stack* p){
    pilha* aux= p->topo;
    p->topo= aux->prox;
    int n= aux->item;
    free(aux);
    return n;
};


int peek(stack* p){
    pilha* aux= p->topo;
    return aux->item;
};

void imprime(stack* p){
    for(pilha* aux= p->topo; aux != NULL; aux= aux->prox){
        printf("%d <-- ", aux->item);
    }
};