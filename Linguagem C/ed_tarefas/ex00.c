//Criando um vetor:

// #include <stdio.h>

// int main(){
//     int vetor_ex[5];
//     double media= 0;
//     vetor_ex[0]= 2;
//     vetor_ex[1]= 5;
//     vetor_ex[2]= 6;
//     vetor_ex[3]= 4;
//     vetor_ex[4]= 1;

//     media= (vetor_ex[0] + vetor_ex[1] + vetor_ex[2] + vetor_ex[3]+ vetor_ex[4])/5;
//     printf("%f\n", media);
// }


// #include <stdio.h>

// int main(){
//     int vetor_ex[5];
//     float media= 0;
//     for(int i=0;i < 5; i++){
//         scanf("%d", &vetor_ex[i]);
//     }
//     for(int c= 0; c < 5; c++){
//         media+= vetor_ex[c];
//     }
//     media/=5;
//     printf("Media: %.2f\n", media);
// }


// #include <stdio.h>

// int main(){
//     char nome[20], sobre[20];
//     scanf("%s %s", nome, sobre);
//     printf("%s\n", sobre);
// }


// #include <stdio.h>       //Ex struct:

// struct EnderecoComp{
//     char end[20];
//     int rua;
//     int casa;
// };

// struct EnderecoComp endereco;       

// int main(){
//     printf("Digite o endereco:\n");
//     scanf("%s %d %d", endereco.end, &endereco.rua, &endereco.casa);
//     printf("%s\n%d\n%d\n", endereco.end, endereco.rua, endereco.casa);

// }


// #include <stdio.h>

// struct Fulano{
//     char nome[20];
//     int dia;
//     int mes;
//     int ano;
// };

// struct Fulano dados_f;

// int main(){
//     printf("Digite seus dados:\n");
//     scanf("%s %d %d %d", dados_f.nome, &dados_f.dia, &dados_f.mes, &dados_f.ano);
//     printf("%s nasceu em %d/%d/%d\n", dados_f.nome, dados_f.dia, dados_f.mes, dados_f.ano);
// }


// #include <stdio.h>      //Ponteiro:

// int main(){
//     int num= 10;
//     int *ptr;
//     ptr= &num;
//     printf("%p", &ptr);
//     // printf("%p", &ptr);
// }

//Ex: imprimindo o maior numero
// #include <stdio.h>
// #include <stdlib.h>

// void maior_n(int n1, int n2){
//     if(n1 > n2){
//         printf("%d é o maior", n1);
//     }else{
//         printf("%d é o maior", n2);
//     }
// }

// int main(){
//     int a= 0;
//     int b= 0;
//     printf("digite 2 valores:\n");
//     scanf("%d %d", &a, &b);
//     maior_n(a,b);
//     return 0;
// }

//Ex: calculando o imc
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// void imc(double n1, double n2){
//     double res= 0;
//     res= n1/ pow(n2,2);
//     printf("IMC = %.2f", res);
// }

// int main(){
//     double a= 0;
//     double b= 0;
//     printf("digite seu peso e sua altura:\n");
//     scanf("%lf %lf", &a, &b);
//     imc(a,b);
//     return 0;
// }



// //Exemplo com matriz:
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// int main(){
//     int mat[3][3];

//     //Preenchendo a matriz:
//     for(int l= 0; l < 3; l++){
//         printf("\n");
//         for(int c= 0; c < 3; c++){
//             scanf("%d", &mat[l][c]);
//         }
//     }

//     //Imprimindo a matriz:
//     for(int linha= 0; linha < 3; linha++){
//         printf("\n");
//         for(int coluna= 0; coluna < 3; coluna++){
//             printf("%d ", mat[linha][coluna]);
//         }
//     }
// }


// #include <stdio.h>
// #include <stdlib.h>

// int simpleArraySum(int ar[], int n){
//     int total= 0;
//     for(int num= 0; num < n;num++){
//         total+= ar[num];
//     }
//     return total;
// }

// int main(){
//     int n= 0;
//     int ar[n];
//     int resultado= 0;
//     scanf("%d", &n);
//     if(n <= 0){
//         return 0;
//     }
//     for(int i=0;i<n;i++){
//         scanf("%d", &ar[i]);
//         if(ar[i] >= 1000){
//             ar[i]= 0;
//         }
//     }
//     resultado= simpleArraySum(ar, n);
//     printf("%d", resultado);
//     return 0;
// }


// #include <stdio.h>

// int main() {
//     char entrada[10];
//     char op;
//     int valor;

//     printf("Digite um comando (ex: F 45): ");
//     fgets(entrada, sizeof(entrada), stdin);

//     // Tenta ler o caractere e o inteiro
//     if (sscanf(entrada, "%c %d", &op, &valor) == 2) {
//         printf("Operação: %c\n", op);
//         printf("Valor: %d\n", valor);
//     } else {
//         printf("Entrada inválida!\n");
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 50

int main(){
    char comando[TAM];
    char nome[TAM];
    char mat[TAM]; 
    int encontrou= 0;
    fgets(comando, TAM, stdin);
    comando[strcspn(comando, "\n")] = '\0';
    fflush(stdin);
    int i= 0, j= 0, k=0;
    while(comando[i] != '\0'){
        if(!encontrou && isdigit(comando[i])) {
            encontrou= 1;}
        
        if(encontrou){
            mat[k++]= comando[i];}
        else{
            nome[j++]= comando[i];}
        i++;
    }
    
    nome[j]= '\0';
    mat[k]= '\0';
    printf("Nome: %s\n", nome);
    printf("Matricula: %s", mat);

    return 0;
}