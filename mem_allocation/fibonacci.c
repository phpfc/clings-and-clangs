#include <stdio.h>
#include <stdlib.h>

int * fibonacci(int n) {
    int *sequence = malloc(sizeof(int) * n);
    sequence[0] = 0;
    sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }

    return sequence;
}

int main() {
    printf("Escolha quantos termos de fibonacci escrever:\n");

    int termos = 0;
    scanf("%d", &termos);
    printf("------\n");
    int *arr = fibonacci(termos);

    for(int i = 0; i < termos; i++) {
        printf("%d\n", arr[i]);
    }
}
