#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  THIS IS NOT NECESSARY! I ONLY NEED THE LAST INDEX!
    int get_last_whitespace(char *string) {
        int counter = 0; int *whitespaces =
        malloc(sizeof(int));

        for(int i = 0; i < strlen(string); i++) { if (string[i] == ' ') {
        counter++; whitespaces = realloc(whitespaces, counter * sizeof(int));
        whitespaces[counter - 1] = i; } }

        int result = (counter > 0) ? whitespaces[counter - 1] : -1;
        free(whitespaces);

        return result;
    }
*/


int get_last_whitespace(char *string) {
    int last_index = -1;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            last_index = i;
        }
    }

    return last_index;
}

char * last_name(char *full_name) {
    int i = get_last_whitespace(full_name);

    char *last_name = &full_name[i + 1];



    return last_name;
}

int main() {
    char *full_name = NULL;
    size_t len = 0;
    printf("Enter your full name.\n");
    ssize_t read = getline(&full_name, &len, stdin);
    /*
        This is POSIX compliant and should
        work on any Unix-like system
     */

     // scanf("%ms", &full_name);
     // This is a GNU extension and won't work on MacOS

    if (read == -1) {
        // Any other condition here might cause use-after-free
        printf("Error reading input.\n");
        free(full_name);
        return 1;
    }

    if (read > 0 && full_name[read - 1] == '\n') {
        full_name[read - 1] = '\0';
    }

    char *last = last_name(full_name);

    printf("Last name is: %s\n", last);

    /*
        Here, by passing %s we instruct printf to
        write the characters from that address until the
        null terminator.
     */

     /*
        Important to note that:
        In C, strings are not a first class data type.
        Instead it is merely a convention.
        It's a way to use chars, pointers and using the
        null terminator AS A CONVENTION.
      */

    free(full_name);
    return 0;
}
