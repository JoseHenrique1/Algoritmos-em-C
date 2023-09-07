#include <stdio.h>

//caminho para vscode, mas se for replit basta: texto.txt
char path[13] = "../texto.txt";


//escrevendo uma linha no final
void escreverLinha(FILE *file, char texto[]) {
    fputs(texto, file);
    fputs("\n", file);
}

//apagando o conteudo do arquivo
void apagarTudo(FILE *file) {
    file = fopen(path, "w");
}

void imprimirArquivo(FILE *file){
    char linha[40];

    printf("\n");
    //feof(file) retorna 0 enquanto nao estamos no fim do arquivo
    while (feof(file) == 0) {
        fgets(linha, 30, file);
        printf(" %s", linha);
    }
    printf("\n");
}


void main () {
    char texto[30] = "Alterando arquivo txt 3 vezes";
    //FILE *file = fopen(path, "w");
    FILE* file = fopen(path, "a");

    escreverLinha(file, texto);
    escreverLinha(file, texto);
    escreverLinha(file, texto);

    // so pode imprimir se o arquivo estiver aberto em r
    file = fopen(path, "r");
    imprimirArquivo(file);

    //apagarTudo(file)

    fclose(file);

    
    
}