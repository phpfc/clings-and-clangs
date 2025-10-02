#include <stdio.h>

#define N 5

struct aluno {
  char nome[50];
  float media;
};
typedef struct aluno ALUNO;

void escreve_alunos(ALUNO v[N]) {
  for (int i = 0; i < N; i++) {
    printf("%s %.2f\n", v[i].nome, v[i].media);
  }
}

void maiores(ALUNO v[N], ALUNO *m1, ALUNO *m2) {
  (*m1).media = -1;
  (*m2).media = -1;
  for (int i = 0; i < N; i++) {
    if (v[i].media > (*m1).media) {
      *m2 = *m1;
      *m1 = v[i];
    } else if (v[i].media > (*m2).media) {
      *m2 = v[i];
    }
  }
}

int main() {
  ALUNO v[N] = {{"Teste1", 7},
                {"Teste2", 8},
                {"Teste3", 7.5},
                {"Teste4", 9},
                {"Teste5", 6}};
  ALUNO m1, m2;
  // escreve_alunos(v);
  maiores(v, &m1, &m2);
  printf("%s %.2f\n", m1.nome, m1.media);
  printf("%s %.2f\n", m2.nome, m2.media);
}
