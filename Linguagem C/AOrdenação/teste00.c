#include <stdio.h>
#include <stdlib.h>

void bubblesort(int vet[], int tam){
    int continua, i, aux, fim= tam;
    do{
        continua= 0;
        for(i=0; i < fim -1;i++){
            if(vet[i] > vet[i+1]){
              aux= vet[i];
              vet[i]= vet[i+1];
              vet[i+1]= aux;
              continua= i;
            }
        }
        fim--;
    }while(continua != 0);
}

int main(){
    int vet[7]= {7, 8, 9, 4, 9, 5, 2}; 
    bubblesort(vet, 7);
    for(int i= 0; i < 7; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}

