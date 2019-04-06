#include <stdio.h>

int main(){

    int inteiro = 5;
    char letra = 'X';
    float decimal = 1.1234567;

    printf("Digite um caractere\n");
    scanf("%c", &letra);
    getchar();

    printf("Digite um inteiro\n");
    scanf("%d", &inteiro);
    getchar();

    printf("Digite um decimal");
    scanf("%f", &decimal);
    getchar();

    printf("Tipo de dados e formatação");
    printf("\n----------------------------------");
    printf("\nTipo caractere\t\t|%5c",letra);
    printf("\nTipo inteiro\t\t|%5d",inteiro);
    printf("\nTipo ponto flutuante\t|%9.3f\n\n",decimal);


    return(1);

}
