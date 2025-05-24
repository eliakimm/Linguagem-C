// #include <stdio.h>   //Ex de entrada e saída de dados:

// int main(){                
//     int idade= 0;
//     int ano= 0;
//     printf("Digite sua idade e seu ano: \n");
//     scanf("%i %i", &idade, &ano);
//     printf("idade: %i, ano: %i", idade, ano);
// }

// #include <stdio.h>  //Ex com variaveis:
// #define texto "Entrada e saída:"

// int main(){
//     char nome[50]= "";
//     int idade= 0;
//     float altura= 0.0;
//     printf("%s\n", texto);
//     scanf("%s", nome);
//     scanf("%i %f", &idade, &altura);
//     printf("nome: %s\nidade: %i\naltura: %.2f", nome, idade, altura);
// }


// #include <stdio.h> //Fazendo operações matematicas:

// int main(){
//     //Recebendo valores:
//     int n1, n2, soma, sub, mult, div, resto;
//     printf("Digite um valor:\n");
//     scanf("%i", &n1);
//     printf("Digite outro valor:\n");
//     scanf("%i", &n2);
//     //Operações:
//     soma= n1 + n2;
//     sub= n1 - n2;
//     div= n1 / n2;
//     mult= n1 * n2;
//     resto= n1 % n2;
//     //Resultados:
//     printf("Soma: %i\n", soma);
//     printf("subtracao: %i\n", sub);
//     printf("divisao: %i\n", div);
//     printf("multiplicacao: %i\n", mult);
//     printf("Resto da div.: %i\n", resto);
// }


// #include <stdio.h> //If e Else:

// int main(){
//     int num= 0;
//     printf("Digite um numero:\n");
//     scanf("%i", &num);
//     if(num%2 == 0){
//         printf("par\n");
//     }else{
//         printf("impar\n");
//     }
// }



// #include <stdio.h>       //\a e \7: emite um sinal sonoro.
// #include <stdlib.h>

// int main(){
//     printf("aqui vai um apito\7\n");
//     printf("aqui vai um apito\a\n");
//     return 0;
// }



// #include <stdio.h>       //\t: tabulação horizontal.
// #include <stdlib.h>

// int main(){
//     printf("1-\tClientes\n");
//     printf("2-\tFornecedores\n");
//     printf("3-\tFaturas\n");
//     printf("1-\tSair\n");
//     return 0;
// }


// #include <stdio.h> //Struct:

// typedef struct Data{
//     int dia, ano;
//     char mes[12];
// }Data;

// int main(){

//     struct Data d_nasc[3];
//     d_nasc= {02,2004, "agosto"};
    
// }


// #include <stdio.h>      //Convertendo para float:

// int main(){
//     int x= 10, y= 4;
//     float z= (float)x/y;
//     printf("%.2f", z);
//     return 0;
    
// }


// #include <stdio.h>

// struct Registro{
//     char nome[30];
//     int dia, mes, ano;
// };

// struct Registro pessoa;

// int main(){
//     scanf("%s %d %d %d", pessoa.nome, &pessoa.dia, &pessoa.mes, &pessoa.ano);
//     printf("%s Nasceu em: %02d %02d %d", pessoa.nome, pessoa.dia, pessoa.mes, pessoa.ano);
// }



// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define TAM 3

// struct reg_pessoa{
//     char nome[50];
//     int idade, peso;
// };

// typedef struct reg_pessoa pessoa;

// int main(){
//     pessoa lista[TAM];

//     for(int i= 0; i < TAM; i++){
//         puts("Nome:");
//         scanf("%50[^\n]s", &lista[i].nome);
//         fflush(stdin);

//         puts("Idade:");
//         scanf("%d", &lista[i].idade);
//         fflush(stdin);

//         puts("Peso:");
//         scanf("%d", &lista[i].peso);
//         fflush(stdin);
//     }
//     system("cls");

//     for(int i= 0; i < TAM; i++){
//         printf("Pessoa:(%d)\n", i);
//         printf("%s tem %d anos, e pesa %d kg.\n", lista[i].nome, lista[i].idade, lista[i].peso);
//         puts("********************************************************");
//     }
    
// }


#include <stdio.h>
#include <stdlib.h>

int main(){
    char c[3]= "13";
    int n= atoi(c);
    n++;
    printf("%d", n);
    return 0;
}
