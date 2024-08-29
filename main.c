// feito por pedro antônio (pafm)
// versão 0.1 feita no dia 29/08/24 às 19:34 > criei a função de converter para a base 2
// versão 0.2 feita no dia 29/08/24 às 19:37 > criei a função de converter para a base 8

#include <stdio.h>

void baseDois (int n){
    if(n>1){
        baseDois(n/2);
    }
    printf("%d", n%2);
}

void baseOito (int n){
    if(n>1){
        baseOito(n/8);
    }
    printf("%d", n%8);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    baseOito(n);

    return 0;
}
