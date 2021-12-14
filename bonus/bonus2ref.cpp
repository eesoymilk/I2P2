#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k, md = 10;

int digits(int x)
{
	int len = 1;
	while (x/=10)
		len++;
	return len;
}

ll a[200003];

int main()
{
	while (cin>>n>>k) {
		map<int,int> rem[md+1];
		for (ll i=0; i<n; i++) {
			cin >> a[i];
			rem[digits(a[i])][a[i] % k]++;
		}

		ll exp[md+1]; // 10^i mod k
		exp[0] = 1;
		for (ll i=1; i<=md; i++)
			exp[i] = exp[i-1] * 10 % k;

		long long ans = 0;
		for (int i=0; i<n; i++) {
			for (int j=1; j<=md; j++) {
				// find complements a[j] such that
				// ( (a[i] * 10^digits(a[j]) mod k) + (a[j] mod k) ) mod k = 0
				// then a[i] concat a[j] is a solution.
				ll x = a[i] * exp[j] % k;
				assert(x < k);
				ans += rem[j][(k-x)%k];
				// might overcount a[i] concat a[i]
				if (digits(a[i]) == j && (x + a[i] % k) % k == 0)
					ans--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
