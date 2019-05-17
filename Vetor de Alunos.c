#include <stdio.h>

#define MAX_ALUNOS 60

typedef float nota;

typedef struct notas_registro
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


void main(){

    Aluno alunos[MAX_ALUNOS];
    int i = 0;


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