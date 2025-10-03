// 3) Fazer uma função que calcule a partir de um horário inicial 
// (hora e minuto) mais uma quantidade de minutos, o horário 
// correspondente ao horario inicial adicionado a essa quantidade de minutos. Protótipo: 

// void calc_horario(int h1, int m1, int qtdmin, int *h2, int *m2)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//Esta implementação possui uma limitação, pois só funciona para somas de no máximo 60 minutos. 
// Se o valor fosse uma entrada, ou um valor aleatório possivelmente maior que 200, deixaria de funcionar,
// uma vez que o rollover só ocorreria uma vez. Uma solução que comporte quaisquer valores de qt_min, 
// precisaria fazer uma conversão de todos valores para um total de minutos.
void calc_time(int t1, int m1, int qtmin, int *t2, int *m2) {
  int soma = m1 + qtmin;
  if (soma < 60) {
    *m2 = soma;
  } else {
    *m2 = soma - 60;
    // *t2++; operador de incremento tem precedencia maior que o operador de ponteiro
    if (t1 == 12) {
      *t2 = 1;
    } else {
      (*t2)++;
    }
  }

  printf("%02d:%02d\n", *t2, *m2);
}

int main() {
  srand(time(NULL));
  int t1 = rand() % 12;
  int m1 = rand() % 60;
  int qt_min = rand() % 60;

  int t_calcd = t1;
  int m_calcd = 0;

  calc_time(t1, m1, qt_min, &t_calcd, &m_calcd);

}