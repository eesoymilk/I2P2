#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,p,k,t;
ll a[300007];
ll b[300007];

int main()
{
	cin >> t;
	while (t--) {
		cin >>n>>p>>k;
		for (int i=1; i<=n; i++)
			cin >> a[i];
		sort(a+1, a+n+1);
		b[0] = 0;
		for (int i=1; i<=n; i++) {
			if (i-k >= 0)
				b[i] = a[i] + b[i-k];
			else
				b[i] = a[i] + b[i-1];
		}
		/* for (int i=1; i<=n; i++) */
		/* 	cout << b[i] << ' '; */
		/* putchar('\n'); */
		int ans = 0;
		for (int i=n; i>=1; i--)
			if (b[i] <= p) {
				ans = i;
				break;
			}
		cout << ans << endl;
	}
	return 0;
}
