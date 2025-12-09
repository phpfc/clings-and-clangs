#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = fopen("./arquivos_binarios_entrada/questao1.bin", "rb");
  if (f == NULL) {
    printf("Erro na abertura do arquivo\n");
    return 0;
  }

  FILE *s = fopen("./arquivos_binarios_entrada/saida.txt", "w");
  if (s == NULL) {
    printf("Erro na abertura do arquivo\n");
    return 0;
  }

  float n, acc = 0;
  int count = 0;
  while (fread(&n, sizeof(float), 1, f) == 1) {
    acc += n;
    count++;
  }
  float media = acc / count;
  printf("Média: %f", media);

  rewind(f);

  while (fread(&n, sizeof(float), 1, f) == 1) {
    if (n > media) {
      fprintf(s, "%f acima da media\n", n);
    }
  }
  fclose(s);
  fclose(f);
}
