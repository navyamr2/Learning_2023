#include <stdio.h>

union DoubleToBits {
    double d;
    unsigned long long bits;
};

void printExponent(double x) {
    union DoubleToBits converter;
    converter.d = x;
    unsigned long long exponent = (converter.bits >> 52) & 0x7FF;

    printf("Hexadecimal: 0x%llX\n", exponent);

    printf("Binary: 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
