// 2) Faça uma função que receba uma hora como parâmetro e retorne uma nova
// estrutura com a hora mais um segundo. O tipo HORA foi criado a partir de uma
// estrutura que armazena os valores para a hora, minuto e segundo conforme o
// código a seguir:

// A função deve ter o seguinte protótipo :

//     HORA
//     adicionaSegundo(HORA horaAtual)

//         O programa de teste deve ler 5 horas e retornar,
//     após leitura,
//     a hora com um segundo a mais para cada uma.

//     12 12 2 Segundo a mais : 12 : 12 : 03 23 59 59 Segundo a
//     mais : 00 : 00 : 00 14 59 59 Segundo a mais : 15 : 00 : 00 15 12 59
//     Segundo a mais : 15 : 13 : 00 8 12 45 Segundo a mais : 08 : 12 : 46
#include <stdio.h>
struct hour {
  int second;
  int minute;
  int hour;
};
typedef struct hour hour;

hour add_second(hour h) {};

void write_hour(hour h) {};

int validate_and_read_hour(hour *h) {
  printf("Entre a hora, minuto e segundo: \n");
  int result = scanf("%d %d %d", &h->hour, &h->minute, &h->second);

  if (result != 3) {
    printf("Erro: Entre apenas caractéres numéricos");
    while (getchar() != '\n')
      ;
    return 0;
  }

  return 1;
};

hour generate_random_time(hour h) {}

int main() {
  hour currentTime;

  for (int i = 0; i < 5; i++) {
    printf("=== Hour %d ===\n", i + 1);
    while (!validate_and_read_hour(&currentTime)) {
      printf("Tente novamente!\n");
    }

    hour nextSecond = add_second(currentTime);
    printf("Próximo segundo: ");
    write_hour(nextSecond);
    printf("\n");
  }
}
