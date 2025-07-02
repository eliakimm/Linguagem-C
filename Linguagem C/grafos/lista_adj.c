#include <stdio.h>
#include <stdlib.h>

//Lista de adjacencia

typedef struct No{
    struct No *prox;
    int rotulo;
}no;

typedef struct Grafo{
    int vertices;
    int arestas;
    no **ponteiro;
}*grafo;

grafo iniciaGrafo(int num_vertices){
    int i;
    grafo g= malloc(sizeof * g);
    g->vertices= num_vertices;
    g->arestas= 0;
    g->ponteiro= malloc(num_vertices * sizeof(no*));
    for(i= 0; i < num_vertices; i++){
        g->ponteiro[i]= NULL;
    }
    return g;
}

void insereArestas(grafo g, int v, int novo){       //v é o vertice em que vamos inserir um no arco.
    no *aux;                                        //novo é o arco a ser inserido no vertice.
    for(aux= g->ponteiro[v]; aux != NULL; aux= aux->prox){
        if(aux->rotulo == novo){
            return;
        }
    }
    aux= malloc(sizeof(no));
    aux->rotulo= novo;
    aux->prox= g->ponteiro[v];
    g->ponteiro[v]= aux;
    g->arestas++;
}

void imprimeGrafo(grafo g){
    for(int i= 0; i < g->vertices; i++){
        printf("Vertice [%d]: ", i);
        no *aux= g->ponteiro[i];
        while(aux != NULL){
            printf("-> %d ", aux->rotulo);
            aux= aux->prox;
        }
        printf("-> NULL\n");
    }
}

liberarGrafo(grafo g){
    for(int i= 0; i < g->vertices; i++){
        no *aux= g->ponteiro[i];
        while(aux != NULL){
            no* temp= aux;
            aux= aux->prox;
            free(temp);
        }
    }
    free(g->ponteiro);
    free(g);
}

int main(){
    grafo g= iniciaGrafo(5);
    insereArestas(g, 0, 1);
    insereArestas(g, 0, 4);
    insereArestas(g, 1, 3);
    insereArestas(g, 3, 4);
    insereArestas(g, 2, 4);
    insereArestas(g, 2, 3);

    imprimeGrafo(g);
    liberarGrafo(g);
    return 0;
}