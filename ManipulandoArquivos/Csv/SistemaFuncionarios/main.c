#include <stdio.h>
#include <string.h>

/*
carregar dados do csv no vetor  - mec
savar dados do vetor no csv
imprimir todos os funcionarios  - mec

crud - funcionarios

C
R
U
D

*/

typedef struct funcionario {
    int matricula;
    char nome[50];
    float salario;
    char cargo[50];
} Funcionario;

void LoadData(FILE *file, Funcionario banco[]) {
    int i;
    for (i = 0; !feof(file) || i<5; i++) {
        char linha[100];
        char *campo;

        fgets(linha, sizeof(linha), file);

        //strtok pega parte de uma string até um determinado caractere
        campo = strtok(linha, ",");
        banco[i].matricula = atoi(campo); //atoi faz um cast de string para int

        campo = strtok(NULL, ",");
        strcpy(banco[i].nome, campo);
        
        campo = strtok(NULL, ",");
        banco[i].salario = atof(campo);//atof faz um cast de string para float

        campo = strtok(NULL, "\n");
        strcpy(banco[i].cargo, campo);
    }
}

void PrintFuncionarios (Funcionario banco[]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d - %s - %.2f - %s\n", banco[i].matricula, banco[i].nome, banco[i].salario, banco[i].cargo);
    }
}





void main() {
    FILE *file;
    Funcionario banco[5];    
    
    file = fopen("banco.csv","r");
    LoadData(file, banco);
    fclose(file);

    PrintFuncionarios(banco); 
}