#include "funcionario.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void preencherFuncionario (Funcionario * funcionario,int matricula, char nome[], float salario, char cargo[]) {
    funcionario->matricula = matricula;
    strcpy(funcionario->nome, nome);
    funcionario->salario = salario;
    strcpy(funcionario->cargo, cargo);
}

void editarFuncionario (Funcionario * funcionario, char nome[], float salario, char cargo[]) {
    strcpy(funcionario->nome, nome);
    funcionario->salario = salario;
    strcpy(funcionario->cargo, cargo);
}

void printFuncionario(Funcionario * funcionario) {
    printf("\n -------------");
    printf("\n matricula: %d", funcionario->matricula);
    printf("\n %s", funcionario->nome);
    printf("\n %f R$", funcionario->salario);
    printf("\n %s", funcionario->cargo);
}


