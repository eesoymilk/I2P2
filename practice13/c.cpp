#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintA(vector<int>& a)
{
    for (auto ai : a)   cout << ai << ' ';
    cout << '\n';
}

void Sol()
{
    int n, p, k, buf, ans = 0;
    cin >> n >> p >> k;
    vector<int> a(n + 1), psum(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    PrintA(a);
    for (int i = 1; i <= n; i++) {
        if (i >= k) psum[i] = a[i] + psum[i - k];
        else        psum[i] = a[i] + psum[i - 1];
    }
    PrintA(psum);
    for (int i = n; i; i--) {
        if (p >= psum[i]){
            ans = i;
            break;
        }
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