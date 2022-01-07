#include <iostream>
#include <vector>

void SOL()
{
    int A, B, C, D, n;
    long long res = 0;
    std::cin >> A >> B >> C >> D;
    n = B + C + 2;
    std::vector<long long> a(n), p(n), psum(n);

    for (int x = A; x <= B; x++) {
        a[x + B]++;
        a[x + C + 1]--;
    }
    for (int i = A + B; i < n; i++) {
        p[i] = a[i] + p[i - 1];
        psum[i] = p[i] + psum[i - 1];
    }
    for (int z = C; z <= D && z < B + C; z++) {
        res += psum[n - 1] - psum[z];
    }
    std::cout << res << '\n';
}

int main()
{
    int T;
    std::cin >> T;
    while (T--) SOL();
    return 0;
}