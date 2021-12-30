#include <bits/stdc++.h>
#include <ostream>
using namespace std;
#define ll long long
#define ull unsigned long long

int t;
ll n;

// number of tournaments for n = a << b students
ll f(ll a, ll b)
{
  cout << "f(" << a <<"," << b<<") = ";
  flush(cout);
  assert(a % 2 == 1 && (a-1)/2*a >= 0);
  ll res = a * ((1<<b)-1) + (a-1)/2*a;
  /* assert(res >= 0); // guard overflow */
  cout << res<<endl;
	return res;
}

int main()
{
  // 576460752303423487 == 1<<59 - 1
  cout << (576460752303423487 >> 58) << endl;
	cin >> t;
	while (t--) {
		cin >> n;
    ll a, b, l, r, m;
    ll ans = -1, res;
    for (b = 0; (n >> b) > 0 ; b++) {
      l = 1, r = (n >> b);
      printf("b = %lld, l = %lld, r = %lld\n", b,l,r);
      while (l < r) {
        m = (l+r)/2, a = 2*m - 1;
        res = f(a, b);
        if (res < n)
          l = m+1;
        else {
          r = m;
          if (res == n)
            ans = (ans == -1) ? (a<<b) : min(ans, a<<b);
        }
      }
      m = (l+r)/2, a = 2*m - 1;
      if (f(a, b) == n)
        ans = min(ans, a << b);
      printf("(%lld, %lld) n = %lld, f(n) = %lld\n", a, b, a<<b, f(a, b));
    }
    cout << ans << endl;
	}
	return 0;
}
