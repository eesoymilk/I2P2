#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX_N = 1001;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
char table[MAX_N][MAX_N];
queue<tuple<int, int, int>> q;
int ans = 0;
int d = 0;

void bfs()
{
	while(!q.empty())
	{
		auto [x, y, s] = q.front(); // C++17: structured binding declaration
		q.pop();
		if(x<0 || n<=x) continue;
		if(y<0 || m<=y) continue;
		if(table[x][y] == 'C') continue;
		if(table[x][y] == 'T') ans = max(ans, s), d--;
		table[x][y] = 'C';
		for(int i=0; i<4; i++)
			q.push({x+dx[i], y+dy[i], s+1});
	}
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++) scanf("%s", table[i]);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++)
		if(table[i][j] == 'I') q.push({i, j, 0});
		else if(table[i][j] == 'T') d++;
	bfs();
	printf("%d\n", d!=0?-1:ans);
	return 0;
}