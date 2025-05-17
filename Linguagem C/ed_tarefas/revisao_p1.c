//Ex 01: simpleArraySum

// #include <stdio.h>
// #include <math.h>

// int main(){
//     int n= 0;
//     int ar[1000];
//     int soma= 0;
//     scanf("%d", &n);

//     for(int i=0;i<n;i++){
//         scanf("%d", &ar[i]);
//         soma=soma + ar[i];}
//     printf("%d", soma);
//     return 0;
// }


//Ex 02: PlusMinus

// #include <stdio.h>
// #include <stdlib.h>


// int main(){
//     int num= 0;
//     int p= 0;
//     int n= 0;
//     int z= 0;

//     int mat[100];
//     scanf("%d", &num);
//     for(int i= 0; i < num; i++){
//         scanf("%d", &mat[i]);
//         if(mat[i] < 0)
//         {n+= 1;}
//         else if(mat[i] == 0)
//         {z+= 1;}
//         else
//         {p+= 1;}
//     }

//     double res_p= (double)p/(double)num;
//     double res_n= (double)n/(double)num;
//     double res_z= (double)z/(double)num;

//     printf("%.6f\n", res_p);
//     printf("%f\n", res_n);
//     printf("%.6f\n", res_z);


//     return 0;
// }


//Ex 03: Time Conversion

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     char hora[10];
//     char hr[10], m[10], s[10];
//     int h= 0; 

//     fgets(hora, 10, stdin);
//     fflush(stdin);

//     m[0]= hora[3];
//     m[1]= hora[4];
//     m[2]= '\0';

//     s[0]= hora[6];
//     s[1]= hora[7];
//     s[2]= '\0';

//     hr[0]= hora[0];
//     hr[1]= hora[1];
//     hr[2]= '\0';

//     if(hora[8] == 'P')
//     {if(hora[0] == '1' && hora[1] == '2')
//     {h= 12;}
//     else if(hora[0] == '1' && hora[1] == '1')
//     {h= 23;}
//     else if(hora[0] == '1' && hora[1] == '0')
//     {h= 22;}
//     else if(hora[0] == '0' && hora[1] == '9')
//     {h= 21;}
//     else if(hora[0] == '0' && hora[1] == '8')
//     {h= 20;}
//     else if(hora[0] == '0' && hora[1] == '7')
//     {h= 19;}
//     else if(hora[0] == '0' && hora[1] == '6')
//     {h= 18;}
//     else if(hora[0] == '0' && hora[1] == '5')
//     {h= 17;}
//     else if(hora[0] == '0' && hora[1] == '4')
//     {h= 16;}
//     else if(hora[0] == '0' && hora[1] == '3')
//     {h= 15;}
//     else if(hora[0] == '0' && hora[1] == '2')
//     {h= 14;}
//     else if(hora[0] == '0' && hora[1] == '1')
//     {h= 13;}

//     printf("%02d:%s:%s", h, m,s);}

//     else
//     {if(hora[0] == '1' && hora[1] == '2')
//     {h= 0;
//     printf("%02d:%s:%s", h, m,s);}
//     else{
//     printf("%s:%s:%s", hr, m,s);}}
    
//     return 0;
// }


//Ex 04: Apple and Orange


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int s= 0, t= 0;
//     int a= 0, b= 0;
//     int m= 0, n= 0;

//     int apples[100000], oranges[100000];

//     int cont_m= 0, cont_o= 0, cont= 0;

//     scanf("%d %d", &s, &t);
//     scanf("%d %d", &a, &b);
//     scanf("%d %d", &m, &n);

//     for(int i= 0; i < m; i++)
//     {scanf("%d", &apples[i]);
//     cont= a + apples[i];
//     if(cont >= s && cont <= t)
//     {cont_m++;}
//     cont= 0;}
    
//     for(int j= 0; j < n; j++)
//     {scanf("%d", &oranges[j]);
//     cont= b + oranges[j];
//     if(cont >= s && cont <= t)
//     {cont_o++;}
//     cont= 0;}
    
//     printf("%d\n%d", cont_m, cont_o);

//     return 0;
// }


//Ex 05: Cats and a Mouse

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int q= 0, a= 0, b= 0, z= 0, p_a= 0, p_b= 0;

//     scanf("%d", &q);
    
//     for(int i= 0; i < q; i++)
//     {scanf("%d %d %d", &a, &b, &z);
//     p_a= abs(a-z);
//     p_b= abs(b-z);
//     if(p_a == p_b)
//     {printf("Mouse C\n");}
//     else if(p_a < p_b)
//     {printf("Cat A\n");}
//     else if(p_b < p_a)
//     {printf("Cat B\n");}}

//     return 0;
// }

/////////////////////////////////////////////////

//Ex extra 01: 2D Array- DS

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int mat[6][6];
//     int maior= -100000;

//     for(int i= 0; i < 6; i++)
//     {for(int j= 0; j < 6; j++)
//         {scanf("%d", &mat[i][j]);}
//     }

//     for(int i= 0; i < 4; i++)
//     {for(int j= 0; j < 6; j++)
//         {if(j == 0 || j > 4 || i > 4)
//         {continue;}
//         else{
//         int amp= mat[i][j-1] + mat[i][j] + mat[i][j+1] + mat[i+1][j] + mat[i+2][j-1] + mat[i+2][j] + mat[i+2][j+1];
//         if(amp >= maior)
//         {maior= amp;
//         amp= 0;}}}}

//     printf("%d", maior);
//     return 0;
// }

//Ex extra 02: Divisible Sum Pairs

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int n= 0, k= 0, cont_p= 0;
//     scanf("%d %d", &n, &k);
//     int ar[100];
//     for(int i= 0; i < n; i++)
//     {scanf("%d", &ar[i]);}

//     for(int i= 0; i < n; i++)
//     {for(int j= i +1; j < n; j++)
//         {if((ar[i] + ar[j]) % k == 0)
//         {cont_p++;}}}
    
//     printf("%d", cont_p);
//     return 0;
// }

//Ex extra 03: CamelCase

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>

// int main(){
//     int plv= 1;
//     char s[100000];
//     fgets(s, 100000, stdin);
//     fflush(stdin);
//     int tam= strlen(s);
//     for(int i= 0; i < tam; i++)
//     {if(isupper(s[i]))
//         {plv++;}
//     }
//     printf("%d", plv);
//     return 0;
// }


//Refazendo a questão Time Conversion:

#include <stdio.h>
#include <stdlib.h>

int main(){
    int hora= 0, min= 0, sec= 0;
    char p[3];
    scanf("%d:%d:%d%s", &hora, &min, &sec, p);
    if(hora == 12)
    {hora= 0;}
    if(p[0] == 'P')
    {hora+= 12;}
    printf("%02d:%02d:%02d", hora, min, sec);
    return 0;
}