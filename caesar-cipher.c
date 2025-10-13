#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct direction DIRECTION;

int range_add(int a, int b, int min, int max) {
  int range = max - min + 1;
  int a_shifter = a - min;
}

void shift(char *word, int direction, int factor) {
  int length = strlen(word);
  for (int i = 0; i < length; i++) {
    if (word[i] >=)
      word[i] += factor * direction;
  }

  printf("%s\n", word);
}

int main() {
  int left = -1, right = 1, factor = 0;
  char word[50];

  printf("Enter a word:\n");
  scanf("%s", word);

  printf("Choose a shifting factor:\n");
  scanf("%d", &factor);

  shift(word, right, factor);
}
