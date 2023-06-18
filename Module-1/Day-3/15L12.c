#include <stdio.h>

void printBits(int num) {
    int i;
    unsigned int mask = 1 << 31; // Start with the most significant bit

    for (i = 0; i < 32; i++) {
        int bit = (num & mask) != 0;
        printf("%d", bit);
        mask >>= 1; // Move the mask to the next bit
    }
}

int main() {
    int num;

    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printf("Bits representation: ");
    printBits(num);

    return 0;
}
