#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

struct no {
    int dado;
    struct no *prox;
};

typedef struct {
    struct no *topo;    
} pilha;

void create(pilha *s);
int push(pilha *s, int d);
int pop(pilha *s, int *d);
int isEmpty(pilha s);

void main() {
    int n;
    pilha p1;

    create(&p1);

    if (push(&p1, 1))
        printf("Dado adicionado a pilha.\n");
    push(&p1, 2);
    push(&p1, 3);

    if (!isEmpty(p1)) {
        pop(&p1, &n);
        printf("Dado desempilhado: %d\n", n);
    }
}

void create(pilha *s) {
    s->topo = NULL;
}

int push(pilha *s, int d) {
    struct no *aux;
    aux = (struct no *)malloc(sizeof(struct no));
    if (aux == NULL)
        return FALSE;
    aux->dado = d;
    aux->prox = s->topo;
    s->topo = aux;
    return TRUE;
}

int pop(pilha *s, int *d) {
    struct no *aux;
    if (s->topo == NULL)
        return FALSE;
    aux = s->topo;
    s->topo = (s->topo)->prox;
    *d = aux->dado;
    free(aux);
    return TRUE;
}

int isEmpty(pilha s) {
    if (s.topo == NULL)
        return TRUE;
    return FALSE;
}