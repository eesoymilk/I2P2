#include <stdio.h>
#include <string.h>

int main()
{
    char S[1001], p[1001];
    int S_len, p_len;
    int q, a, b, occ, max_occ = 0;
    int p_sum[1001];
    int i, j;

    // For convenience, p_sum[0] will always be 0
    // We start counting prefix sum at p_sum[1]
    for (p_sum[0] = 0; scanf(" %s %s", S, p) != EOF; max_occ = 0) {
        S_len = strlen(S);
        p_len = strlen(p);
        // WE ONLY NEED TO MAKE THE PREFIX SUM OF (S_len - p_len + 1) LENGTH
        for (i = 0; i <= S_len - p_len; i++) {
            // def. of prefix sum
            p_sum[i + 1] = p_sum[i];
            // p[0] matches; see if the rest match
            if (p[0] == S[i]) {
                for (j = 1; j < p_len && p[j] == S[i + j]; j++) ;
                // MATCH CONDITION: escape the loop because j >= p_len
                if (j == p_len) p_sum[i + 1]++;
            }
        }

        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            // Range(a, b) is shorter than p_len; therefore skip
            if (b - a + 1 < p_len)
                continue;
            // See if occurence of Range(a, b) is greater than the current max
            if ((occ = p_sum[b - p_len + 1] - p_sum[a - 1]) > max_occ)
                max_occ = occ;
        }
        printf("%d\n", max_occ);
    }

    return 0;
}