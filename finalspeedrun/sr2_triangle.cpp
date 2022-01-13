#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define N (int)1e5 + 7
using namespace std;

int a[N], p[N], psum[N];

void SOL()
{
    int A, B, C, D;
    long long res = 0;
    cin >> A >> B >> C >> D;
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    memset(psum, 0, sizeof(psum));
    for (int x = A; x <= B; x++) {
        a[x + B]++;
        a[x + C + 1]--;
    }
    for (int i = 1; i < N; i++) {
        p[i] = a[i] + p[i - 1];
        psum[i] = p[i] + psum[i - 1];
    }

    for (int z = C; z <= D; z++) {
        res += psum[N - 1] - psum[z];
    }

    cout << res << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--) SOL();
    return 0;
}