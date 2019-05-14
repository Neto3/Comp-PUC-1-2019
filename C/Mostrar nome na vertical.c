#include <stdio.h>
#include <string.h>
#include <ctype.h>

short int isVowel(char);
char* getVowels(char[]);

int main(){

    char full_name[150];
    int i, vowels_count;
    char* vowels;

    memset(&full_name, '\0', 150); //Sempre usar memset antes de strlen

    printf("What's your full name?\n");

    scanf("%[^\n]s", full_name); //Nao ha a necessidade de usar o & para string

    printf("Let's see your name in vertical:\n");

    for (i = 0; i < strlen(full_name); i++) {

        printf("%c\n", full_name[i]);

    }

    vowels = getVowels(full_name);

    vowels_count = strlen(vowels);

    if (vowels_count > 0) {

        if (vowels_count == 1)
            printf("There is 1 vowel in your name: %s.", vowels);
        else
            printf("There are %d vowels in your name: %s.", vowels_count, vowels);

    }
    else
        printf("There are no vowels in your name.");



    return(0);

}

short int isVowel(char testing_char){

    char vowels[5] = {'a','e','i','o','u'};
    int i;

    for (i = 0; i < 5; i++) {
        if (tolower(testing_char) == vowels[i])
            return(1);
    }

    return(0);

}

char* getVowels(char name[150]) {

    char vowels[150];
    int count = 0, i;

    memset(&vowels, '\0', 150);

    for (i = 0; i < strlen(name); i++) {

        if (isVowel(name[i])){

            vowels[count] = name[i];
            count++;

        }

    }

    return(vowels);

}