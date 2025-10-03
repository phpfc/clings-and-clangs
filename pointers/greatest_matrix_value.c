/*
  4) Faça uma função que receba como parâmetro uma matriz M[5][5] 
  e retorne o maior valor existente na matriz, bem como a linha e 
  coluna onde o valor ocorre.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void get_greatest_value_in_matrix(int m[N][N], int *greatest, int *idx_row, int *idx_col) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (*greatest < m[i][j]) {
        *greatest = m[i][j];
        *idx_row = i + 1;
        *idx_col = j + 1;
      }
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
  int greatest = 0;
  int idx_row = 0;
  int idx_col = 0;

  create_matrix(matrix);
  print_matrix(matrix);
  get_greatest_value_in_matrix(matrix, &greatest, &idx_row, &idx_col);

  printf("The greatest value is %d at row %d, column %d\n", greatest, idx_row, idx_col);
}
