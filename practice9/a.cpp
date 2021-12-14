#include <bits/stdc++.h>
#define LL long long int
#define Max(x, y) (x > y ? x : y)
#define Min(x, y) (x < y ? x : y)
#define IO_BOOST                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
using namespace std;

LL sum = 0;
set<int> s;
int main() 
{
    IO_BOOST;
    int n;
    cin >> n;
    while (n--) {
        string order;
        cin >> order;
        if ( order == "min" ) {
            if (s.empty()) continue;
            cout << *s.begin() << '\n';
        } else if ( order == "range_erase" ) {
            int l, r;
            cin >> l >> r;
            for(auto x = s.lower_bound(l); x != s.upper_bound(r); x++)
                sum -= *x;
            s.erase(s.lower_bound(l), s.upper_bound(r));
        } else if ( order == "insert" ) {
            int x;
            cin >> x;
            if(s.insert(x).second)
                sum += x;
        } else if ( order == "print" ) {
            vector<int> output;
            for(auto i: s) output.push_back(i);
            for(int i = 0; i < output.size(); i++)
                cout << output[i] << ((i == output.size()-1) ? '\n' : ' ');
        } else if ( order == "sum" ) {
            cout << sum << '\n';
        }
    }
}