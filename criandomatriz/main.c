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

void inserir(int vet[], int num, int linha, int coluna) {
    //supondo que o total de colunas seja 3!
    int posicao = linha*3+coluna;
    vet[posicao] = num;
}

void main() {
    int linha = 3;
    int coluna = 3;
    int tamanho = linha*coluna;

    //vetor que simula a matriz
    int vet[tamanho];

    zerar(vet, tamanho);
    imprimir(vet, tamanho);

    //numero qualquer para realizar a inserção
    int num = 298;
    inserir(vet, num, 0, 0);

    imprimir(vet, tamanho);


}