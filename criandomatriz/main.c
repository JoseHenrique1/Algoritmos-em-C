#include <stdio.h>



void zerar(int vet[], int tamanho) {
    int k;
    for (k=0;k<tamanho;k++)
    {
        vet[k] = 0;
    }
}

void imprimir(int vet[], int tamanho) {
    int k;
    for (k=0;k<tamanho;k++)
    {
        printf("%d ", vet[k]);
    }

}

void inserir(int vet[], int num, int linha, int coluna, int max_coluna) {
    //formula linha * n + coluna
    int posicao = linha*max_coluna+coluna;
    vet[posicao] = num;
}

void main() {
    int max_linha = 3;
    int max_coluna = 3;
    int tamanho = max_linha*max_coluna;

    //vetor que simula a matriz
    int vet[tamanho];

    

    zerar(vet, tamanho);
    imprimir(vet, tamanho);

    //numero qualquer para realizar a inserção
    int num = 298;
    inserir(vet, num, 0, 0, max_coluna);

    imprimir(vet, tamanho);


}