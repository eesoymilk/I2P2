#include <stdio.h>
#define LL long long

// You can use the function to print out 2 by 2 matrix if you are interested
// void MatrixPrint(LL a[2][2]) {
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 2; j++)
//             printf(" %d", a[i][j]);
//         putchar('\n');
//     }
// }

// Multiply two 2 by 2 MATRICES MATRIX(a) and MATRIX(b)
// Then, store the result into MATRIX(a)
// Program Representation:
// MATRIX(c) = MATRIX(a) * MATRIX(c)
// MATRIX(a) = MATRIX(c)
void MatrixMul(LL a[2][2], LL b[2][2]) {
    LL c[2][2] = {0};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = c[i][j] % ((LL)1e9+7);
}

/**********************************************/
/*  1. MATRIX EXPONENTIATION with FIBONACCI!  */
/*  2. BINARY EXPONENTIATION from problem b!  */
/**********************************************/

int main()
{
    LL i;

    while (scanf("%lld", &i) != EOF) {
        LL C[2][2] = {{1, 1}, {1, 0}};
        LL M[2][2] = {{1, 0}, {0, 1}};
        for ( ; i; i >>= 1, MatrixMul(C, C))
            if (i & 1)  MatrixMul(M, C);
        printf("%lld\n", M[1][0]);
    }

    return 0;
}