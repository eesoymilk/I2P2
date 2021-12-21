#include <iostream>
#include <vector>
#define LL long long
using namespace std;

int main()
{
    int n, x, A, B;
    LL m, sum = 0, mean;
    cin >> n >> x >> A >> B >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    mean = (sum + m) / n;

    return 0;
}