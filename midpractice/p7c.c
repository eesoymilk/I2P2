#include <stdio.h>
#include <stdlib.h>
#define LL long long
#define MOD ((LL)1e9+7)

typedef struct GAME {
    int idx;
    LL res;
} GAME;

LL FME(int p)
{
    LL base = 2, ans = 1;
    for ( ; p; p >>= 1){
        if (p & 1)
            ans = ans * base % MOD;
        base = base * base % MOD;
    }
    return ans;
}

int GAMECMP (const void * L, const void * R)
{
    const GAME *l = (GAME*)L, *r = (GAME*)R;
    if (l->res == r->res)
        return l->idx > r->idx;
    return l->res > r->res;
}

void PRINTGAMES(GAME* g, int n)
{
    printf("idx:");
    for (int i = 0; i < n; i++)
        printf(" %d", g[i].idx);
    printf("\nres:");
    for (int i = 0; i < n; i++)
        printf(" %d", g[i].res);
    putchar('\n');
}

int main()
{
    int n, q, buf, start = 0, end = n - 1, mid;
    LL x;
    GAME *games;

    while (scanf("%d%d", &n, &q) != EOF) {
        games = (GAME*)calloc(n, sizeof(GAME));
        for (int i = 0; i < n; i++) {
            games[i].idx = i;
            scanf("%d(/`A`)/ ~I__I", &buf);
            if (buf & 1) {
                games[i].res = 0;
                continue;
            }
            if (buf >>= 1)
                games[i].res = FME(buf);
        }

        printf("before qsort:\n");
        PRINTGAMES(games, n);

        qsort(games, n, sizeof(GAME), GAMECMP);

        printf("after qsort:\n");
        PRINTGAMES(games, n);

        while (q--) {
            scanf("%lld", &x);
            for (start = 0, end = n - 1; start < end; ) {
                mid = (start + end) / 2;
                if (games[mid].res >= x)
                    end = mid;
                else
                    start = mid + 1;
            }
            mid = (start + end) / 2;
            if (games[mid].res == x) {
                printf("%d\n", games[mid].idx + 1);
            } else
                printf("Go Down Chicken 404\n");
        }
        free(games);
    }

    return 0;
}