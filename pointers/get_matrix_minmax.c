/*
  5) Na Teoria de Sistemas, define-se como elemento minimax de uma matriz 
  o menor elemento da linha em que se encontra o maior elemento da matriz. 
  Faça uma função que receba como parâmetro uma matriz A[5][5] e retorne o 
  valor do elemento minimax, bem como a linha e coluna onde ocorreu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void get_matrix_minmax(int m[N][N], int *minmax, int *idx_row, int *idx_col) {
  int max_val = m[0][0];
  int max_row = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (m[i][j] > max_val) {
        max_val = m[i][j];
        max_row = i;
      }
    }
  }

  *minmax = m[max_row][0];
  *idx_row = max_row + 1;
  *idx_col = 0;

  for (int j = 0; j < N; j++) {
    if (m[max_row][j] < *minmax) {
      *minmax = m[max_row][j];
      *idx_col = j + 1;
    }
  }

};

void create_matrix(int m[N][N]) {
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      m[i][j] = rand() % 100;
    }
  }
}

void print_matrix(int m[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("% 3d", m[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int matrix[N][N];
  int minmax;
  int idx_row = 0;
  int idx_col = 0;

  create_matrix(matrix);
  print_matrix(matrix);
  get_matrix_minmax(matrix, &minmax, &idx_row, &idx_col);

  printf("The minmax value is %d at row %d, column %d\n", minmax, idx_row, idx_col);
}
