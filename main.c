// feito por pedro antônio (pafm)
// versão 0.1 feita no dia 29/08/24 às 19:34 > criei a funçãode converter para a base 2

#include <stdio.h>

void baseDois (int n){
    if(n>1){
        baseDois(n/2);
    }
    printf("%d", n%2);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    baseDois(n);

    return 0;
}
