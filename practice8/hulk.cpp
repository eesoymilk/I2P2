#include <iostream>
#include <algorithm>
using namespace std;

int n, a[(int)1e5+7];

int UpperBound(int x)
{
    int l = 0, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (x >= a[m])  l = m + 1;
        else            r = m;
    }
    return r;
}

int LowerBound(int x)
{
    int l = 0, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (x > a[m])   l = m + 1;
        else            r = m;
    }
    return r;
}

int main()
{
    int q, x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> q;
    while (q--) {
        cin >> x;
        cout << UpperBound(x) - LowerBound(x) << '\n';
    }
    return 0;
}