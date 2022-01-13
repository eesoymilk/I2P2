#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long int sum = 0;
    set<int> a, s;
    cin >> n;
    while (n--) {
        string ins;
        cin >> ins;
        if (ins == "insert") {
            int a_i;
            cin >> a_i;
            if(a.insert(a_i).second)
                sum += a_i;
        } else if (ins == "print") {
            vector<int> output;
            for(auto ele : a) output.push_back(ele);
            for(int i = 0; i < output.size(); i++)
                cout << output[i] << ((i == output.size() - 1) ? '\n' : ' ');
        } else if (ins == "min") {
            if (a.empty())  continue;
            cout << *a.begin() << '\n';
        } else if (ins == "range_erase") {
            int l, r;
            cin >> l >> r;
            for (auto itr = a.lower_bound(l); itr != a.lower_bound(r); itr++)
                sum -= *itr;
            a.erase(a.lower_bound(l), a.upper_bound(r));
        } else if (ins == "sum") {
            cout << sum << '\n';
        }
    }
}