#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int numero;
    struct nodo *proximo;
}Nodo;


typedef struct fila {
    struct nodo * inicio;
    
} Fila;


Fila * criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    return f;
}

void inserir(Fila *f, int n) {
    Nodo * novo = (Nodo*)malloc(sizeof(Nodo));
    (*(*f).inicio).numero = n;
    novo->proximo = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
    }
    else {
        Nodo *aux = f->inicio;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        aux->proximo = novo;   
    }
}

int remover (Fila * f)
{
    Nodo *aux = f->inicio;
    int resultado = aux->numero;
    f->inicio = aux->proximo;
    free(aux);
    return resultado;   
}

int estaVazia(Fila *f)
{
    if(f->inicio == NULL)
    {
        return 1;
    }

    return 0;
}

void main () {}