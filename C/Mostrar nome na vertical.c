#include <stdio.h>
#include <string.h>

short int isVogal(char c);
int countVogais(char nome[150]);

main(){

    char nome[150];
    int i;

    memset(nome, '\0', 150); //Sempre usar memset antes de strlen

    printf("Digite um nome\n");

    scanf("%[^\n]s", nome); //Não há a necessidade de usar o & para string

    for (i = 0; i < strlen(nome); i++) {

        printf("%c\n", nome[i]);

    }

    printf("Número de vogais: %d", countVogais(nome));

}

short int isVogal(char c){
    char vogais[5];
    int i;
    vogais[0] = 'a';
    vogais[1] = 'e';
    vogais[2] = 'i';
    vogais[3] = 'o';
    vogais[4] = 'u';

    for(i=0;i<5;i++){
        if (c == vogais[i])
            return 1;
    }
    return 0;
}

int countVogais(char nome[150]){
    int count = 0, i;
    for (i=1;i<strlen(nome);i++){
        if (isVogal(nome[i]))
            count++;
    }
    return count;
}
