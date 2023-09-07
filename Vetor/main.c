#include <stdio.h>

void main(){
    int k;
    
    int vet[5];
    for (k=0;k<5;k++){
        vet[k] = k*2;
    }
   
    
    printf("\n %d \n", &vet);
    printf("\n %d \n", vet);

    printf("######");

    printf("\n %d \n", &vet[0]);
    printf("\n %d \n", &vet[1]);
    printf("\n %d \n", &vet[2]);
    printf("\n %d \n", &vet[3]);
    printf("\n %d \n", &vet[4]);

    printf("####");

    printf("\n %d \n", &vet[5]);
    printf("\n %d \n", &vet[6]);
    
}