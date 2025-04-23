#include <stdio.h>

// Function to multiply a number by 9 using bitwise operations
int multiply_by_9(int num) {
    return (num << 3) + num;  // num * 9 = (num << 3) + num
}

int main() {
    int num;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d * 9 is: %d\n", num, multiply_by_9(num));

        // Ask if the user wants to continue or exit
        printf("Press Y to continue or any other key to exit: ");
        scanf(" %c", &choice); 

    } while (choice == 'Y' || choice == 'y');  // Loop continues if user enters 'Y' or 'y'

    printf("Exiting the program.!\n");

    return 0;
}
