#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Lines(vector<int>& a, int d)
{
    int lines = 0;
    for (int i = 0; i < a.size(); i++) {
        int effect = a[i] - (i / d);
        if (effect > 0) {
            lines += effect;
        } else {
            break;
        }
    }
    return lines;
}

void SOL()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int l = 1, r = n + 1, d, res = n + 1;
    while (l < r) {
        d = (l + r) / 2;
        if (Lines(a, d) >= m) {
            res = min(res, d);
            r = d;
        } else {
            l = d + 1;
        }
    }
    if (res == n + 1)   cout << -1 << '\n';
    else                cout << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) SOL();
    return 0;
}