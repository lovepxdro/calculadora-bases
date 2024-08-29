// feito por pedro antônio (pafm)
// versão 0.1 feita no dia 29/08/24 às 19:34 > criei a função de converter para a base 2
// versão 0.2 feita no dia 29/08/24 às 19:37 > criei a função de converter para a base 8
// versão 0.3 feita no dia 29/08/24 às 19:39 > criei a função de converter para a base 16
// versão 0.4 feita no dia 29/08/24 às 19:41 > criei a função de converter para a base bcd

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

void baseDezesseis(int n) {
    if (n >= 16) {
        baseDezesseis(n / 16);
    }

    int resto = n % 16;

    if (resto >= 10) {
        switch (resto) {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
        }
    } else {
        printf("%d", resto);
    }
}

void baseBCD(int n) {
    int digitos[10];
    int i = 0;

    while (n > 0) {
        digitos[i] = n % 10;
        n /= 10;
        i++;
    }
  
    for (int j = i - 1; j >= 0; j--) {
        int binario[4] = {0, 0, 0, 0};

        int num = digitos[j];
        int k = 3;

        while (num > 0) {
            binario[k] = num % 2;
            num /= 2;
            k--;
        }

        for (k = 0; k < 4; k++) {
            printf("%d", binario[k]);
        }
        printf(" ");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    baseBCD(n);

    return 0;
}
