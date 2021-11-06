#include <stdio.h>
#include <stdlib.h>
#define LL long long

typedef struct
{
    int idx;
    LL sol;
} RES;

int REScmp(const void* l, const void* r)
{
    const RES *L = (const RES*)l;
    const RES *R = (const RES*)r;
    if (L->sol == R->sol)
        return L->idx > R->idx;
    return L->sol > R->sol;
}

// void PrintRES(RES* res, int n)
// {
//     puts("idx:");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", res[i].idx);
//     }
//     puts("\nsol:");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", res[i].sol);
//     }
//     putchar('\n');
// }

int main()
{
    int n, q, buf;
    RES *res;
    while (scanf("%d%d", &n, &q) != EOF) {
        res = (RES*)malloc(n * sizeof(RES));
        for (int i = 0; i < n; i++) {
            scanf("%d(/`A`)/ ~I__I", &buf);
            res[i].idx = i;
            if (buf & 1)
                res[i].sol = 0;
            else if (buf >>= 1) {
                LL base, ans;
                for (base = 2, ans = 1; buf; buf >>= 1) {
                    if (buf & 1)
                        ans = (ans * base) % 1000000007;
                    base = base * base % 1000000007;
                }
                res[i].sol = ans;
            }
        }

        // puts("\nbefore qsort:");
        // PrintRES(res, n);

        qsort(res, n, sizeof(RES), REScmp);

        // puts("\nafter qsort:");
        // PrintRES(res, n);

        while (q--) {
            LL x;
            int start, end, middle;
            scanf("%lld", &x);
            start = 0;
            end = n - 1;
            while (start < end) {
                middle = (start + end) / 2;
                if (x <= res[middle].sol)
                    end = middle;
                else
                    start = middle + 1;
            }
            middle = (start + end) / 2;
            if (x == res[middle].sol)
				printf("%d\n", res[middle].idx + 1);
			else
				puts("Go Down Chicken 404");
            // for (r = 0; r < n && x != res[r]; r++) ;
            // if (r == n)
            //     printf("Go Down Chicken 404\n");
            // else
            //     printf("%d\n", r + 1);
        }
        free(res);
    }

    return 0;
}