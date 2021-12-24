#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void PrintA(vector<vector<double>>& A)
{
    for (auto row : A) {
        for (auto val : row)
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m;
    cin >> T;

    while (T--) {
        double res = 0, buf;
        int deno;
        cin >> n >> m;
        vector<vector<double>> A(n, vector<double>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { cin >> A[i][j]; }

        if (n > 1 || m > 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i + 1 < n)
                        if ((buf = A[i][j] * A[i + 1][j]) > res)
                            res = buf;
                    if (j + 1 < m)
                        if ((buf = A[i][j] * A[i][j + 1]) > res)
                            res = buf;
                }
            }
            res = -sqrt(res);
        } else {
            res = A[0][0];
        }
        cout << res << '\n';
    }

    return 0;
}