#include <stdio.h>

int Ones(int a, int b)
{
    int A = (--a), B = b, lsb_a, lsb_b, m, ans;

    for (ans = 0, m = 1; B; m *= 10) {
        lsb_a = A % 10;
        lsb_b = B % 10;
        A /= 10;
        B /= 10;
        ans += (B - A) * m;
        if (lsb_b == 1) ans += b % m + 1;
        if (lsb_b > 1)  ans += m;
        if (lsb_a == 1) ans -= a % m + 1;
        if (lsb_a > 1)  ans -= m;
    }

    return ans;
}

int main()
{
    int t, a, b;
    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", Ones(a, b));
    }

    return 0;
}