#include <bits/stdc++.h>
using namespace std;
#define MOD ((int)1e9+7)


string operator*(const string &lhs, int rhs)
{
	string ret = "";
	while (rhs--)
		ret += lhs;
	return ret;
}

int main()
{
	int x, t;
	string s;
	cin >> t;
	while (t--) {
		cin >> x >> s;
		long long ans = s.length();
		for (int i=1; i<=x; i++) {
			if ((int)s.length() <= 1000007)
				s = s.substr(0, i) + s.substr(i) * (s[i-1]-'0');
			ans = (i + (ans-i+MOD) % MOD * (s[i-1]-'0') % MOD) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
