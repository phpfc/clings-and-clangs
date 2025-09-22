// 1)  Faça uma função que receba uma data como parâmetro e retorne uma nova
// estrutura com o dia seguinte. O tipo DATA foi criado a partir de uma
// estrutura que armazena os valores para dia, mês e ano conforme o código a
// seguir:
// A função deve ter o seguinte protótipo:

// DATA proximoDia (DATA diaAtual)

// Cuidado com os anos bissextos (múltiplos de 400 ou múltiplos de 4, mas não
// múltiplo de 100). O programa de teste deve ler 5 datas e retornar o próximo
// dia para cada dia após a leitura.
//
#include <stdio.h>
struct date {
  int day;
  int month;
  int year;
};
typedef struct date date;

date next_day(date currentDay) {
  date nextDate = currentDay;

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (currentDay.year % 400 == 0 ||
      (currentDay.year % 4 == 0 && currentDay.year % 100 != 0)) {
    daysInMonth[1] = 29;
  }

  if (currentDay.day < daysInMonth[currentDay.month - 1]) {
    nextDate.day++; // Se não for o último dia do mês, incremente
  } else {
    nextDate.day = 1;             // Caso contrário, incremente
    if (currentDay.month == 12) { // Se for o último mês do ano
      nextDate.month = 1;
      nextDate.year++;
    } else { // Senão incremente o mês
      nextDate.month++;
    }
  }

  return nextDate;
}

void write_date(date date) {
  printf("%02d/%02d/%02d\n", date.day, date.month, date.year);
}

int validate_and_read_date(date *d) {
  printf("Entre o dia, mês e ano (formato: dd mm aaaa): \n");
  int result = scanf("%d %d %d", &d->day, &d->month, &d->year);

  if (result != 3) {
    printf("Erro: Entre apenas caractéres numéricos");
    while (getchar() != '\n')
      ;
    return 0;
  }

  if (d->year < 1) {
    printf("Erro: Ano deve ser positivo\n");
    return 0;
  }

  if (d->month < 1 || d->month > 12) {
    printf("Erro: Mês deve estar entre 1 e 12\n");
    return 0;
  }

  if (d->day < 1) {
    printf("Erro: Dia deve ser positivo\n");
    return 0;
  }

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (d->year % 400 == 0 || (d->year % 4 == 0 && d->year % 100 != 0)) {
    daysInMonth[1] = 29;
  }

  if (d->day > daysInMonth[d->month - 1]) {
    printf("Erro: Dia %d é inválido para o mês %d", d->day, d->month);
    return 0;
  }

  return 1;
}

int main() {
  date currentDate;

  for (int i = 0; i < 5; i++) {
    printf("=== Data %d ===\n", i + 1);

    while (!validate_and_read_date(&currentDate)) {
      printf("Tente novamente!\n");
    }
    date nextDate = next_day(currentDate);
    printf("Próximo dia: ");
    write_date(nextDate);
    printf("\n");
  }
}
