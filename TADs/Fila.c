#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
    int numero;
    struct nodo * proximo;

} Nodo;

typedef struct fila {
    Nodo * inicio;

}Fila;

Fila * criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    return f;

}

void inserir(Fila *f, int n) {
  Nodo * novo = (Nodo*)malloc(sizeof(Nodo));
  novo->numero = n;
  novo->proximo = NULL;
  if(f->inicio == NULL) {
    f->inicio = novo;
  }
  else {
    Nodo *aux = f->inicio;
    while(aux->proximo!=NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
}

int remover(Fila *f) {
  Nodo *aux = f->inicio;
  int resultado = aux->numero;
  f->inicio = aux->proximo;
  free(aux);
  return resultado;
}

int estaVazia(Fila *f) {
  if (f->inicio == NULL) {
    return 1;
  }
  return 0;
}



void main(){
    Fila * f = criarFila();
    int n;
    printf("Informe um numero ");
    scanf("%d", &n);
    while (n!=0) {
      inserir(f, n);
      printf("Informe um numero ");
      scanf("%d", &n);
      
    }
    printf("Excluindo numeros:\n");
    while (estaVazia(f) == 0){
      n = remover(f);
      printf("%d ", n);
      
    }



}
