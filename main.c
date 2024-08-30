// feito por pedro antônio (pafm)
// versão 0.1 feita no dia 29/08/24 às 19:34 > criei a função de converter para a base 2
// versão 0.2 feita no dia 29/08/24 às 19:37 > criei a função de converter para a base 8
// versão 0.3 feita no dia 29/08/24 às 19:39 > criei a função de converter para a base 16
// versão 0.4 feita no dia 29/08/24 às 19:41 > criei a função de converter para a base bcd
// versão 0.5 feita no dia 30/08/24 às 14:20 > criei a função de converter com complemento a 2

#include <stdio.h>
#include <stdint.h> // usada na função complemento2

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

void complemento2(int n){
    if (n < -32768 || n > 32767) {
        return;
    }
    
    int new=-n;
    
    uint16_t complemento2; // converter para 16 bits

    if (new < 0) {
        complemento2 = (uint16_t)(~(-new) + 1);
    } else {
        complemento2 = (uint16_t)new;
    }

    for (int i = 15; i >= 0; i--) {
        printf("%d", (complemento2 >> i) & 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    complemento2(n);

    return 0;
}
