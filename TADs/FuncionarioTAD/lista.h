#include "funcionario.h"

typedef struct nodo{
    Funcionario funcionario;
    struct nodo * anterior;
    struct nodo * posterior;
}Nodo;

typedef struct lista{
    Nodo * inicio;
    Nodo * fim;
}Lista;


Lista * criarLista ();

void push (Lista * lista, char nome[], float salario, char cargo[]);

Nodo * localizarFuncionario (Lista * lista, int matricula);

void excluir (Lista * lista, int matricula);

void editar (Lista * lista, int matricula, char nome[], float salario, char cargo[]);

void printLista(Lista * lista);

void LoadData(FILE *file, Lista * lista);

void SaveData(FILE * file, Lista * lista);




