#include <stdio.h>

// Define function pointer type
typedef void (*fp)(int);

// Stop function: end of printing
void stop(int i) {
    (void)i; // Suppress unused variable warning
    printf("\n");
}

// Declaration of next function
void next(int i);

// Function pointer array
fp options[] = { next, stop };

// Recursive function to print numbers
void next(int i) {
    printf("%d\n", i);
    options[i / 1000](i + 1); // Call next or stop based on i
}

int main(void) {
    next(1); // Start from 1
    return 0;
}
