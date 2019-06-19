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
    int j;
    int caracteres[NUMBER_OF_CHARS] = {0};

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

    // Desenhar o histograma
    printf("\n\n-- Histograma --");
    printf("\n[Carac.][ Qtd. ]\n");
    for (i = 0; i < NUMBER_OF_CHARS; i++) {
        if (caracteres[i] > 0) {
            printf("[%6c][%6d] ", i, caracteres[i]);
            for (j = 0; j < caracteres[i]; j++) {
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
