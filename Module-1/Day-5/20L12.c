#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

void readComplexNumber(struct Complex* complex) {
    printf("Enter the real part: ");
    scanf("%f", &(complex->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(complex->imaginary));
}

void writeComplexNumber(const struct Complex* complex) {
    printf("Complex number: %.2f + %.2fi\n", complex->real, complex->imaginary);
}

struct Complex addComplexNumbers(const struct Complex* complex1, const struct Complex* complex2) {
    struct Complex result;
    result.real = complex1->real + complex2->real;
    result.imaginary = complex1->imaginary + complex2->imaginary;
    return result;
}

struct Complex multiplyComplexNumbers(const struct Complex* complex1, const struct Complex* complex2) {
    struct Complex result;
    result.real = complex1->real * complex2->real - complex1->imaginary * complex2->imaginary;
    result.imaginary = complex1->real * complex2->imaginary + complex1->imaginary * complex2->real;
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;

    printf("Reading Complex Number 1:\n");
    readComplexNumber(&complex1);

    printf("\nReading Complex Number 2:\n");
    readComplexNumber(&complex2);

    printf("\nComplex Number 1:\n");
    writeComplexNumber(&complex1);

    printf("\nComplex Number 2:\n");
    writeComplexNumber(&complex2);

    sum = addComplexNumbers(&complex1, &complex2);
    printf("\nSum of Complex Numbers:\n");
    writeComplexNumber(&sum);

    product = multiplyComplexNumbers(&complex1, &complex2);
    printf("\nProduct of Complex Numbers:\n");
    writeComplexNumber(&product);

    return 0;
}
