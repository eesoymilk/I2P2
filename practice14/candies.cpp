#include <iostream>
#include <algorithm>
using namespace std;

void SOL()
{
    int rgb[3];
    cin >> rgb[0] >> rgb[1] >> rgb[2];
    sort(rgb, rgb + 3);
    auto [a, b, c] = rgb;
    if (c > a + b)
        cout << a + b << '\n';
    else
        cout << (a + b + c) / 2 << '\n';
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--) SOL();
    return 0;
}