#include <stdio.h>
#define ll long long

ll fib[100];
ll n, x, ans;

// 1000000000000000000
// 679891637638612258

int main()
{
	fib[0] = 0;
	fib[1] = 1;
	int i;
	for (i=2; i<89; i++)
		fib[i] = fib[i-1] + fib[i-2];
	// for (i=2; i<89; i++)
	// cout << i << ' ' << fib[i] << endl;
	while (scanf("%lld", &n) != EOF) {
		if (n <= 1) {
			puts("0");
			continue;
		}
		ans = n-1;
		for (i=0; fib[i] <= n; i++) {
			if ((n - fib[i]) % fib[i+1] == 0) {
				x = (n - fib[i]) / fib[i+1];
				if (x < ans)
					ans = x;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
