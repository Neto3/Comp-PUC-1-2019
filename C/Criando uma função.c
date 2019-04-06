#include <stdio.h>

void comparaPN(int ZERO);

int main() {

    int ZERO = 0;

    comparaPN(ZERO);
    comparaPN(ZERO);

    return(0);

}

void comparaPN(int ZERO) {

    int nmr;

    printf("\nInforme um valor: ");
    scanf("%d", &nmr);
    getchar();

    if (nmr >= ZERO) {
        printf("\nSeu número é positivo.");
    }

    if (nmr < ZERO) {
        printf("\nSeu número é negativo.");
    }

    return;

}