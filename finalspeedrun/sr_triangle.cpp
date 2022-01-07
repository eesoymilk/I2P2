#include <iostream>
#include <vector>
using namespace std;

void SOL()
{
    int A, B, C, D, n;
    long long ans = 0;
    cin >> A >> B >> C >> D;
    n = B + C + 2;
    vector<int> a(n), p(n), psum(n);
    for (int x = A; x <= B; x++) {
        a[x + B]++;
        a[x + C + 1]--;
    }
    for (int i = A + B; i < n; i++) {
        p[i] = a[i] + p[i - 1];
        psum[i] = p[i] + psum[i - 1];
    }
    for (int z = C; z <= D && z < n; z++)
        ans += psum[n - 1] - psum[z];

    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--) SOL();
    return 0;
}