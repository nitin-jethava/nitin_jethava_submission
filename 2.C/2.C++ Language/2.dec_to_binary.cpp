#include <stdio.h>

void decToBinary(int n) {
    int binary[32], i = 0;
    while(n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }
    for(int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

int main() {
    int num = 545;
    printf("Binary of %d: ", num);
    decToBinary(num);
    return 0;
}
