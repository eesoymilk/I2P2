#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define LL long long
using namespace std;
using Skills = vector<pair<int, int>>;

int n;

void PrintPairs(const Skills& pairs)
{
    for (auto pair : pairs) {
        cout << pair.first << ", ";
        // cout << '(' << pair.first << ", " << pair.second << "), ";
    }
    cout << endl;
}

void PrintVec(const vector<LL>& vec)
{
    for (auto v : vec) {
        cout << v << ", ";
        // cout << '(' << pair.first << ", " << pair.second << "), ";
    }
    cout << endl;
}

int MinOptUB(const Skills& a, const vector<LL>& psum, int l, int r, LL m)
{
    int ub;

    // ub = 5 -> l = 6 -> ub = 8 -> r = 8 -> ub = 7 -> r = 7
    // -> ub = 6 -> r = 6 (l = 6) ->

    // l = 6, r = 9 -> ub = 7 -> l = 7 -> ub = 8 -> l = 8 -> l = 9 
    while (l < r) {
        ub = (l + r) / 2;
        if (m >= a[ub].first * ub - psum[ub]) {
            l = ub + 1;
        } else {
            r = ub;
        }
    }
    return ub;
}

int main()
{
    int x, A, B;
    LL m, S = 0;

    cin >> n >> x >> A >> B >> m;
    Skills a(n + 1), sol(n + 1);
    vector<LL> psum(n + 1);

    // Prep
    for (int i = 1; i <= n; i++) {
        int buf;
        cin >> buf;
        a[i] = {buf, i};
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i - 1] + a[i].first;

    cout << "a: ";
    PrintPairs(a);
    cout << "psum: ";
    PrintVec(psum);

    // Real Shit
    for (int i = 0; i <= n; i++) {
        cout << "\niteration " << i + 1 << ":\n";
        if (i > 0) {
            if (m < x - a[n - i + 1].first) break;
            LL diff = x - a[n - i + 1].first;
            m -= diff;
            a[n - i + 1].first = x;
            psum.pop_back();
        }
        cout << "a: ";
        PrintPairs(a);
        cout << "psum: ";
        PrintVec(psum);
        cout << "remaining m: " << m << endl;

        int ub = MinOptUB(a, psum, 0, n - i, m);
        LL S_tmp = A * i + B * a[ub].first;   // LL
        if (S < S_tmp) {
            cout << "S is updated!!!\n";
            S = S_tmp;
            int min = a[ub].first;
            sol = a;
            for (int i = 1; i < ub; i++)
                sol[i].first = min;
        }
        cout << "S = " << S << endl;
        
        
        cout << "sol: ";
        PrintPairs(sol);
    }

    cout << "m = " << m << endl;

    return 0;
}