#include <stdio.h>

float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);

main(){
    float a, b, resultado;
    char sinal;
    printf("Digite sua conta usando + - * /\n");
    scanf("%f", &a);
    scanf("%c", &sinal);
    scanf("%f", &b);

    if(sinal == '+') {
        resultado = soma(a,b);
        printf("Resultado: %f", resultado);
    }
    else if(sinal == '-') {
        resultado = subtracao(a,b);
        printf("Resultado: %f", resultado);
    }
    else if(sinal == '*') {
        resultado = multiplicacao(a,b);
        printf("Resultado: %f", resultado);
    }
    else if(sinal == '/') {
        resultado = divisao(a,b);
        printf("Resultado: %f", resultado);
    }
    else
        printf("Sinal inválido.");
}

float soma(float a, float b){
    return a+b;
}
float subtracao(float a, float b){
    return a-b;
}
float multiplicacao(float a, float b){
    return a*b;
}
float divisao(float a, float b){
    return a/b;
}
