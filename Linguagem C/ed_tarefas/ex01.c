// #include  <stdio.h>      //For:

// int main(){
//     for(int c= 0;c<=10;c++){
//         printf("contagem: %i\n", c);
//     }
    
// }

// #include <stdio.h>      //While:

// int main(){
//     int c= 0;
//     while(c <= 10){
//         printf("contagem: %i\n", c);
//         c++;
//     }
// }


// #include <stdio.h>

// int main(){
//     int n1= 15;
//     int *ptr= &n1;
//     printf("conteudo da variavel n1: %d\n", n1);
//     printf("endereco de memoria da variavel n1: %p\n", &n1);
//     printf("conteudo apontado pelo ponteiro: %d\n", *ptr);
//     printf("endereco apontado pelo ponteiro: %p\n", ptr);
// }


// #include <stdio.h>

// int main(){
//     int ar[6];
//     ar[0]= 2;
//     printf("%d", ar[1]);
// }



#include <stdio.h>
#include <stdlib.h>

int main(){
    for(int i= 0; i < 6; i++)
    {if(i % 2 == 0)
        {continue;}
    else{
    printf("Ok\n");}
    }
    return 0;
}