#include <iostream>
#include <vector>
#define UB 90
using namespace std;

int main()
{
    unsigned long long n, f1, tmp;
    vector<unsigned long long> fib(2, 1);
    for (int i = 2; i < UB; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    // for (int i = 0; i < UB; i++) {
    //     cout << i << ": " << fib[i] << '\n';
    // }
    while (cin >> n)
    {
        if (n <= 1) {
            cout << "0\n";
            continue;
        }
        f1 = n - 1;
        for (int i = 0; fib[i] <= n; i++) {
            if ((n - fib[i]) % fib[i + 1] == 0) {
                tmp = (n - fib[i]) / fib[i + 1];
                f1 = tmp < f1 ? tmp : f1;
            }
        }
        cout << f1 << '\n';
    }

    return 0;
}