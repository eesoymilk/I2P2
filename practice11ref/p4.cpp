#include <bits/stdc++.h>
using namespace std;

int t, n, r, k, a, b;

struct v2 {
	int x;
	int y;
} pos[507];
bool vis[507];

int dist2(const v2 &lhs, const v2 &rhs)
{
	int dx = lhs.x - rhs.x, dy = lhs.y - rhs.y;
	return dx*dx + dy*dy;
}

void dfs(int now, int *size)
{
	/* printf("dfs(%d, %d)\n", now, *size); */
	for (int i=0; i<n; i++)
		if (i != now && !vis[i] && dist2(pos[now], pos[i]) <= r*r) {
			vis[i] = true;
			(*size)++;
			dfs(i, size);
		}
}

int main()
{
	cin >> t;
	while (t--) {
		cin>>n>>r>>k;
		for (int i=0; i<n; i++)
			cin >> pos[i].x >> pos[i].y;
		memset(vis, 0, sizeof(vis));
		a = b = 0;
		int size;
		for (int i=0; i<n; i++)
			if (!vis[i]) {
				vis[i] = true;
				size = 1;
				dfs(i, &size);
				if (size < k) a++;
				else b++;
				/* printf("cluster with size %d\n", size); */
			}
		cout << a << ' ' << b << endl;
	}
	return 0;
}
