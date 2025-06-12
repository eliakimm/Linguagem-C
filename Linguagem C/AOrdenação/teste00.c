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
    int vet[26]= {117, 90, 88, 83, 81, 77, 74, 69, 64, 63, 51, 50, 49, 42, 41, 34, 32, 29, 28, 22, 16, 8, 6, 5, 3, 1};
    
    bubblesort(vet, 26);
    for(int i= 0; i < 26; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}

