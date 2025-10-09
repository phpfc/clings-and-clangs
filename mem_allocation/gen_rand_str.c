#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ascii_group {
    const char *name;
    const int ground;
    const int ceiling;
};
typedef struct ascii_group ASCII_GROUP;

char get_rand_char() {
    ASCII_GROUP groups[] = {
        { .name = "Numerical", .ground = 48, .ceiling = 57 },
        { .name = "Uppercase", .ground = 65, .ceiling = 90 },
        { .name = "Lowercase", .ground = 97, .ceiling = 122}
    };
    int group = rand() % 3;

    char c = (rand() % (groups[group].ceiling - groups[group].ground + 1)) + groups[group].ground;
    return c;
}

char * random_str(int n) {
    char *random = malloc((n + 1) * sizeof(char));

    if (random == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        random[i] = get_rand_char();
    }

    random[n] = '\0';

    return random;
}

int main() {
    srand(time(NULL));
    /* This should only be seeded ONCE!
        Every subsequent call for rand() consumes the
        next part of the pseudo-random sequence.
        Reseeding it will make rand() consume the same
        part of the sequence for that given seed.
        Which in this context, is the same every second
     */

    char *random = random_str(10);

    if (random != NULL) {
       printf("%s\n", random);
       free(random);
    } else {
        printf("Erro ao alocar memória.\n");
    }
}
