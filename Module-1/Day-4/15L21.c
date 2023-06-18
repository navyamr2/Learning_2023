#include <stdio.h>

// Function to set a BCD digit at a given position in an 8-bit BCD number
unsigned char setBCDDigit(unsigned char num, int position) {
    unsigned char mask = 0x0F << (position * 4);
    return num | mask;
}

// Function to clear a BCD digit at a given position in an 8-bit BCD number
unsigned char clearBCDDigit(unsigned char num, int position) {
    unsigned char mask = ~(0x0F << (position * 4));
    return num & mask;
}

// Function to toggle a BCD digit at a given position in an 8-bit BCD number
unsigned char toggleBCDDigit(unsigned char num, int position) {
    unsigned char mask = 0x0F << (position * 4);
    return num ^ mask;
}

int main() {
    unsigned char bcdNumber = 0x37; // Example 8-bit BCD number

    // Set digit at position 2
    unsigned char setDigitResult = setBCDDigit(bcdNumber, 2);
    printf("Set digit: 0x%02X\n", setDigitResult);

    // Clear digit at position 3
    unsigned char clearDigitResult = clearBCDDigit(bcdNumber, 3);
    printf("Clear digit: 0x%02X\n", clearDigitResult);

    // Toggle digit at position 1
    unsigned char toggleDigitResult = toggleBCDDigit(bcdNumber, 1);
    printf("Toggle digit: 0x%02X\n", toggleDigitResult);

    return 0;
}
