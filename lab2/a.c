#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, n, q, l, L, R;
    int len;
    char buf;
    int *m, *res, *p_sum, occ;
    int i, j;

    scanf("%d%d%d", &a, &b, &n);
    for (i = 0; i < n + a - b; i++)
        scanf(" %c", &buf);

    for (i = 0; i < b - a; i++) {
        scanf(" %c", &buf);
        if (buf == '1')
            break;
    }
    len = b - i;
    m = (int*)calloc(len, sizeof(int));
    m[0] = buf;
    for (i = 1; i <= len; i++) {
        scanf(" %c", &buf);
        m[i] = buf - 48;
    }

    scanf("%d%d", &q, &l);

    p_sum = (int*)calloc(len + 1, sizeof(int));
    for (i = 0; i <= len - l; i++) {
        // def. of prefix sum
        p_sum[i + 1] = p_sum[i];
        // p[0] matches; see if the rest match
        if (m[i] == 0) {
            for (j = 1; j < l && m[i + j] == 0; j++) ;
            // MATCH CONDITION: escape the loop because j >= l
            if (j >= l)
                p_sum[i + 1]++;
        }
    }
    free(m);

    while (q--) {
        scanf("%d%d", &L, &R);

        if (R - L + 1 < l)
            occ = 0;
        else
            occ = p_sum[R - l + 1] - p_sum[L - 1];
        printf("%d\n", occ);
    }
    free(p_sum);

    return 0;
}