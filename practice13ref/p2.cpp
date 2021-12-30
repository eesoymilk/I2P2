#include <bits/stdc++.h>
using namespace std;

int t,n,q;
int L[5007];
int R[5007];
int s[5007];
int ps[5007];

int main(int argc, char *argv[])
{
	cin >> t;
	while (t--) {
		memset(s,0,sizeof(s));
		cin >> n >> q;
		for (int i=1; i<=q; ++i) {
			cin >> L[i] >> R[i];
			for (int j=L[i]; j<=R[i]; ++j) s[j]++;
		}
		ps[0] = 0;
		int ans = 0, guarded, min_remove;
		for (int i=1; i<=q; ++i) {
			for (int j=L[i]; j<=R[i]; ++j) s[j]--;
			guarded = 0;
			for (int j=1; j<=n; ++j) {
				if (s[j] > 0) guarded++;
				ps[j] = (s[j] == 1 ? 1 : 0) + ps[j-1];
			}
			// remove one more guard
			min_remove = 10000;
			for (int j=1; j<=q; ++j) if (i != j)
				min_remove = min(min_remove, ps[R[j]] - ps[L[j]-1]);
			if (guarded - min_remove > ans) ans = guarded - min_remove;
			for (int j=L[i]; j<=R[i]; ++j) s[j]++; // restore
		}
		cout << ans << endl;
	}
	return 0;
}
