#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"


Lista * criarLista () {
    Lista * lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void push (Lista * lista, char nome[], float salario, char cargo[]) {
    Nodo * novo = (Nodo*) malloc(sizeof(Nodo));
    novo->anterior = NULL;
    novo->posterior = NULL;

    strcpy(novo->funcionario.nome, nome);
    novo->funcionario.salario = salario;
    strcpy(novo->funcionario.cargo, cargo);

    if (lista->inicio == NULL){
        lista->inicio= novo;
        lista->fim = novo;
        novo->funcionario.matricula = 1;
    }
    else {
        novo->funcionario.matricula = lista->fim->funcionario.matricula + 1;
        novo->anterior = lista->fim;
        lista->fim->posterior = novo;
        lista->fim = novo;
    }   
}

Nodo * localizarFuncionario (Lista * lista, int matricula) {
    Nodo * aux = lista->inicio;
    do {
        if (aux->funcionario.matricula == matricula){
            return aux;
        }
        aux = aux->posterior;
    } while(aux != NULL);
    printf("Não encontrado");
    return aux;
}  



void excluir (Lista * lista, int matricula) {
    Nodo * aux = lista->inicio;
    do {
        if (aux->funcionario.matricula == matricula){
            if (aux == lista->inicio) {
                lista->inicio = aux->posterior;
                lista->inicio->anterior = NULL;
            }
            else if (aux == lista->fim) {
                lista->fim = aux->anterior;
                lista->fim->posterior = NULL; 
            }
            else {
                aux->anterior->posterior = aux->posterior;
                aux->posterior->anterior = aux->anterior;
            }
            
            free(aux);
            break;
        }
        aux = aux->posterior;
    } while(aux != NULL);
} 

void editar (Lista * lista, int matricula, char nome[], float salario, char cargo[]) {
    Nodo * aux = localizarFuncionario(lista, matricula);
    if (aux !=NULL) {
        strcpy(aux->funcionario.nome, nome);
        aux->funcionario.salario = salario;
        strcpy(aux->funcionario.cargo, cargo);
    }
}


void printLista(Lista * lista) {
    if (lista->inicio == NULL) {
        printf("\n Lista vazia \n");
    }
    else {
        Nodo * aux = lista->inicio;
        while (aux != NULL)
        {   
            printf("\n ---------");
            printf("\n %d", aux->funcionario.matricula);
            printf("\n %s", aux->funcionario.nome);
            printf("\n %f R$", aux->funcionario.salario);
            printf("\n %s", aux->funcionario.cargo);
            aux = aux->posterior;
        }
    }
}

void LoadData(FILE *file, Lista * lista) {
    char linha[150];
    char *campo;
    fgets(linha, sizeof(linha), file);
    while (feof(file) == 0)
    {
        Nodo * aux = (Nodo*) malloc(sizeof(Nodo));

        campo = strtok(linha, ",");
        aux->funcionario.matricula = atoi(campo);

        campo = strtok(NULL, ",");
        strcpy(aux->funcionario.nome, campo);
        
        campo = strtok(NULL, ",");
        aux->funcionario.salario = atof(campo);
        
        campo = strtok(NULL, "\n");
        strcpy(aux->funcionario.cargo, campo);

        fgets(linha, sizeof(linha), file);

        if (lista->inicio == NULL) {
            lista->inicio = aux;
            lista->fim = aux;
        }
        else{
            lista->fim->posterior = aux;
            aux->anterior = lista->fim;
            lista->fim = aux;
        }   
    }
}

void SaveData(FILE * file, Lista * lista){
    Nodo * aux = lista->inicio;
    while (aux != NULL)
    {
        Funcionario f = aux->funcionario;
        fprintf(file,"%d,%s,%f,%s\n", f.matricula, f.nome, f.salario, f.cargo);
        aux = aux->posterior;
    }   
}



