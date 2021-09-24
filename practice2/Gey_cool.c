#include <stdio.h>
#include <stdlib.h>

int main()
{
    // qry: query, result: desired query that produce max sum
    int n, q, qry[2] = {0}, result[2] = {0};

    // long long int instead of int due to chance of overflowing
    // temp: promising max, psum: prefix sum, itr: looping pointer
    long long int temp, max = 0, *psum, *itr;
    int i;  // loop indices

    while (scanf("%d %d", &n, &q) != EOF) {
        // scanf returns a EOF if scan failed

        // n qureies, so allocate n spaces for prefix sum
        psum = (long long int*) calloc(n, sizeof(long long int));
        
        // only need to store the prefix sum, the number is trivial
        for (itr = psum, i = 0; itr < &psum[n]; itr++, i++) {
            scanf("%d", &psum[i]);
            if (i)
                psum[i] += psum[i - 1];
        }

        // see if the sum is bigger than current max; if it is, update max
        for (i = 0; i < q; i++) {
            scanf("%d %d", &qry[0], &qry[1]);
            qry[0]--;
            qry[1]--;
            temp = psum[qry[1]];
            if (qry[0])
                temp -= psum[qry[0] - 1];
            if (qry[0] > qry[1])
                temp += psum[n - 1];
            if (temp > max) {
                result[0] = qry[0] + 1;
                result[1] = qry[1] + 1;
                max = temp;
            }
        }
        free(psum); // free allocated memory for psum

        printf("Max_range: (%d,%d); Value: %lld\n", result[0], result[1], max);
        max = 0;    // re-init max to 0
    }

    return 0;
}