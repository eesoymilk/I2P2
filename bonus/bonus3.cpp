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

int MinOptUB(const vector<LL>& psum, int l, int r, LL m)
{
    int ub = (1 + n) / 2;

    while (l < r) {
        if ()
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

    // Real Shit
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            if (m < x - a[n - i + 1].first) break;
            LL diff = x - a[n - i + 1].first;
            m -= diff;
            a[n - i + 1].first = x;
            psum.pop_back();
        }
        PrintPairs(a);
        PrintVec(psum);
        
        int ub = MinOptUB(psum, 0, n - i, m);
        LL S_tmp = A * i + B * ub;   // LL
        if (S < S_tmp) {
            S = S_tmp;
            int min = a[ub].first;
            sol = a;
            for (i = 1; i < ub; i++)
                sol[i].first = min;
        }
    }

    cout << "m = " << m; 

    return 0;
}