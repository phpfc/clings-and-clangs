/*
    3)  Dado um arquivo com o seguinte formato:

    5
    123.987.098-09
    RODRIGO DA SILVA
    1500.78
    CONTABILIDADE
    454.283.731.99
    RODRIGO DE SOUZA
    567.00
    PRODUCAO
    723.987.098-15
    PEDRO PAULO RANGEL
    500.00
    TESOURARIA
    123.987.098-09
    MARIA MENDONÇA DE SOUZA
    400.15
    FATURAMENTO
    456.987.098-11
    FELIPE DE MATTOS
    700.76
    CONTABILIDADE

    onde o primeiro número (5 no exemplo) corresponde ao número de funcionários
   e para cada funcionário tem-se: CPF, nome, salário e departamento. Gerar um
   novo arquivo texto com as mesmas informações mas com os funcionários
   ordenados de acordo com o nome (um funcionário por linha).
 */

#include <stdio.h>
#include <stdlib.h>

struct {
  char cpf[16];
  char name[64];
  float salary;
  char sector[64];
} typedef Employees;

// Aqui faz mais sentido ler linha por linha usando fgets.
// Importante lembrar de declarar o array de employees de forma dinamica com
// malloc.

void print_employees(Employees *employees, int count) {
  FILE *output = fopen("./saida.txt", "w");
  for (int i = 0; i < count; i++) {
    fprintf(output, "%s  ", employees[i].cpf);
    fprintf(output, "%s  ", employees[i].name);
    fprintf(output, "%.2f  ", employees[i].salary);
    fprintf(output, "%s  ", employees[i].sector);
    fprintf(output, "\n");
  }
  fclose(output);
}

int myStrCmp(const char *s1, char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

void order_employees_by_name(Employees *employees, int count) {
  Employees aux;

  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - 1 - i; j++) {
      if (myStrCmp(employees[j].name, employees[j + 1].name) > 0) {
        aux = employees[j];
        employees[j] = employees[j + 1];
        employees[j + 1] = aux;
      }
    }
  }
}

int main() {
  FILE *fp = fopen("./entrada.txt", "r");
  if (!fp) {
    perror("Erro ao abrir o arquivo");
  }

  int emp_index = 0, field_index = 0, employee_count = 0;
  char buffer[64];

  fscanf(fp, "%d\n", &employee_count);

  Employees *employees = malloc(employee_count * sizeof(Employees));

  for (int i = 0; i < employee_count; i++) {
    for (int j = 0; j < 4; j++) {
      switch (j) {
      case 0:
        fscanf(fp, "%s", employees[i].cpf);
        fgetc(fp);
        break;
      case 1:
        fscanf(fp, "%[^\n]", employees[i].name);
        fgetc(fp);
        break;
      case 2:
        fscanf(fp, "%f", &employees[i].salary);
        fgetc(fp);
        break;
      case 3:
        fscanf(fp, "%s", employees[i].sector);
        fgetc(fp);
      }
    }
  }

  order_employees_by_name(employees, employee_count);

  print_employees(employees, employee_count);

  fclose(fp);
}
