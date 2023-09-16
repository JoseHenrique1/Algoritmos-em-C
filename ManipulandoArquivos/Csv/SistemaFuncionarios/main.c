#include <stdio.h>
#include <string.h>


/*
carregar dados do csv no vetor  - mec
savar dados do vetor no csv     - mec
imprimir todos os funcionarios  - mec

crud - funcionarios

C - mec
R - mec
U - mec
D - mec

*/

int tamanhoBD = 5;

typedef struct funcionario {
    int matricula;
    char nome[50];
    float salario;
    char cargo[50];
} Funcionario;

void LoadData(FILE *file, Funcionario banco[]) {
    int i;
    for (i = 0; !feof(file) || i<tamanhoBD; i++) {
        char linha[100];
        char *campo;

        fgets(linha, sizeof(linha), file);

        //strtok pega parte de uma string até um determinado caractere
        campo = strtok(linha, ",");
        banco[i].matricula = atoi(campo); //atoi faz um cast de string para int

        campo = strtok(NULL, ",");
        strcpy(banco[i].nome, campo);
        
        campo = strtok(NULL, ",");
        banco[i].salario = atoi(campo);//atof faz um cast de string para float

        campo = strtok(NULL, "\n");
        strcpy(banco[i].cargo, campo);
    }
}


void SaveData(FILE * file, Funcionario banco []){
    // file no W write
    int k;
    for (k=0;k < tamanhoBD; k++)
    {
        fprintf(file,"%d, %s, %f, %s\n", banco[k].matricula, banco[k].nome, banco[k].salario, banco[k].cargo);
    }
    
}

void PrintFuncionarios (Funcionario banco[]) {
    int i;
    for (i = 0; i < tamanhoBD; i++) {
        printf("%d - %s - %.2f - %s\n", banco[i].matricula, banco[i].nome, banco[i].salario, banco[i].cargo);
    }
}

void ZerarMatriculas(Funcionario banco[]) {
    int k;
    for (k=0;k<tamanhoBD;k++) {
        banco[k].matricula = 0;
    }
}



int BancoFull(Funcionario banco[]) {
    int k;

    // se for 0 - banco tem espaco
    //se for 1 - banco cheio
    int resposta = 1;
    for (k=0;k<tamanhoBD;k++) {
        if (banco[k].matricula == 0) {
            resposta = 0;
        }
    }

    return resposta;
}

void  pushFuncionario(Funcionario banco[], char nome[], float salario, char cargo[]){
    if (BancoFull(banco) == 0) {
        Funcionario funcionario;
        strcpy(funcionario.nome, nome);
        strcpy(funcionario.cargo, cargo);
        funcionario.salario = salario;
        int k;
        for (k=0;k<tamanhoBD;k++) {
            if (banco[k].matricula == 0) {
                if (k==0) {
                    funcionario.matricula = 1;
                    banco[k] = funcionario;
                } else {
                    funcionario.matricula = banco[k-1].matricula +1;
                }
                //adicionando funcionario no banco
                banco[k] = funcionario;
                break;

            }
        }
    }
}


//FUNCAO NAO TESTADA!
//essa funcao é chamada toda vez que exclui um funcionario
void OrganizarVetor(Funcionario banco[]) {
    int k, j;
    for (k=0;k<tamanhoBD-1;k++){

        //ver se a posicao esta faltando funcionario
        if (banco[k].matricula == 0) {

            //procura se tem alguem proximo
            for (j=k+1;j<tamanhoBD;j++) {

                //verifica se a matricula é diferente de zero
                if (banco[j].matricula !=0) {

                    banco[k] = banco[j];
                    banco[j].matricula = 0;
                    //poderia trocar o nome,cargo e salaraio pra default, mas nao é um requerimento
                    /*banco[j].nome = "default"*/
                    break;
                }
            }
            
        }
    }
}

void UpdateFuncionario(Funcionario banco[], int matricula, char nome[], float salario, char cargo[]){
    int k;
    for (k=0; k < tamanhoBD; k++)
    {
        if ((banco[k].matricula == matricula) && (matricula=!0))
        {
            strcpy(banco[k].nome, nome);
            strcpy(banco[k].cargo, cargo);
            banco[k].salario = 900;
            break;
        }
        
    }
    
}

void ExcluirFuncionario(Funcionario banco[], int matricula) {
    int k;
    for (k = 0; k < tamanhoBD; k++)
    {
        if (banco[k].matricula == matricula){
            printf("\n excluir: %d \n", banco[k].matricula);
            banco[k].matricula = 0;
            printf("\n atualizado: %d \n", banco[k].matricula);
            OrganizarVetor(banco);
            break;

        }
    }
    
}

Funcionario GetFuncionario(Funcionario banco[], int matricula) {
    int k;
    for (k = 0; k <tamanhoBD; k++)
    {
        if (banco[k].matricula == matricula) {
            return banco[k];
        }
    }   
}







void main() {
    
    FILE *file;
    Funcionario banco[5];  
    ZerarMatriculas(banco);  
    
    file = fopen("banco.csv","r");
    LoadData(file, banco);
    fclose(file);

    PrintFuncionarios(banco); 
    printf("banco esta cheio: %d \n\n", BancoFull(banco) );

    printf("\n \n id: ");
    int id;
    scanf("%d", &id);
    ExcluirFuncionario(banco, id);
    PrintFuncionarios(banco);

    //funcionario novo
    pushFuncionario(banco,"jose henrique", 100, "estudante");

    printf("\n");
    PrintFuncionarios(banco);
    printf("\n");
    printf("\n");

    UpdateFuncionario(banco, 6, "jose henrique", 900, "aluno");

    PrintFuncionarios(banco);

    printf("%s \n\n", GetFuncionario(banco, 1).nome);


    file = fopen("teste.csv","w");
    SaveData(file, banco);
    fclose(file);
}