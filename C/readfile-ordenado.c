#include <stdio.h>
#include <stdlib.h> //exit()
#include <unistd.h> //usleep()
#include <string.h> //memset()

#define NUMBER_OF_CHARS 128
// Tabela ASCII possui 128 sinais:
// 95 sinais gráficos (letras do alfabeto latino, sinais de pontuação e sinais matemáticos)
// 33 sinais de controle

void advance_cursor();

int main(void) {

    FILE *fd; //ponteiro - apontar para o arquivo
    char caracter, thefile[30];
    int i = 0;
    int j, aux, ordena_trocas = 1;
    int caracteres[NUMBER_OF_CHARS] = {0};
    char ordena[NUMBER_OF_CHARS];

    // Limpar o lixo de memória para a string com o nome do arquivo
    memset(&thefile, '\0', 30);

    // Solicitar nome do arquivo
    printf("Digite o nome do arquivo de texto:\n");
    scanf("%[^\n]s", thefile);

    // Abrir arquivo
    fd = fopen(thefile, "r");

    if (fd == NULL) {
        printf("\n Erro ao abrir.");
        exit(0);
    }

    // Ler e contar caracteres
    printf("\n-- Conteudo do arquivo --\n");
    do {

        if ((caracter = fgetc(fd)) != EOF) {

            caracteres[caracter]++;

            putc(caracter, stdout);

        }

    } while (caracter != EOF);

    // Fechar o arquivo
    fclose(fd);

    for (i = 0; i < NUMBER_OF_CHARS; i++) {
        ordena[i] = i;
    }

    while (ordena_trocas > 0) {
        ordena_trocas = 0;
        for (i = 0; i < NUMBER_OF_CHARS - 1; i++) {

            if (caracteres[ordena[i]] < caracteres[ordena[i+1]]) {
                aux = ordena[i];
                ordena[i] = ordena[i+1];
                ordena[i+1] = aux;
                ordena_trocas = 1;
            }

        }
    }

    // Desenhar o histograma
    printf("\n\n-- Histograma --");
    printf("\n[Carac.][ Qtd. ]\n");
    for (i = 0; i < NUMBER_OF_CHARS; i++) {
        if (caracteres[ordena[i]] > 0) {
            printf("[%6c][%6d] ", ordena[i], caracteres[ordena[i]]);
            for (j = 0; j < caracteres[ordena[i]]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    // Animar cursor
    for (i = 100000; i; i--) {

        advance_cursor();
        usleep(100000);

    }

    printf("\n");
    getchar();
    return(0);

}

void advance_cursor() {

    static int pos = 0;
    char cursor[] = {'/', '-', '\\', '|'};

    printf("%c\b", cursor[pos]);
    fflush(stdout);
    pos = (pos + 1) % 4;

}
