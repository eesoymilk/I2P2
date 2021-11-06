#include <stdio.h>
#include <stdlib.h>
#define LL long long

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) != EOF) {
        int buf, *res;
        res = (int*)calloc(n, sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d(/`A`)/ ~I__I", &buf);
            if (buf % 2 == 0)
                res[i] = buf / 2;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", res[i]);
        }
        putchar('\n');
        while (q--) {
            LL x;
            int target = -1, r;

            scanf("%lld", &x);

            if (x == 0)
                target = 0;
            if (x > 1) {
                int i;
                for (i = 0; !(x & 1); i++, x >>= 1) ;
                if (x == 1) target = i;
            }

            if (target >= 0) {
                for (r = 0; r < n && target != res[r]; r++) ;
                if (r != n) printf("%d\n", r + 1);
                else        printf("Go Down Chicken 404\n");
            }
            if (target == -1)
                printf("Go Down Chicken 404\n");
        }
        free(res);
    }

    return 0;
}