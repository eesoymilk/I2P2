#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q, buf, l, r, m;
    long long *sqn, max;

    scanf("%d%d", &n, &q);
    sqn = (long long*)calloc(n + 1, sizeof(long long));
    for (int i = 1; i <= n; i++) {
        sqn[i] = sqn[i - 1];
        scanf("%d", &buf);
        if (buf > 0) sqn[i] += buf;
    }

    while (q--) {
        scanf("%d%d%d", &l, &r, &m);
        max = sqn[l + m - 1] - sqn[l - 1];
        printf("%lld\n", max);
    }

    return 0;
}