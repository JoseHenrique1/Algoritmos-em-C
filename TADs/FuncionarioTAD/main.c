#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int matricula;
    char nome[30];
    float salario;
    char cargo[30];
} Funcionario;

typedef struct nodo{
    Funcionario funcionario;
    struct nodo * anterior;
    struct nodo * posterior;
}Nodo;

typedef struct lista{
    Nodo * inicio;
    Nodo * fim;
}Lista;

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




void main (){
    FILE *file; 
    file = fopen("banco.csv","r");
    Lista * lista =  criarLista();
    LoadData(file, lista);
    fclose(file);

    int cond = 1;
    while (cond)
    {
        system("clear");
        printf("\n 1 - criar\n 2 - ver\n 3 - editar \n 4 - excluir\n 5 - ver todos\n 6 - sair\n ");
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
            printf("\n%d \n%s \n%f \n%s", funcionario->funcionario.matricula, funcionario->funcionario.nome, funcionario->funcionario.salario, funcionario->funcionario.cargo);
            
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