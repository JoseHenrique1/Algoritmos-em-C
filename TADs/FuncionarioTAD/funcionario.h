typedef struct funcionario {
    int matricula;
    char nome[30];
    float salario;
    char cargo[30];
} Funcionario;


void preencherFuncionario (Funcionario * funcionario,int matricula,  char nome[], float salario, char cargo[]);

void editarFuncionario (Funcionario * funcionario, char nome[], float salario, char cargo[]);

void printFuncionario(Funcionario * funcionario);