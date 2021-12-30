#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintA(vector<int>& a)
{
    cout << "a: ";
    for (auto e : a) cout << e << ' ';
	cout << '\n';
}

int Lines(const vector<int>& a, const int d)
{
    int lines = 0;
    for (int j = 0; j < a.size(); j++) {
        int effect = a[j] - (j / d);
        if (effect > 0) lines += effect;
        else            break;
    }
    return lines;
}

void Sol()
{
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum == m){
        cout << n << '\n';
        return;
    }
    if (sum < m) {
        cout << -1 << '\n';
        return;
    }
    
    int l = 1, r = n + 1, d, res = n + 1;
    while (l < r) {
        d = (l + r) / 2;
        if (Lines(a, d) < m)
            l = d + 1;
        else {
            res = min(res, d);
            r = d;
        }
    }
    if (res == n + 1)   cout << -1 << '\n';
    else                cout << res << '\n';

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--) Sol();
    return 0;
}