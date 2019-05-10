#include <stdio.h>
#define TAM 10

float media(int[]);

int main() {

    int notas[] = {6, 7, 8, 6, 8, 3, 5, 7, 7, 8};
    int auxiliar[TAM], i;

    printf("Ordem normal:\n");

    for (i = 0; i < TAM; i++){
        printf("notas[%d] = %d\n", i, notas[i]);
        auxiliar[TAM - i - 1] = notas[i];
    }

    printf("Ordem inversa:\n");

    for (i = 0; i < TAM; i++){
        printf("aux[%d] = %d\n", i, auxiliar[i]);
    }

    printf("Media = %f\n", media(notas));

    return(0);

}

float media(int valores[]) {
    int i, somatoria = 0;

    for (i = 0; i < TAM; i++) {
        somatoria += valores[i];
    }

    return (float) somatoria / TAM;
}