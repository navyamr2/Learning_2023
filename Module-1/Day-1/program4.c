#include <stdio.h>

int countSetBits(unsigned int n) {
    int count = 0;
    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int a[] = {0x1, 0xF4, 0x10001};
    int n = sizeof(a) / sizeof(a[0]);
    int totalSetBits = 0;

    for (int i = 0; i < n; i++) {
        totalSetBits += countSetBits(a[i]);
    }

    printf("Total number of set bits: %d\n", totalSetBits);

    return 0;
}
