#include <stdio.h>

#define MAX_ALUNOS 60

void cadastrar_aluno();
void pesquisar_aluno();
void mostrar_aluno(int);
void listar_alunos();

typedef float nota;

typedef struct Notas
{
    nota P1;
    nota P2;
    nota P3;
    nota P4;
} Notas;

typedef struct aluno_registro
{
    char nome[250];
    int ra;
    Notas notas;
    float media;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int i = -1;

void main(){

    char opcao;
    short int sair = 0;

    do {

        printf("Selecione uma opção: (c) Cadastrar, (p) Pesquisar, (l) Listar, (s) Sair\n");
        scanf("%c", &opcao);
        getchar();

        switch (opcao){

            case 'c':
                cadastrar_aluno();
                break;
            case 'p':
                pesquisar_aluno();
                break;
            case 'l':
                listar_alunos();
                break;
            case 's':
                sair = 1;
                break;
            default:
                printf("Opção inválida.\n");

        }

    } while (sair == 0);

}

void cadastrar_aluno() {

    printf("Cadastrar aluno\n");

    i++;

    printf("Digite o nome do aluno:\n");
    //memset(alunos[i].nome, '\0', 150); 
    scanf("%[^\n]s", alunos[i].nome);
    getchar();

    printf("Digite o R.A. do aluno:\n");
    scanf("%d", &alunos[i].ra);
    getchar();

    printf("Digite a nota da P1:\n");
    scanf("%f", &alunos[i].notas.P1);
    getchar();

    printf("Digite a nota da P2:\n");
    scanf("%f", &alunos[i].notas.P2);
    getchar();

    printf("Digite a nota da P3:\n");
    scanf("%f", &alunos[i].notas.P3);
    getchar();

    printf("Digite a nota da P4:\n");
    scanf("%f", &alunos[i].notas.P4);
    getchar();

    alunos[i].media = (alunos[i].notas.P1+
    alunos[i].notas.P2+
    alunos[i].notas.P3+
    alunos[i].notas.P4)/4;

    printf("Média: %f\n", alunos[i].media);

}

void pesquisar_aluno(){
    int ra, j;
    int encontrou = -1;

    printf("Digite o R.A. do aluno:\n");
    scanf("%d", &ra);
    getchar();

    printf("Pesquisando aluno com RA: %d \n", ra);

    for (j = 0; j <= i; j++){
        if (alunos[j].ra == ra)
            encontrou = j;
    }

    if (encontrou > -1){
        mostrar_aluno(encontrou);
    } else {
        printf("Aluno não encontrado.\n");
    }
}

void mostrar_aluno(int id){
    printf("Mostrar aluno\n");
    printf("%d - %s Média: %f \n", id, alunos[id].nome, alunos[id].media);
}

void listar_alunos(){
    int j;

    printf("Listar alunos\n");

    for (j = 0; j <= i; j++){
        printf("%d - %s \n", j, alunos[j].nome);
    }
}
