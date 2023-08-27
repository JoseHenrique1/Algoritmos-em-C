#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int numero;
    struct nodo *proximo;
}Nodo;

typedef struct pilha
{
    Nodo * topo;
}Pilha;

Pilha *criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha *p, int n) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->numero = n;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    Nodo *aux = p->topo;
    int resultado = aux->numero;
    p->topo = aux->proximo;
    free(aux);
    return resultado;
}

int estaVazia (Pilha *p) {
    if (p->topo == NULL) {
        return 1;
    }
    return 0;  
}

void main () {
    Pilha *p = criarPilha();
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);
    while (n!=0) {
        push(p, n);
        printf("Informe um numero: ");
        scanf("%d", &n);     
    }

    printf("Os numeros informados foram: \n");
    while (estaVazia(p) == 0) {
        n = pop(p);
        printf("%d \n", n);
    }
    

}
