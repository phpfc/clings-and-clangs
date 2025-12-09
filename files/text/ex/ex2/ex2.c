/*
    2)  Considere um arquivo texto com as notas dos alunos de uma disciplina.
   Cada linha do arquivo contém a matrícula de um aluno (cadeia de nove
   caracteres), seguida pelos valores de suas três notas (P1, P2 e P3).
   Considere ainda que não existem linhas em branco no arquivo. Um exemplo desse
   formato é mostrado abaixo.

    9010087-2     2.0     4.3      6.5
    8820324-3     7.0     8.2      8.5
    9210478-5      6.0     7.5      7.8
    9020256-8      3.0     0.5      4.2

    Escreva uma função que receba como parâmetros o número de matrícula de um
   aluno e o nome de um arquivo com as notas de uma disciplina no formato
   descrito acima, e retorne a média do aluno na disciplina. A média de um aluno
   é calculada pela fórmula (P1+P2+P3)/3. Caso o número de matrícula passado
   como parâmetro não seja encontrado no arquivo, a função deve retornar -1.0.
   Por exemplo, considerando um arquivo com o conteúdo apresentado acima, sua
   função deve retornar 7.9 caso o número de matrícula passado como parâmetro
   seja “8820324-3”. O protótipo da função é dado abaixo. Se não for possível
   abrir o arquivo de entrada, a função deve imprimir a mensagem “ERRO” e
   terminar a execução do programa.

    float media (char mat[50], char nome_arquivo[50]);
 */

#include <stdio.h>
#include <stdlib.h>

int myStrCmp(const char *s1, char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

float getStudentAverageScore(char *reg, char *file_name) {
  FILE *fp = fopen(file_name, "r");
  if (!fp) {
    perror("Erro ao abrir o arquivo");
  }

  char read_reg[10];
  float n1, n2, n3;
  int isSoughtReg = 0;

  while (fscanf(fp, "%s %f %f %f", read_reg, &n1, &n2, &n3) == 4) {
    if (myStrCmp(reg, read_reg) == 0) {
      fclose(fp);
      return (n1 + n2 + n3) / 3;
    }
  }
  fclose(fp);
  return -1.0;
}

int main() {
  char *file_name = "entrada.txt";
  char *reg = "9010087-2";
  // char *reg = "902025";

  float average_score = getStudentAverageScore(reg, file_name);
  average_score <= -1 ? printf("Registro não encontrado")
                      : printf("Média do aluno %s: %.1f\n", reg, average_score);
}
