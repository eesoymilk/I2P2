#include <stdio.h>
#include <stdlib.h>
#define LL long long

void MatrixPrint(LL M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf(" %lld", M[i][j]);
        putchar('\n');
    }
}

void MatrixMul(LL A[3][3], LL B[3][3])
{
    LL C[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            C[i][j] %= (LL)1e9+7;
        }
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            A[i][j] = C[i][j];
}

int main()
{
    int t;

    scanf("%d", &t);
    while (t--) {
        LL x;
        scanf("%lld", &x);
        if (x == 1) printf("1\n");
        if (x == 2) printf("12\n");
        if (x == 3) printf("13\n");
        if (x > 3) {
            LL ans,
            M[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
            C[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}};
            for (x -= 3 ; x > 0; x >>= 1) {
                if (x & 1)  MatrixMul(M, C);
                MatrixMul(C, C);
            }
            ans = M[0][0] * 13 + M[0][1] * 12 + M[0][2] * 1;
            ans %= (LL)1e9+7;
            printf("%lld\n", ans);
        }
    }

    return 0;
}