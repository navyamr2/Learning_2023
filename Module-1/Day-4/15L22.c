#include <stdio.h>

// Macro to convert decimal to BCD
#define DEC_TO_BCD(decimal) (((decimal / 10) << 4) | (decimal % 10))

int main() {
    int decimalNumber = 25; // Example decimal number

    unsigned char bcdNumber = DEC_TO_BCD(decimalNumber);

    printf("Decimal: %d\n", decimalNumber);
    printf("BCD: 0x%02X\n", bcdNumber);

    return 0;
}
