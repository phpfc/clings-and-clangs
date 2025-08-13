#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main() {
    int mat[N][N];
    int i, j;
    
    srand(time(NULL)); // Isto gera seeds diferentes, baseadas na variação do retorno de time() srand -> seed rand
    for(i=0; i<N; i++) {
        for(j=0; j < N; j++) {
            // printf("Digite o valor:\n");
            // scanf("%d", &mat[i][j]);
            mat[i][j] = rand() % 100;  // Desta forma valores aleatórios são gerados até 100. Mas sempre com mesmo valor (sem seed)
        }    
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j < N; j++) {
            printf("% 5d", mat[i][j]);    // Antecede o conteúdo com espaço ao limite de 5 caracteres
        }    
        printf("\n");
    }
    // Iteração em matriz bidimensional linha a linha.
    
    // for(j=0; j < 3; j++) {
    //     printf("Digite o valor:\n");
    //     scanf("%d", &mat[1][j]);
    // }
    // for(j=0; j < 3; j++) {
    //     printf("Digite o valor:\n");
    //     scanf("%d", &mat[2][j]);
    // }
}