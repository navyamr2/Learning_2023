#include <stdio.h>

char *xstrchr(char *string, char ch) {
    while (*string != '\0') {
        if (*string == ch) {
            return string;  // Return a pointer to the first occurrence of the character
        }
        string++;
    }

    return NULL;  // Character not found, return NULL
}

int main() {
    char str[] = "Hello, world!";
    char ch = 'o';

    char *result = xstrchr(str, ch);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
