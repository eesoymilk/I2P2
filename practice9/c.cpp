#include <cstdio>
const int MAX_N=1e4+4;

int n, r;
int x[MAX_N], y[MAX_N];
int visited[MAX_N];
int cat, hole;

int dist2(int i, int j)
{ return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]); }
int dfs(int now)
{
	visited[now] = true;
	int res = 1;
	for(int i=0; i<n; i++)
		if(!visited[i] && dist2(now,i)<=r*r)
			res += dfs(i);
	return res;
}

int main()
{
	scanf("%d%d", &n, &r);
	for(int i=0; i<n; i++) scanf("%d%d", &x[i], &y[i]);
	for(int i=0; i<n; i++)
		if(!visited[i])
		{
			int cnt = dfs(i);
			if(cnt==1) cat++;
			else hole++;
		}
	printf("%d %d\n", cat, hole);
	return 0;
}