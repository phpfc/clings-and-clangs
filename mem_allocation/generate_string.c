#include<stdio.h>
#include <stdlib.h>

char * gen_str(int n, char c) {
    char *s = malloc((n + 1) * sizeof(char));

    // +1 in order to properly accept the null terminator

    if (s == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        s[i] = c;
    }

    s[n] = '\0';

    return s;
}

int main() {
    char *str = gen_str(4, 'a');
    if (str != NULL) {
        printf("%s\n", str);
        free(str);
    } else {
        printf("Erro ao alocar memória.\n");
    }
}
