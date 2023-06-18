#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encodeString(const char* input) {
    int length = strlen(input);
    char* encoded = malloc((length + 1) * sizeof(char));  // Allocate memory for the encoded string

    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            encoded[i] = ' ';  // Preserve spaces
        } else {
            encoded[i] = input[i] + 1;  // Shift each character by 1
        }
    }
    encoded[length] = '\0';  // Null-terminate the encoded string

    return encoded;
}

char* decodeString(const char* encoded) {
    int length = strlen(encoded);
    char* decoded = malloc((length + 1) * sizeof(char));  // Allocate memory for the decoded string

    for (int i = 0; i < length; i++) {
        if (encoded[i] == ' ') {
            decoded[i] = ' ';  // Preserve spaces
        } else {
            decoded[i] = encoded[i] - 1;  // Shift each character back by 1
        }
    }
    decoded[length] = '\0';  // Null-terminate the decoded string

    return decoded;
}

int main() {
    const char* original = "Hello, World!";
    printf("Original string: %s\n", original);

    char* encoded = encodeString(original);
    printf("Encoded string: %s\n", encoded);

    char* decoded = decodeString(encoded);
    printf("Decoded string: %s\n", decoded);

    free(encoded);
    free(decoded);

    return 0;
}
