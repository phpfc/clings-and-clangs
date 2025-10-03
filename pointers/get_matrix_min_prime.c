/* 
  6) Faça uma função que receba como parâmetro uma matriz M[15][15] 
  e retorne: o menor número primo da matriz e a sua respectiva posição 
  (linha e coluna). O protótipo da função é dado por:

  Protótipo da função:

  void menor_primo(int M[15][15], int *primo, int *lin, int *col)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#define N 15


bool is_prime(int num) {
  if (num <= 1) {
    return false;
  }

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

void get_matrix_min_prime(int m[N][N], int *min_prime, int *row, int *col) {
  bool has_primes = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (*min_prime > m[i][j] && is_prime(m[i][j])) {
        *min_prime = m[i][j];
        *row = i;
        *col = j;
        has_primes = true;
      }
    }
  }

  if (has_primes == false) {
    *min_prime = -1;
    *row = -1;
    *col = -1;
  }
}

void create_matrix(int m[N][N], bool primeless) {
  int ground = 12;
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int val = m[i][j] = (rand() % (100 - ground)) + ground;
      if (primeless && val % 2 != 0) val++;
      m[i][j] = val;
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
  int min_prime;
  int idx_row = 0;
  int idx_col = 0;

  create_matrix(matrix, true);
  print_matrix(matrix);
  get_matrix_min_prime(matrix, &min_prime, &idx_row, &idx_col);

  printf("The smallest prime value is %d at row %d, column %d\n", min_prime, idx_row, idx_col);
}
