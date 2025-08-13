#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void gera_matriz(int mat[N][N]) {
    int i, j;
    srand(time(NULL));
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

void escreve_soma_diagonal(int mat[N][N]) {
    int i, j, acc = 0;

    for(i=0; i<N; i++) {
        // for(j=0; j<N; j++) {
        //     if(i == j) {  // Isto gera complexidade O(N2)
        //         acc +=mat[i][j];
        //     }
        // }
        // Isto é mais simples, e funciona sem a necessidade de comparações
        // É plausível somar acessando diretamente os valores alvo
        // A complexidade aqui é O(N)
        acc += mat[i][i];
    }
    printf("A soma da diagonal é: %d\n", acc);
}

int main () {
    int mat[N][N];
    
    gera_matriz(mat);
    
    escreve_soma_diagonal(mat);
    
    return 0;
}