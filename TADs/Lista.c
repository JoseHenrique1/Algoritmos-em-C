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

//lista de contatos
typedef struct lista{
  Nodo *inicio;
}Lista;

Lista * criarLista() {
  Lista * list = (Lista*)malloc(sizeof(Lista));
  list->inicio = NULL;
  return list;
}

void inserir(Lista *list, char nome[100], char telefone[20])
{
  Nodo * novo = (Nodo*)malloc(sizeof(Nodo));
  novo->anterior = NULL;
  (*novo).proximo = NULL;

  //copiando a string recebida dentro da estrutura contato
  strcpy(novo->contato.nome, nome);
  strcpy(novo->contato.telefone, telefone);

  if(list->inicio == NULL)
  {
    list->inicio = novo;
  }

  else 
  {
    Nodo *aux = list->inicio;
    int comp = strcmp(nome, aux->contato.nome);
    while (comp>0 && aux->proximo!=NULL)
    {
      aux = aux->proximo;
      comp = strcmp(nome, aux->contato.nome);
    }

    if (comp>0)
    {
      aux->proximo = novo;
      novo->anterior = aux;
    }

    else if (list->inicio == aux)
        {
          aux->anterior = novo;
          novo->proximo = aux;
          list->inicio = novo;
        }

        else
        {
          novo->anterior = aux->anterior;
          novo->proximo = aux;
          aux->anterior->proximo = novo;
          aux->anterior = novo;
        }
    
  }
}
   




void main() {}
