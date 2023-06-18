#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 0;

    for (int i = 0; i < n; i += 2) {
        sum += a[i];
    }

    printf("Sum of every alternate element: %d\n", sum);

    return 0;
}
