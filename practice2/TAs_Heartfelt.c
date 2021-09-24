#include <stdio.h>

int main() 
{
    float x;

    // we need an int* because only int* can perform bitwise operation
    int *p;

    while (scanf("%f", &x) != EOF) {
        p = (int*)&x;
        // p points to the memory location of x
        for (int i = 31; i >= 0; i--) {
            if (*p & 1 << i)
                putchar('1');
            else
                putchar('0');
        }
        putchar('\n');
    }

    return 0;
}