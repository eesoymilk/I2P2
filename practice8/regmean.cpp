#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, ans = 1e9;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        int buf;
        cin >> buf;
        ans = min(buf, ans);
    }
    cout << ans << '\n';
    return 0;
}