#include <stdio.h>
int max_linha = 0;
int max_coluna = 0;
int tamanho = 0;

//altera as variaveis globais
void dimensionar_matriz(int linha, int colunas) {
    max_linha = linha;
    max_coluna = colunas;
    tamanho = linha*colunas;
}

void zerar_matriz(int vet[]) {
    int k;
    for (k=0;k<tamanho;k++){
        vet[k] = 0;
    }
}

void imprimir_matriz(int vet[]) {
    int k;
    for (k=0;k<tamanho;k++){
        printf("%d     ", vet[k]);
        //imprimindo de forma bidimensional
        if ((k+1)%max_coluna == 0) {
            printf("\n");
        }
    }
}

void inserir_elemento(int vet[], int num, int linha, int coluna) {

    //usuário não considera o 0!
    linha = linha - 1;
    coluna = coluna -1;
    //formula: posicao =  linha * n + coluna
    int posicao = linha*max_coluna+coluna;
    vet[posicao] = num;
}

int buscar_elemento(int vet[], int linha, int coluna) {
    //usuário não considera o 0!
    linha = linha - 1;
    coluna = coluna -1;
    //formula: posicao =  linha * n + coluna
    int posicao = linha*max_coluna+coluna;
    return vet[posicao];

}
void main() {
    dimensionar_matriz(4,5);

    //vetor que simula a matriz
    int vet[tamanho];

    zerar_matriz(vet);
    imprimir_matriz(vet);
    printf("\n\n");

    
    inserir_elemento(vet, 20, 1, 1);
    inserir_elemento(vet, 20, 1, 2);
    inserir_elemento(vet, 20, 2, 1);
    inserir_elemento(vet, 20, 1, 3);

    imprimir_matriz(vet);

    int num = buscar_elemento(vet, 1, 1);
    printf("\n num =  %d \n", num);


}