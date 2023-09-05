/*
r - leitura
w - escrita e cria arquivo
a - escreve no final
*/


#include <stdio.h>

//caminho para vscode, mas se for replit basta: texto.txt
char path[13] = "../texto.txt";


void main () {

    //ponteiro para o arquivo
    FILE *file;

    //abrindo arquivo
    file = fopen(path, "w");

    //escrevendo no arquivo
    fputs("escrevendo no arquivo...", file);

    //fechando arquivo
    fclose(file);

    ////abrindo arquivo com 'a'
    file = fopen(path, "a");

    //escrevendo no final
    fputs("escrevendo no final...", file);

    //fechando arquivo
    fclose(file);

    
    
}