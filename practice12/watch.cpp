#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Sol()
{
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k >= m) k = m - 1;
    for (int i = 0; i <= k; i++) {
        int least = max(a[i], a[i + (n - m)]);
        for (int j = 1; j < m - k; j++) {
            least = min(max(a[i + j], a[i + j + (n - m)]), least);
        }
        ans = max(least, ans);
    }
    cout << ans << '\n';

}

int main()
{
    int t;
    cin >> t;
    while (t--) Sol();
    return 0;
}