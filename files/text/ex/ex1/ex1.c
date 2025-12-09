/*
    1)Considere um arquivo texto que contém os nomes e as notas dos alunos de
   uma disciplina. As informações de cada aluno ocupam duas linhas do arquivo: a
    primeira linha contém o nome do aluno (com eventuais espaços em branco) e a
    segunda as três notas obtidas. Considere:
    Fulano de Tal
    6.3 5.7 7.1
    Sicrano Silva
    3.4 5.4 4.7
    Beltrano Alves
    9.2 6.8 8.3
    Escreva um programa que leia o arquivo “entrada.txt”, que contém as
   informações dos alunos no formato descrito acima, e imprima na tela o número
   de alunos aprovados e o número de alunos reprovados. Considere que um aluno é
   aprovado se obtiver média maior ou igual a cinco. Se não for possível abrir o
   arquivo, o programa deve ter como saída a mensagem “ERRO”. Para o exemplo
   ilustrado acima, a saída do programa seria:
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("./entrada.txt", "r");
  char nome[100];

  int aprovados = 0, reprovados = 0;
  float n1, n2, n3;

  if (fp == NULL) {
    perror("Erro ao abrir arquivo");
  }

  while (fgets(nome, sizeof(nome), fp) != NULL) {
    if (fscanf(fp, " %f %f %f\n", &n1, &n2, &n3) != 3) {
      break;
    }

    float media = (n1 + n2 + n3) / 3.0;
    if (media >= 5)
      aprovados++;
    else
      reprovados++;
  }

  fclose(fp);

  printf("Aprovados: %d\n", aprovados);
  printf("Reprovados: %d\n", reprovados);
}
