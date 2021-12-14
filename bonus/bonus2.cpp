#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#define LL long long
using namespace std;

int DigitsCnt(int x)
{
    int cnt = 1;
    for (x /= 10; x > 0; x /= 10)   cnt++;
    return cnt;
}

int main()
{
    int n, k;

    while (cin >> n >> k)
    {
        LL res = 0, buf;
        vector<tuple<LL, int, LL>> a(n);
        vector<LL> modK(11);
        map<int, int> REM[11];

        modK[0] = 1;    // 10^0 % k = 0
        for (int i = 1; i <= 10; i++)
            modK[i] = modK[i - 1] * 10 % k;

        for (int i = 0; i < n; i++) {
            cin >> buf;
            a[i] = make_tuple(buf, DigitsCnt(buf), buf % k);
            REM[get<1>(a[i])][get<2>(a[i])]++;
        }

        for (int i = 0; i < n; i++) {
            /********************************************/
            /* Find j such that
            /* (a[i] * 10^j % k + a[n] % k) % k = 0
            /* where DigitCnt(a[n]) = j
            /********************************************/
            /* The corresponding counts will be
            /* a[n] with j digits whose
            /* remainder is (k - a[i] * 10^j % k) % k
            /********************************************/
            for (int j = 1; j <= 10; j++) {
                LL r = get<2>(a[i]) * modK[j] % k;
                res += REM[j][(k - r) % k];
                if (get<1>(a[i]) == j && (r + get<2>(a[i])) % k == 0)
                    res--;
            }
        }
        cout << res << endl;
    }
    return 0;
}