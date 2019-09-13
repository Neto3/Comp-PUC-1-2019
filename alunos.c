#include <stdio.h>

typedef struct {
    int ra;
    char nome[200];
    char nasc[11];
} Aluno;

typedef struct {
    int id;
    char sigla[10];
    char nome[50];
} Disciplina;

typedef struct {
    int id;
    int ra;
    int id_disc;
    int ano;
    int semestre;
} Aluno_Disc;

void mostrarMenuPrincipal();
void mostrarMenuGerenciamento(int t);
void insere(int t);
void altera(int t);
void consulta(int t);
void exlui(int t);
void submenuListOrd();
void mostrarListagem(int t);
void ordenar(int t);


Aluno alunos[100];
Disciplina disciplinas[50];
Aluno_Disc aluno_discs[1000];

int alunos_inseridos = 0, disciplinas_inseridas = 0, aluno_discs_inseridos = 0;


void main(){
    int sair = 0, opcao;

    do {

        mostrarMenuPrincipal();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarMenuGerenciamento(1);
                break;
            case 2:
                mostrarMenuGerenciamento(2);
                break;
            case 3:
                mostrarMenuGerenciamento(3);
                break;
            case 4:
                submenuListOrd();
                break;
            case 5:
                submenuListOrd();
                break;
        }

    } while (sair == 0);
}


void mostrarMenuPrincipal(){
    printf("[1] Gerenciamento de Aluno\n");
    printf("[2] Gerenciamento de Disciplina\n");
    printf("[3] Gerenciamento Aluno-Disciplina\n");
    printf("[4] Mostrar Listagem\n");
    printf("[5] Ordenar\n");
    printf("[6] Sair\n");
}
void mostrarMenuGerenciamento(int t){
    int opcao2;

    printf("[1] Inserir\n");
    printf("[2] Alterar\n");
    printf("[3] Consultar\n");
    printf("[4] Excluir\n");

    scanf("%d", &opcao2);

    switch (opcao2) {
        case 1:
            insere(t);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }

}

void insere(int t){

    Aluno aluno;
    Disciplina disciplina;
    Aluno_Disc aluno_disc;

    switch (t) {
        case 1:
            printf("Digite o RA do novo aluno:\n");
            scanf("%d", &aluno.ra);
            printf("Digite o nome do novo aluno:\n");
            scanf("%s", &aluno.nome);
            printf("Digite a data de nascimento do novo aluno:\n");
            scanf("%s", &aluno.nasc);
            alunos[alunos_inseridos] = aluno;
            alunos_inseridos++;
            break;
        case 2:
            printf("Digite o ID da nova disciplina:\n");
            scanf("%d", &disciplina.id);
            printf("Digite a sigla da nova disciplina:\n");
            scanf("%s", &disciplina.sigla);
            printf("Digite o nome da nova discplina:\n");
            scanf("%s", &disciplina.nome);
            disciplinas[disciplinas_inseridas] = disciplina;
            disciplinas_inseridas++;
            break;
        case 3:
            printf("Digite o RA do aluno:\n");
            scanf("%d", &aluno_disc.ra);
            printf("Digite o ID disciplina:\n");
            scanf("%d", &aluno_disc.id_disc);
            printf("Digite o ano:\n");
            scanf("%d", &aluno_disc.ano);
            printf("Digite o semestre:\n");
            scanf("%d", &aluno_disc.semestre);
            aluno_discs[aluno_discs_inseridos] = aluno_disc;
            alunos_inseridos++;
            break;
    }

}
void altera(int t){

    switch (t) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }

}
void consulta(int t){

    switch (t) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }

}
void exlui(int t){

    switch (t) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    } 

}

void submenuListOrd(){
    
    int opcao2;

    printf("[1] Alunos\n");
    printf("[2] Disciplinas\n");
    printf("[3] Alunos-Disciplinas\n");

    scanf("%d", &opcao2);

    switch (opcao2) {
        case 1:
            mostrarListagem(1);
            break;
        case 2:
            mostrarListagem(2);
            break;
        case 3:
            mostrarListagem(3);
            break;
    }

}
void mostrarListagem(int t){

    int i;

    switch (t) {
        case 1:
            printf("Listagem de alunos:\n");
            for (i = 0; i < alunos_inseridos; i++){
                printf("%d, %s, %s\n", alunos[i].ra, alunos[i].nome, alunos[i].nasc);
            }
            break;
        case 2:
            printf("Listagem de disciplinas:\n");
            for (i = 0; i < disciplinas_inseridas; i++){
                printf("%d, %s, %s\n", disciplinas[i].id, disciplinas[i].sigla, disciplinas[i].nome);
            }
            break;
        case 3:
            printf("Listagem Alunos-Disciplinas:\n");
            for (i = 0; i < aluno_discs_inseridos; i++){
                printf("%d, %d, %d, %d\n", aluno_discs[i].ra, aluno_discs[i].id_disc, aluno_discs[i].ano, aluno_discs[i].semestre);
            }
            break;
    }
}
void ordenar(int t){}