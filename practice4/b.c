#include <stdio.h>

/****************************/
/*  BINARY EXPONENTIATION!  */
/****************************/

int main()
{
    long long x, y, m, ans = 1;

    scanf("%lld%lld%lld", &x, &y, &m);

    // We utilize pointer to aid us in our way
    // Much like what we did in practice 2
    for (x %= m; y; y >>= 1, x = x * x % m)
        if (y & 1)  ans = ans * x % m;
    ans %= m;

    printf("%lld\n", ans);

    return 0;
}