#include <stdio.h>

long long fibs(int n) {
    if (n == 0 || n == 1) return 1;
    return fibs(n - 1) + fibs(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", fibs(n));
    return 0;
}