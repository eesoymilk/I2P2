#include <bits/stdc++.h>
#include <cstdio>
#define LL long long
using namespace std;

// 15 maps
map<LL, LL> RMaps[15];

// Function to calculate and return the
// count of pairs
LL Sol(vector<LL> a, LL n, LL k)
{
    vector<LL> len(n);

    // Compute power of 10 modulo k
    vector<LL> p(15);
    p[0] = 1;
    for (int i = 1; i <= 14; i++)
        p[i] = (p[i - 1] * 10) % k;

    // length of a[i]
    for (LL i = 0; i < n; i++) {
        for (LL x = a[i]; x > 0; x /= 10) len[i]++;
        RMaps[len[i]][a[i] % k]++;
    }

    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        for (int j = 1; j <= 14; j++) {
            // Calculate (a[i]* 10^lenj) % k
            LL r = ((a[i] % k) * p[j]) % k;
            // Calculate (k - (a[i]* 10^lenj)% k) % k
            LL xr = (k - r) % k;
            // Increase answer by count
            // Since xr + r = k
            ans += RMaps[j][xr];
            // If a pair (a[i], a[i]) is counted
            if (len[i] == j && (r + a[i] % k) % k == 0)
                ans--;
        }
    }
    return ans;
}

int main()
{
    LL n, k;
    while (cin >> n >> k) {
        vector<LL> a(n);
        for (LL i = 0; i < n; i++)
            cin >> a[i];
        cout << Sol(a, n, k) << endl;
        for (int i = 0; i < 15; i++)
            RMaps[i].clear();
    }
}