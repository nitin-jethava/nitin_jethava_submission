#include <stdio.h>

// Structure to represent a complex number
typedef struct {
    float real;
    float imag;
} Complex;

int main() {
    Complex num1, num2, sum;

    // Input first complex number
    printf("Enter first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imag);

    // Input second complex number
    printf("\nEnter second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imag);

    // Add real and imaginary parts separately
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;

    // Display result
    printf("\nSum = %.2f + %.2fi\n", sum.real, sum.imag);

    return 0;
}
