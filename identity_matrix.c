#include <stdio.h>
/*
M00000700 -
https://avaucs.grupoa.education/plataforma/course/3644210/content/46177802
    Uma matriz identidade é uma matriz que possui 1 em todos os elementos da
    diagonal principal, e 0 em todas as outras posições. Faça um programa que
    leia uma matriz M[5][5] e verifique se é uma matriz identidade escrevendo: 1
    - Se é uma matriz identidade; 0 - Se não é uma matriz identidade.
*/
#define N 4

int is_indetity_matrix(int mat[N][N]) {
  int i, j;

  for (i = 0; i < N; i++) {
    if (mat[i][i] != 1) {
      return 0;
    }
    for (j = 0; j < i; j++) {
      if (mat[i][j] != 0 || mat[j][i] != 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int mat[N][N] = {
      {1, 0, 0, 3},
      {0, 1, 0, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1},
  };

  int ident;

  ident = is_indetity_matrix(mat);

  if (ident) {
    printf("É ident\n");
  } else {
    printf("Não é ident\n");
  }
  return 0;
}
