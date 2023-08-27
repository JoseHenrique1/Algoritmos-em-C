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

void inserir(Lista *list, char nome[100], char telefone[20]){
    Nodo * novo = (Nodo*)malloc(sizeof(Nodo));
    novo->anterior = NULL;
    novo->proximo = NULL;
    strcpy(novo->contato.nome, nome);
    strcpy(novo->contato.telefone, telefone);

    if (list->inicio == NULL) {
        list->inicio = novo;
    }
    else {
        Nodo * aux = list->inicio;
        int comp = strcmp(nome, aux->contato.nome);

        //verifica se o nome possa vir a ser o primeiro da lista
        if (comp<0) {
            aux->anterior = novo;
            novo->proximo = aux;
            list->inicio = novo;
        }

        //percorrer a lista e ver se ele ta no final ou entre elementos
        else {

            //anda com o aux at� o nome ficar na posicao certa! em ordem alfabetica
            while (comp>0 && aux->proximo != NULL) {
                aux = aux->proximo;
                comp = strcmp(nome, aux->contato.nome);
            }

            //verficar se ta entre elementos
            if (comp < 0) {
                novo->anterior = aux->anterior;
                aux->anterior->proximo = novo;
                aux->anterior = novo;
                novo->proximo = aux;
            }
            //como nao esta entre elementos, o aux esta no final da lista.
            // como ele esta no final o novo.proximo == null
            else {
              printf("algo...");



            }

            }


        }
}




void main() {

    Lista * list = criarLista();
    char nome[100];
    char telefone[100];

    printf("Nome: ");
    gets(nome);

    printf("Telefone: ");
    gets(telefone);

  /*
  while(strcmp("000", nome)) {

  }
  */


}
