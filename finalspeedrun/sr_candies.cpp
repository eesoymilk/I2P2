#include <iostream>
#include <algorithm>
using namespace std;

void SOL()
{
    int rgb[3], ans;
    cin >> rgb[0] >> rgb[1] >> rgb[2];
    sort(rgb, rgb + 3);
    auto [a, b, c] = rgb;
    if (a > c - b)  ans = (a + b + c) / 2;
    else            ans = a + b;
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) SOL();
    return 0;
}