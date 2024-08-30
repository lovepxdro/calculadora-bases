// feito por pedro antônio (pafm)
// versão 0.1 feita no dia 29/08/24 às 19:34 > criei a função de converter para a base 2
// versão 0.2 feita no dia 29/08/24 às 19:37 > criei a função de converter para a base 8
// versão 0.3 feita no dia 29/08/24 às 19:39 > criei a função de converter para a base 16
// versão 0.4 feita no dia 29/08/24 às 19:41 > criei a função de converter para a base bcd
// versão 0.5 feita no dia 30/08/24 às 14:20 > criei a função de converter com complemento a 2
// versão 0.6 feita no dia 30/08/24 às 19:34 > criei a função de converter decimal para float e double
// versão 1.0 feita no dia 30/08/24 às 19:58 > criei uma função de menu e organizei o código

#include <stdio.h>
#include <stdint.h>

void baseDois(int n);
void baseOito(int n);
void baseDezesseis(int n);
void baseBCD(int n);
void complemento2(int n);
void printFloat(uint32_t num);
void printDouble(uint64_t num);
void floatToBinary(float f);
void doubleToBinary(double d);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice, n;
    float f;
    double d;

    do {
        printf("\nMenu:\n");
        printf("1. Converter para Binário\n");
        printf("2. Converter para Octal\n");
        printf("3. Converter para Hexadecimal\n");
        printf("4. Converter para BCD\n");
        printf("5. Converter para Complemento de 2\n");
        printf("6. Converter Float para Binário\n");
        printf("7. Converter Double para Binário\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                printf("Digite um número inteiro: ");
                scanf("%d", &n);
                printf("Binário: ");
                baseDois(n);
                printf("\n");
                break;
            case 2:
                printf("Digite um número inteiro: ");
                scanf("%d", &n);
                printf("Octal: ");
                baseOito(n);
                printf("\n");
                break;
            case 3:
                printf("Digite um número inteiro: ");
                scanf("%d", &n);
                printf("Hexadecimal: ");
                baseDezesseis(n);
                printf("\n");
                break;
            case 4:
                printf("Digite um número inteiro: ");
                scanf("%d", &n);
                printf("BCD: ");
                baseBCD(n);
                printf("\n");
                break;
            case 5:
                printf("Digite um número inteiro: ");
                scanf("%d", &n);
                printf("Complemento de 2: ");
                complemento2(n);
                printf("\n");
                break;
            case 6:
                printf("Digite um número float: ");
                scanf("%f", &f);
                floatToBinary(f);
                break;
            case 7:
                printf("Digite um número double: ");
                scanf("%lf", &d);
                doubleToBinary(d);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (choice != 0);
}

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
    
    uint16_t complemento2;

    if (new < 0) {
        complemento2 = (uint16_t)(~(-new) + 1);
    } else {
        complemento2 = (uint16_t)new;
    }

    for (int i = 15; i >= 0; i--) {
        printf("%d", (complemento2 >> i) & 1);
    }
}

void printFloat(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 31 || i == 23) {
            printf(" ");
        }
    }
    printf("\n");
}

void printDouble(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 63 || i == 52) {
            printf(" ");
        }
    }
    printf("\n");
}

void floatToBinary(float f) {
    uint32_t *num = (uint32_t*)&f;
    uint32_t sign = (*num >> 31) & 1;
    uint32_t exponent = (*num >> 23) & 0xFF;
    uint32_t fraction = *num & 0x7FFFFF;

    printf("Float: %f\n", f);
    printf("Bits: ");
    printFloat(*num);

    printf("Sinal: %d\n", sign);
    printf("Expoente: %u\n", exponent);
    printf("Expoente com viés: %d\n", exponent - 127);
    printf("Fração: 0x%X\n", fraction);
}

void doubleToBinary(double d) {
    uint64_t *num = (uint64_t*)&d;
    uint64_t sign = (*num >> 63) & 1;
    uint64_t exponent = (*num >> 52) & 0x7FF;
    uint64_t fraction = *num & 0xFFFFFFFFFFFFF;

    printf("Double: %lf\n", d);
    printf("Bits: ");
    printDouble(*num);

    printf("Sinal: %llu\n", sign);
    printf("Expoente: %llu\n", exponent);
    printf("Expoente com viés: %lld\n", (long long)(exponent - 1023));
    printf("Fração: 0x%llX\n", fraction);
}
