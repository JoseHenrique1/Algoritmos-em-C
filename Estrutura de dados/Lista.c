/*Lista duplamente encadeada:
    Simula o app contatos...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[100];
  char telefone[20];
}Pessoa;

typedef struct nodo {
  struct nodo *anterior;
  Pessoa contato;
  struct nodo *proximo;
}Nodo;

typedef struct lista{
  Nodo *inicio;
}Lista;

Lista * criarLista() {
  Lista * list = (Lista*)malloc(sizeof(Lista));
  list->inicio = NULL;
  return list;
}

void inserir(Lista *list, char nome[100], char telefone[20]){}
   




void main() {}
