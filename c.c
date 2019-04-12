#include <stdio.h>
#include <ctype.h>

float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);
unsigned short int continuar();

int main(){
    float a, b, resultado;
    char sinal;
    int continua;

    continua = 1;

    while(continua){

        printf("Digite sua conta usando + - * /\n");
        scanf("%f", &a);
        scanf("%c", &sinal);
        scanf("%f", &b);
        getchar();

        switch (sinal)
        {
            case '+':
                resultado = soma(a,b);
                printf("Resultado: %f", resultado);
                break;
            case '-':
                resultado = subtracao(a,b);
                printf("Resultado: %f", resultado);
                break;
            case '*':
                resultado = multiplicacao(a,b);
                printf("Resultado: %f", resultado);
                break;
            case '/':
                resultado = divisao(a,b);
                printf("Resultado: %f", resultado);
                break;
            default:
                printf("Sinal inválido.");
        }

        printf("\n");
        
        continua = continuar();
    }
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
unsigned short int continuar(){
    int count;
    char resposta;

    count = 0;

    while (count < 3){
       
        printf("Continuar? (s|n)\n");
        resposta = toupper(getchar());
        getchar();

        if (resposta != 'S' && resposta != 'N'){
            count++;
        } else if (resposta == 'S'){
            return 1;
        } else if (resposta == 'N'){
            return 0;
        }

    }

    printf("Você respondeu 3 vezes incorretamente.");
    return 0;

}