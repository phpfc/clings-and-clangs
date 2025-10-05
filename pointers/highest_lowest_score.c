
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5

struct student {
  char name[50];
  float score1;
  float score2;
  float score3;
  float avg_score;
};
typedef struct student STUDENT;

void get_average_score(STUDENT *student) {
  student->avg_score =
      (student->score1 + student->score2 + student->score3) / 3;
}

void initialize_students(STUDENT students[N]) {
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    printf("Entre o nome do aluno %d\n", i + 1);
    scanf("%s", students[i].name);
    students[i].score1 = rand() % 10;
    students[i].score2 = rand() % 10;
    students[i].score3 = rand() % 10;
    get_average_score(&students[i]);
  }
}

void highest_lowest_scoring(STUDENT students[N], STUDENT *highest,
                            STUDENT *lowest) {
  *highest = *lowest = students[0];
  for (int i = 0; i < N; i++) {
    if (highest->avg_score < students[i].avg_score) {
      *highest = students[i];
    }
    if (lowest->avg_score > students[i].avg_score) {
      *lowest = students[i];
    }
  }
}

void print_students(STUDENT students[N], STUDENT *highest, STUDENT *lowest) {
  for (int i = 0; i < N; i++) {
    printf("Nome: %s\n", students[i].name);
    printf("Nota média: %f\n", students[i].avg_score);
  }
  printf("O aluno %s, teve a maior média, de: %f\n", highest->name,
         highest->avg_score);
  printf("O aluno %s, teve a menor média, de: %f\n", lowest->name,
         lowest->avg_score);
}

int main() {
  STUDENT highest_scoring;
  STUDENT lowest_scoring;
  STUDENT students[N];

  initialize_students(students);
  highest_lowest_scoring(students, &highest_scoring, &lowest_scoring);
  print_students(students, &highest_scoring, &lowest_scoring);
}
