#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void transforma(char* infixa) {
    char nota[101]= strtok()
    int tam= strlen(infixa);
    for(int s= 0; s < tam;s++){
        if(infixa[s] == '('){
            int p= s+1;
            while(infixa[p] != ')'){
                if(infixa[p] == ' ') continue;
                else if(infixa[])
            }
        }
    }
}

int main() {
    // char infixa[101], posfixa[201];

    // scanf("%100[^\n]", infixa);

    // transforma(infixa, posfixa);
    // printf("%s\n", posfixa);
    char s= '1';
    if(isdigit(s)){
        printf("funciona");}
    else{
        printf("nao");
    }

    return 0;
}