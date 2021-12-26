#include <iostream>
#include <vector>
#include <tuple>
#define x first
#define y second
using namespace std;

int n, range;

int Square(int x)
{
    return x * x;
}

int SquareNorm(pair<int, int>& p1, pair<int, int>& p2)
{
    return Square(p2.x - p1.x) + Square(p2.y - p1.y);
}

int DFS(vector<bool>& traversed, vector<pair<int, int>>& cats, int now)
{
    traversed[now] = true;
    int res = 1;
    for (int i = 0; i < n; i++)
        if (traversed[i] == false && SquareNorm(cats[i], cats[now]) <= range)
            res += DFS(traversed, cats, i);
    return res;
}

// void PRINTALL(vector<bool>& traversed, vector<pair<int, int>>& cats)
// {
//     for (int i = 0; i < n; i++) {
//         if (traversed[i])   cout << "[O] (";
//         else                cout << "[X] (";
//         cout << cats[i].x << ", " << cats[i].y << ")\n";
//     }
//     cout << '\n';
// }

int main()
{
    int buf, cat_toast = 0, black_hole = 0;
    cin >> n >> range;
    range *= range;
    vector<pair<int, int>> cats(n);
    vector<bool> traversed(n);

    for (int i = 0; i < n; i++) cin >> cats[i].x >> cats[i].y;
    // PRINTALL(traversed, cats);
    for (int i = 0; i < n; i++) {
        if (traversed[i] == false) {
            if (DFS(traversed, cats, i) == 1)   cat_toast++;
            else                                black_hole++;
        }
        // PRINTALL(traversed, cats);
    }
    cout << cat_toast << ' ' << black_hole << '\n';

    return 0;
}