#include <iostream>
#include <vector>
using namespace std;
using FLAT = vector<vector<char>>;

int n, m, Ts = 0, res = 0;

void BFS(FLAT& F, const int x, const int y, const int d)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (F[x][y] == 'C') return;

    if (F[x][y] == 'T') {
        res = max(d, res);
        Ts--;
    }
    F[x][y] = 'C';
    BFS(F, x, y + 1, d + 1);
    BFS(F, x + 1, y, d + 1);
    BFS(F, x, y - 1, d + 1);
    BFS(F, x - 1, y, d + 1);
}

int main()
{
    int I_x, I_y;
    cin >> n >> m;
    FLAT flat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char buf;
            cin >> buf;
            if (buf == 'I') {
                I_x = i;
                I_y = j;
            } else if (buf == 'T') {
                Ts++;
            }
            flat[i][j] = buf;
        }
    }
    BFS(flat, I_x, I_y, 0);
    cout << (Ts != 0 ? -1 : res) << '\n';
    return 0;
}