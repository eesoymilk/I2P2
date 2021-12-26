#include <iostream>
#include <vector>
#include <tuple>
#define x first
#define y second
using namespace std;
using POSITION = pair<int, int>;
using CAT = pair<bool, POSITION>;
using CATS = vector<CAT>;

int n, r;

int Square(int x)
{
    return x * x;
}

int SquareNorm(POSITION& p1, POSITION& p2)
{
    return Square(p2.x - p1.x) + Square(p2.y - p1.y);
}

int DFS(CATS& cats, int now)
{
    int res = 1;
    cats[now].first = true;
    for (int i = 0; i < n; i++) {
        if (cats[i].first == false && SquareNorm(cats[i].second, cats[now].second) <= r * r) {
            res += DFS(cats, i);
        }
    }
    return res;
}

void Sol()
{
    int k, lt = 0, nlt = 0;
    cin >> n >> r >> k;
    CATS cats(n);
    for (int i = 0; i < n; i++)
        cin >> cats[i].second.x >> cats[i].second.y;
    for (int i = 0; i < n; i++) {
        if (cats[i].first == false)
            if (DFS(cats, i) < k)   lt++;
            else                    nlt++;
    }
    cout << lt << ' ' << nlt << '\n'; 
}

int main()
{
    int t, n, r, k;
    cin >> t;
    while(t--)
    {
        Sol();
        // pair<int, int> sol = Sol();
        // cout << sol.first << ' ' << sol.second << '\n'; 
    }

    return 0;
}