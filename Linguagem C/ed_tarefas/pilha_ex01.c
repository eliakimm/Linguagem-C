//Coversor de decimal para binario utilizando pilha:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void push(stack* p, int n);//insere itens na pilha;
void desempilhar(stack* p);//desempilha;
int pop(stack* p);//remove o item que está no topo da pilha; 
int peek(stack* p);//imprime o topo da pilha.


int main(){
    int n, res;
    char str[5];
    stack* p;
    p= criar();
    printf("Digite um numero:\n");
    scanf("%s", str); 
    while(){
        if(str[0] == '+'){
            for(int c=0; c < 2; c++){
                res+= pop(p);}
        }else{
            n= atoi(str);
            push(p, n);}
        scanf("%s", str);
    }
    desempilhar(p);
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


void desempilhar(stack* p){
    while(p->topo != NULL){
        printf("%d", pop(p));
    }
}