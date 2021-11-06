#include <stdio.h>
#include <stdlib.h>
#define LL long long
#define MOD ((LL)1e9+7)

void MatrixMul(LL A[3][3], LL B[3][3])
{
    LL C[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            C[i][j] = 0;
            for (int k = 0; k < 3; k++){
                C[i][j] += A[i][k] * B[k][j] % MOD;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            A[i][j] = C[i][j];
        }
    }
}

int main()
{
    int t;
    LL x, P[3] = {1, 12, 13};

    scanf("%d", &t);
    while (t--) {
        LL M[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        LL C[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}};
        LL ans = 0;
        scanf("%lld", &x);
        if (x > 3) {
            for (x -= 3 ; x; x >>= 1) {
                if (x & 1)
                    MatrixMul(M, C);
                MatrixMul(C, C);
            }
            for (int i = 0; i < 3; i++)
                ans += (M[0][i] * P[2 - i]) % MOD;
            ans %= MOD;
        } else {
            ans = P[x - 1];
        }
        printf("%d\n", ans);
    }

    return 0;
}