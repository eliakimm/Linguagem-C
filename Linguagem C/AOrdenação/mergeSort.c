#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *vet, int inicio, int meio, int fim){
     int *aux, part1, part2, tamanho, i, j, k;
     int fim1= 0, fim2= 0; //flags para validar o tamanho das partes 1 e 2;
     tamanho= fim - inicio +1;
     part1= inicio;
     part2= meio +1;
     aux= (int*)malloc(tamanho*sizeof(int));
     if(aux != NULL){
        for(i= 0; i < tamanho; i++){
            if(!fim1 && !fim2){ //verifica se as flags são validas;
                if(vet[part1] < vet[part2]){
                    aux[i]= vet[part1++];}
                else{
                    aux[i]= vet[part2++];}
                if(part1 > meio){ //verifica se a parte 1 do vetor acabou;
                    fim1= 1;}
                if(part2 > fim){ //verifica se a parte 2 do vetor acabou;
                    fim2= 1;}}
            else{
                if(!fim1){
                    aux[i]= vet[part1++];}
                else{
                    aux[i]= vet[part2];}}}
        for(j= 0, k= inicio; j < tamanho; j++, k++){
            vet[k]= aux[j];}
        free(aux);
        }
}

void mergeSort(int *vet, int inicio, int fim){
    int meio= floor((inicio + fim)/2);
    if(inicio < fim){
        //Divide o vetor em partes enquanto vetor > 0:
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        //Junta as partes de forma ordenada:
        merge(vet, inicio, meio, fim);
    }
}

int main(){
   int vet[]= {117, 90, 88, 83, 81, 77, 74, 69, 64, 63, 51, 50, 49, 42, 41, 34, 32, 29, 28, 22, 16, 8, 6, 5, 3, 1};
   int tam = sizeof(vet) / sizeof(vet[0]);
   mergeSort(vet, 0, tam -1);
   printf("Quantidade de elementos: %d\n", tam); 
   for(int i= 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}