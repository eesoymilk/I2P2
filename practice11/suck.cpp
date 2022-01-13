#include <iostream>
#include <vector>
#include <set>
#include <string>
#define MOD ((int)1e9+7)
using namespace std;

void SOL()
{
    int x;
    long long len;
    string str;
    cin >> x >> str;
    len = str.length();
    for (int i = 1; i <= x; i++) {
        int t = str[i - 1] - '0';
        if (str.length() <= 1000007) {
            string paste = str.substr(i);
            str = str.substr(0, i);
            for (int j = 0; j < t; j++) str += paste;
        }
        len = (i + (len - i + MOD) % MOD * t) % MOD;
    }
    cout << len << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) SOL();
    return 0;
}