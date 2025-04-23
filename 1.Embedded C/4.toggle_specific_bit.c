#include <stdio.h>
#include <stdint.h>  // For uint8_t

// Function to toggle a specific bit
uint8_t toggle_bit(uint8_t num, uint8_t bit_position) {
    return num ^ (1 << bit_position);
}

int main() {
    uint8_t num;
    uint8_t bit_position;

    printf("Enter an 8-bit number (0-255): ");
    scanf("%hhu", &num);  // %hhu for uint8_t

    printf("Enter the bit position to toggle (0-7): ");
    scanf("%hhu", &bit_position);

    // Checking for valid bit position
    if (bit_position > 7) {
        printf("Invalid bit position! It must be between 0 and 7.\n");
        return 1;
    }

    // Toggle the specified bit
    uint8_t result = toggle_bit(num, bit_position);

    // Display the result
    printf("Result after toggling bit %d of %u: %u\n", bit_position, num, result);

    return 0;
}
