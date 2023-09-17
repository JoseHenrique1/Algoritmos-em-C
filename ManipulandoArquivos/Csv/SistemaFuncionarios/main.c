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


    file = fopen("banco.csv","w");
    SaveData(file, banco);
    fclose(file);
}