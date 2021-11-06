#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MOD 1000000007

typedef struct A {
	int idx;
	int val;
	int sol; // solution from fme
} A;

int n, q;
int rep[1000007]; // check for repeating A
A a[1000007];

// fast modular exponentiation over 1e9+7
int fme(long long p)
{
	long long ans = 1;
	long long base = 2;
	/* assert(p>=0); */
	while (p) {
		if (p & 1)
			ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		p >>= 1;
	}
	return ans;
}

int cmp(const void *l, const void *r)
{
	const A *L = (const A *)l;
	const A *R = (const A *)r;
	/* assert(L->sol != R->sol); */
	return L->sol > R->sol;
}

int main(int argc, char *argv[])
{
	int i, j, k, val, sol, has_odd;
	char trash[128];
	while (scanf("%d%d\n", &n, &q)==2) {
		memset(a, 0, sizeof(a));
		memset(rep, 0, sizeof(rep));
		has_odd = 0;
		// parse stupid input format
		for (i = k = 0; i < n; i++) {
			scanf("%s", trash);
			for (val = j = 0; trash[j] >= '0' && trash[j] <= '9'; j++) {
				val *= 10;
				val += trash[j] - '0';
			}
			scanf("%s", trash);
			// sieve duplicate solutions
			if (val & 1) { // odd val has 0 solution
				if (has_odd)
					continue;
				has_odd = 1;
				sol = 0;
			} else  { // even val always has solutions: pow(2, a[i].val/2)
				if (rep[val])
					continue;
				rep[val] = 1;
				sol = fme(val/2);
			}
			a[k].idx = i;
			a[k].val = val;
			a[k].sol = sol;
			k++;
		}
		n = k;
		qsort(a, n, sizeof(A), cmp);
		/* for (i=0; i<n; i++) */
		/* 	printf("(%d %d %d)\n", a[i].idx, a[i].val, a[i].sol); */
		// binary search index to answer queries in q * log(n) time
		int l, r, m;
		while (q--) {
			scanf("%d", &val);
			l = 0;
			r = n-1;
			while (l < r) { // infinite loop if there are no 0 solutions
				m = (l+r)/2;
				/* printf("binary serach(%d, %d, %d)\n", l, r, m); */
				if (val <= a[m].sol)
					r = m;
				else
					l = m+1;
			}
			m = (l+r)/2;
			if (val == a[m].sol)
				printf("%d\n", a[m].idx+1);
			else
				puts("Go Down Chicken 404");
		}
	}
	return 0;
}