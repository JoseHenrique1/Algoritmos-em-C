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

void soma_matriz(int vet1[], int vet2[], int vet3[]) {
  int i, j;
  for (i = 1; i <= max_linha; i++) {
    for (j = 1; j <= max_coluna; j++) {
      int val1 = buscar_elemento(vet1, i, j);
      int val2 = buscar_elemento(vet2, i, j);
      int soma = val1 + val2;
      inserir_elemento(vet3, soma, i, j);
    }
  }
}

void imprimir_matriz(int vet[]) {
    int l,c, num;
    for (l=1;l<=max_linha;l++){
        for (c=1;c<=max_coluna;c++){
            num = buscar_elemento(vet, l, c);
            printf("  %d", num);
        }
        printf("\n");
    }

    printf("\n");
}

void zerar_matriz(int vet[]) {
    int l,c;
    for (l=1;l<=max_linha;l++){
        for (c=1;c<=max_coluna;c++){
            inserir_elemento(vet, 0, l, c);
        }
    }
}

void main() {
    dimensionar_matriz(2,2);

    //vetor que simula a matriz
    int vet1[tamanho];
    int vet2[tamanho];
    int vet3[tamanho];//vetor da soma

    zerar_matriz(vet1);
    zerar_matriz(vet2);
    zerar_matriz(vet3);

    inserir_elemento(vet1, 5, 1, 1);
    inserir_elemento(vet1, 5, 1, 2);
    
    inserir_elemento(vet2, 5, 1, 1); 
    inserir_elemento(vet2, 5, 1, 2);


    
    soma_matriz(vet1, vet2, vet3);

    imprimir_matriz(vet1);
    imprimir_matriz(vet2);
    imprimir_matriz(vet3);
    printf("\n\n Buscando na posicao 1 - 1:  ");
    int num = buscar_elemento(vet1, 1, 1);
    printf("%d \n", num);




}