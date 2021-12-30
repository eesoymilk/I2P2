#include <bits/stdc++.h>
using namespace std;
#define INF ((int)2e9)

int t,n,m,k;
int a[5007];

int main (int argc, char *argv[])
{
  cin >>t;
  while (t--) {
    cin >>n>>m>>k;
    if (k >= m) k = m-1;
    for (int i=0; i<n; i++)
      cin >> a[i];
    int ans = 0, least;
    for (int i=0; i<=k; i++) {
      least = INF;
      for (int j=0; j<m-k; j++)
        least = min(max(a[i+j], a[i+j+(n-m)]), least);     
      ans = max(least, ans);
    }
    cout << ans << endl;
  }
  return 0;
}

/* int main (int argc, char *argv[]) */
/* { */
/*   cin >>t; */
/*   while (t--) { */
/*     cin >>n>>m>>k; */
/*     if (k >= m) k = m-1; */
/*     for (int i=0; i<n; i++) */
/*       cin >> a[i]; */
/*     int ans = 0, least; */
/*     for (int i=0; i<=k; i++) { */
/*       printf("i = %d\n", i); */
/*       least = INF; */
/*       for (int j=0; j<m-k; j++) { */
/*         printf("max(%d,%d)\n", a[i+j], a[i+j+(n-m)]); */
/*         least = min(max(a[i+j], a[i+j+(n-m)]), least); */     
/*       } */
/*       assert(least != INF); */
/*       printf("least = %d\n", least); */
/*       ans = max(least, ans); */
/*     } */
/*     cout << ans << endl; */
/*   } */
/*   return 0; */
/* } */
