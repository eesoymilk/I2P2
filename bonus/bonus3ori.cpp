#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define LL long long
using namespace std;
using Skills = vector<pair<LL, LL>>;

int MinOptUB(const Skills &a, const vector<LL> &psum, LL l, LL r, LL m)
{
    LL ub = (l + r) / 2;
    while (l < r) {
        if (m >= a[ub].first * ub - psum[ub])
            l = ub + 1;
        else
            r = ub;
        ub = (l + r) / 2;
    }
    return ub - 1;
}

int main()
{
    LL n, x, A, B;
    LL m, S = 0;

    cin >> n >> x >> A >> B >> m;
    Skills a(n + 1), sol(n + 1);
    vector<LL> psum(n + 1);

    // Prep
    for (int i = 1; i <= n; i++)
    {
        LL buf;
        cin >> buf;
        a[i] = {buf, i};
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i - 1] + a[i].first;

    // Real Shit
    for (int i = 0; i <= n; i++)
    {
        if (i > 0)
        {
            if (m < x - a[n - i + 1].first)
                break;
            LL diff = x - a[n - i + 1].first;
            m -= diff;
            a[n - i + 1].first = x;
            psum.pop_back();
        }

        LL ub = MinOptUB(a, psum, 0, n - i, m);
        LL S_tmp = A * i + B * a[ub].first;
        if (S < S_tmp) {
            S = S_tmp;
            LL min = a[ub].first;
            sol = a;
            for (int i = 1; i < ub; i++)
                sol[i].first = min;
        }
    }

    sort(sol.begin(), sol.end(), [](const pair<LL, LL> &a, const pair<LL, LL> &b)
         { return a.second < b.second; });

    cout << S << endl;
    for (int i = 1; i < n; i++)
        cout << sol[i].first << ' ';
    cout << sol[n].first << endl;

    return 0;
}