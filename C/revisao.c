#include <stdio.h>

void mostrarMenu();
void definirVotosTodasUrnas();
void definirVotosUrna(int urna);
void listarVotos();
void contabilizarVotos();
void contabilizarVotosCandidato(int candidato);
void definirVencedor();

int urnas[3][5];
int n_urnas = 3;
int candidatos[] = {10, 20, 30, 0, 99};
int n_candidatos = sizeof(candidatos)/sizeof(int);

void main() {

    short int sair = 0;
    int escolheu, urna_id, candidato_id;

    do {
        mostrarMenu();
        fflush(stdin);
        scanf("%d", &escolheu);

        switch (escolheu) {
            case 1:
                definirVotosTodasUrnas();
                break;
            case 2:
                printf("Digite o ID da urna:\n");
                fflush(stdin);
                scanf("%d", &urna_id);
                definirVotosUrna(urna_id);
                break;
            case 3:
                listarVotos();
                break;
            case 4:
                contabilizarVotos();
                break;
            case 5:
                printf("Digite o ID do candidato:\n");
                fflush(stdin);
                scanf("%d", &candidato_id);
                contabilizarVotosCandidato(candidato_id);
                break;
            case 6:
                definirVencedor();
                break;
            case 7:
                sair = 1;
                break;
            default:
                printf("Opção não existente.\n");
        }


    } while (sair == 0);
}

void mostrarMenu() {

    printf("[ 1 ] - Definir votos das 3 urnas sequencialmente.\n");   
    printf("[ 2 ] - Definir votos de uma urna específica.\n");
    printf("[ 3 ] - Listar os votos de todas as urnas.\n");
    printf("[ 4 ] - Contabilizar o resultado de votos de cada candidato.\n");
    printf("[ 5 ] - Exibir o total de votos de um candidato específico.\n");
    printf("[ 6 ] - Definir Vencedor.\n");
    printf("[ 7 ] - Fim.\n");

}

void definirVotosTodasUrnas() {
    int i;
    for (i = 0; i < n_urnas; i++) {
        definirVotosUrna(i);
    }
}

void definirVotosUrna(int urna) {
    int j;
    for (j = 0; j < 5; j++) {
        printf("Digite o voto %d da urna %d:", j, urna);
        fflush(stdin);
        scanf("%d", &urnas[urna][j]);
    }
}

void listarVotos() {
    int i, j;
    for (i = 0; i < n_urnas; i++) {
        for (j = 0; j < 5; j++) {
            printf("Voto %d da urna %d: %d\n", j, i, urnas[i][j]);
        }
    }
}

void contabilizarVotos() {
    int i;
    for (i = 0; i < n_candidatos; i++) {
        contabilizarVotosCandidato(candidatos[i]);
    }
}

void contabilizarVotosCandidato(int candidato) {
    int i, j;
    int total = 0;
    for (i = 0; i < n_urnas; i++) {
        for (j = 0; j < 5; j++) {
            if (urnas[i][j] == candidato) {
                total++;
            }
        }
    }
    printf("O candidato %d recebeu %d votos.\n", candidato, total);

}

void definirVencedor() {
    int vencedor = 0, votos_vencedor = 0;
    int votos_candidatos[] = {0, 0, 0, 0, 0};
    int i, j;
    for (i = 0; i < n_urnas; i++) {
        for (j = 0; j < 5; j++) {
            votos_candidatos[urnas[i][j]]++;
        }
    }
    for (i = 0; i < n_candidatos; i++) {
        if (votos_candidatos[i] > votos_vencedor) {
            vencedor = i;
        }
    }
    printf("O candidato %d foi o vencedor.\n", vencedor);
}