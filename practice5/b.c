#include <stdio.h>

int Pigeonhole(int n)
{
    if (n > 26 || n == 1) return 1;

    int idx[26] = {0};
    char ch;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch);
        if (++idx[ch - 97] > 1)
            return 1;
    }
    return 0;
}

int main()
{
    int n;

    scanf("%d", &n);
    if (Pigeonhole(n))
        printf("I'm the god of Knuckles!\n");
    else
        printf("Different makes perfect\n");

    return 0;
}