
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tamanhoBD = 5;

typedef struct funcionario {
    int matricula;
    char nome[30];
    float salario;
    char cargo[30];
} Funcionario;


// ----> CSV

void LoadData(FILE *file, Funcionario banco[]) {
    int i;
    for (i = 0; (i<tamanhoBD); i++) {
        char linha[150];
        char *campo;

        fgets(linha, sizeof(linha), file);
        if (feof(file) == 1) {
            
            break;
        }

        //strtok pega parte de uma string até um determinado caractere
        campo = strtok(linha, ",");
        banco[i].matricula = atoi(campo); //atoi faz um cast de string para int

        //printf("\nmatricula %d \n", banco[i].matricula);

        campo = strtok(NULL, ",");
        strcpy(banco[i].nome, campo);
        
        campo = strtok(NULL, ",");
        banco[i].salario = atof(campo);//atof faz um cast de string para float
        //coloque atoi caso de erro
        campo = strtok(NULL, "\n");
        strcpy(banco[i].cargo, campo);
    }
}


void SaveData(FILE * file, Funcionario banco []){
    // file no W write
    int k;
    for (k=0;k < tamanhoBD; k++)
    {
        if (banco[k].matricula != 0)
        {
            fprintf(file,"%d,%s,%f,%s\n", banco[k].matricula, banco[k].nome, banco[k].salario, banco[k].cargo);
        }
        
    }
    
}


// ---->UTILITARIOS

void PrintFuncionarios (Funcionario banco[]) {
    int i;
    for (i = 0; i < tamanhoBD; i++) {
        if (banco[i].matricula != 0)
        {
            printf("%d - %s - %.2f - %s\n", banco[i].matricula, banco[i].nome, banco[i].salario, banco[i].cargo);
        }
        
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


// ----> C R U D

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
    else {printf("Banco está cheio");}
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
            banco[k].matricula = 0;
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






void renderizar (FILE *file ,Funcionario * banco) {
    int cond = 1;
    while (cond)
    {
        printf("\n\n----------MENU---------\n 1 - Criar funcionario \n 2 - Ver funcionario\n 3 - Editar funcionario\n 4 - Deletar funcionario\n 5 - Todos funcionarios\n 6 - Sair\n\n");
        int opcao;
        scanf("%d", &opcao);
        system("clear");

        if (opcao == 1)
        {
            if (BancoFull(banco) == 0)
            {
                printf("\nNome:");
                char nome[20];
                scanf("%s", nome);
                fflush(stdin);

                printf("\nSalario:");
                float salario;
                scanf("%f", &salario);
                fflush(stdin);

                printf("\nCargo:");
                char cargo[20];
                scanf("%s", cargo);
                fflush(stdin);

                pushFuncionario(banco, nome, salario, cargo);
            }
            else {printf("Banco esta cheio");}
            
            
            
        }
        else if (opcao == 2)
        {
            printf("\n \n Matricula: ");
            int matricula;
            scanf("%d", &matricula);
            Funcionario funcionario = GetFuncionario(banco, matricula);
            printf("%s %f %s \n\n", funcionario.nome, funcionario.salario, funcionario.cargo);
            
        }
        else if (opcao == 3)
        {

            printf("\n \n Matricula: ");
            int matricula;
            scanf("%d", &matricula);

            printf("\nNome:");
            char nome[20];
            scanf("%s", nome);
            fflush(stdin);

            printf("\nSalario:");
            int salario;
            scanf("%d", &salario);
            fflush(stdin);

            printf("\nCargo:");
            char cargo[20];
            scanf("%s", cargo);
            fflush(stdin);
            
            UpdateFuncionario(banco, matricula, nome, salario, cargo);
        }
        else if (opcao == 4)
        {
            printf("\n \n Matricula: ");
            int matricula;
            scanf("%d", &matricula);
            ExcluirFuncionario(banco, matricula);
        }
        else if (opcao == 5)
        {
            PrintFuncionarios(banco); 
        }
        else if (opcao == 6)
        {
            printf("Saindo ...");
            cond = 0;

            //Ao sair o programa salva os dados e fecha o arquivo 
            file = fopen("banco.csv","w");
            SaveData(file, banco);
            fclose(file);
        }
        else {
            printf("tecla errada");
        }
        
        
    }
}

void main() {
    
    FILE *file;
    Funcionario banco[tamanhoBD];  
    ZerarMatriculas(banco);  
    
    file = fopen("banco.csv","r");
    if (file == NULL)
    {
        file = fopen("banco.csv","w");
        fclose(file);
        file = fopen("banco.csv","r");
    }
    LoadData(file, banco);
    fclose(file);

    renderizar(file, banco);

    file = fopen("banco.csv","w");
    SaveData(file, banco);
    fclose(file);
}