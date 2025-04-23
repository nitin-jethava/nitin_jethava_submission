#include <stdio.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main() {
    int a = 45, b = 34;
    printf("The Minimum of %d and %d is %d\n", a, b, MIN(a, b));
    return 0;
}
