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
            vet[k]= aux[j];
        }
        }
}

void mergeSort(int *vet, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio= floor((inicio + fim)/2);
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int main(){
   int vet[7]= {7, 8, 9, 4, 9, 5, 2};
   mergeSort(vet, 0, 7); 
   for(int i= 0; i < 7; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}