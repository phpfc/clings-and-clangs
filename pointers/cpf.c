#include <stdio.h>

int resto11(int soma) {
  int resto = soma % 11;

  if (resto == 0 || resto == 1) {
    return 0;
  } else {
    return 11 - resto;
  }
}

void calcula_digitos(char cpf[12], int *p1, int *p2) {
  int i, soma1 = 0, soma2 = 0, m1 = 10, m2 = 11;

  for (int i = 0; cpf[i] != '\0'; i++) {
    if (cpf[i] >= '0' && cpf[i] <= '9') {
      soma1 += (cpf[i] - '0') * m1--;
      soma2 += (cpf[i] - '0') * m2--;
    }
  }

  *p1 = resto11(soma1);
  soma2 += *p1 * 2;
  *p2 = resto11(soma2);
}

int main() {
  // char cpf[12] = "388.121.321";
  char cpf[12] = "048.768.990";
  int d1, d2;

  calcula_digitos(cpf, &d1, &d2);
  printf("D1 = %d D2= %d\n", d1, d2);
}
