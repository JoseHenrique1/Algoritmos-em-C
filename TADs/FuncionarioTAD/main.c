#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"




void main (){
    FILE *file; 
    file = fopen("banco.csv","r");
    if (file == NULL)
    {
        file = fopen("banco.csv","w");
        fclose(file);
        file = fopen("banco.csv","r");
    }
    
    Lista * lista =  criarLista();
    LoadData(file, lista);
    fclose(file);

    int cond = 1;
    while (cond)
    {
        system("clear");
        printf("\n 1 - criar\n 2 - ver\n 3 - editar \n 4 - excluir\n 5 - ver todos\n 6 - sair e salvar\n ");
        int op = 0;
        scanf("%d", &op);
        system("clear");
        if (op == 1){
            float salario;
            char nome[20];
            char cargo[20];
            printf("\n nome: ");
            scanf("%s", nome);
            printf("\n salario: ");
            scanf("%f", &salario);
            printf("\n cargo: ");
            scanf("%s", cargo);
            push(lista, nome, salario, cargo);
        }
        else if (op == 2){
            int matricula = 0;
            printf("\n matricula: ");
            scanf("%d", &matricula);
            Nodo * funcionario = localizarFuncionario(lista, matricula);
            if (funcionario)
            {
                printFuncionario(&(funcionario->funcionario));
            }
            
            char buffer[20];
            scanf("%s", buffer);
            fflush(stdin);
        }
        else if (op == 3){
            int matricula;
            float salario;
            char nome[20];
            char cargo[20];
            printf("\n matricula: ");
            scanf("%d", &matricula);
            printf("\n nome: ");
            scanf("%s", nome);
            printf("\n salario: ");
            scanf("%f", &salario);
            printf("\n cargo: ");
            scanf("%s", cargo);
            editar(lista, matricula, nome, salario, cargo);
        }
        else if (op == 4){
            int matricula = 0;
            printf("\n matricula: ");
            scanf("%d", &matricula);
            excluir(lista, matricula);
        }
        else if (op == 5){
            printLista(lista);
            
            char buffer[20];
            printf("\nalgo + enter");
            scanf("%s", buffer);
            fflush(stdin);
        }
        else if (op == 6){
            cond = 0;
            printf("Saindo ...");
            file = fopen("banco.csv","w");
            SaveData(file, lista);
            //depois que salvar, os dados da ram devem ser apagados
            fclose(file);
        }
        else {
            printf("tecla errada");
        }   
    }
}