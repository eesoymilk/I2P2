#include <stdio.h>
#include <stdlib.h>
#define LL long long

int main()
{
    int n, q, gain, buf;
    LL *psum;
    scanf("%d%d", &n, &q);
    psum = (LL*)calloc((n + 1), sizeof(LL));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &buf);
        psum[i] += psum[i - 1];
        if (buf > 0)
            psum[i] += buf;
    }

    while (q--) {
        int l, r, m;
        scanf("%d%d%d", &l, &r, &m);
        printf("%lld\n", psum[l + m - 1] - psum[l - 1]);
    }

    return 0;
}