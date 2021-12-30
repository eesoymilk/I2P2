#include <bits/stdc++.h>
using namespace std;

int t, n,m;
int a[200007];

int day(int d)
{
	int loc = 0;
	for (int i=0; i<n; i++)
		loc += max(a[i] - i/d, 0);
	return loc;
}

int main(int argc, char *argv[])
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) cout << a[i] << ' ';
		cout << '\n';
		sort(a, a+n, [](int lhs, int rhs) { return lhs > rhs; });
		for (int i=0; i<n; ++i) cout << a[i] << ' ';
		cout << '\n';
		int L=1, R=n+1, M, ans=n+1;
		while (L<R) {
			M = (L+R)/2;
			if (day(M) < m)
				L = M + 1;
			else {
				ans = min(ans, M);
				R = M;
			}
		}
		if (ans == n+1) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
