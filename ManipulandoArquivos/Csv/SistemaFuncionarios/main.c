#include "metodos.c"
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
void renderizar (FILE *file ,Funcionario * banco) {
    int cond = 1;
    while (cond)
    {
        printf("\n\n 1 - Criar funcionario \n 2 - Ver funcionario\n 3 - Editar funcionario\n 4 - Deletar funcionario\n 5 - Todos funcionarios\n 6 - Sair\n\n");
        int opcao;
        scanf("%d", &opcao);
        system("clear");

        if (opcao == 1)
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
    Funcionario banco[5];  
    ZerarMatriculas(banco);  
    
    file = fopen("banco.csv","r");
    LoadData(file, banco);
    fclose(file);

    renderizar(file, banco);

    file = fopen("banco.csv","w");
    SaveData(file, banco);
    fclose(file);
}