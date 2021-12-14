#include <bits/stdc++.h>
using namespace std;

int n, m;
int x;
int MIN = 1e9+7;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) 
            scanf("%d", &x), MIN = min(MIN, x);
    printf("%d\n", MIN);
}