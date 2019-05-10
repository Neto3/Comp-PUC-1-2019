#include <stdio.h>

int main() {

    int n, l, c;

    printf("Informe o tamanho da linha:");
    scanf("%d", &n);
    getchar();

    l = 0;

    while (l < n) {

        c = 0;

        while (c < n - l) {
            
            printf("o");
            c++;

        }

        printf("\n");
        l++;

    }

    return(0);

}