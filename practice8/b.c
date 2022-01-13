#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005

int n;
int a[MAX_N];

int cmp(const void *L, const void *R)
{
	int l = *(int*)L, r = *(int*)R;
	if(l > r) return 1;
	else if(l < r) return -1;
	else return 0;
}

int UPB(int t)
{
	int l=0, r=n, mid;
	while(l<r) {
		mid = (l+r)/2;
		if(a[mid] > t) r = mid;
		else l = mid+1;
	} return r;
}

int LOB(int t)
{
	int l=0, r=n, mid;
	while (l < r) {
		mid = (l+r)/2;
		if(a[mid] >= t) r = mid;
		else l = mid+1;
	}
	return r;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	int q, x;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &x);
		printf("%d\n", UPB(x)-LOB(x));
	}
}