#include <iostream>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, sum = 0;
    string ins;
    cin >> n;
    map<int, int> DS;

    while (n--) {
        cin >> ins;
        if (ins == "insert") {
            int a_i;
            cin >> a_i;
            sum += a_i;
            if (DS.find(a_i) == DS.end())
                DS.insert(pair<int, int>(a_i, 1));
            else
                DS[a_i]++;
        } else if (ins == "print") {
            if (DS.empty()) continue;
            for (auto pair : DS) {
                for (int i = 0; i < pair.second; i++)
                    cout << pair.first << ' ';
            }
            cout << '\n';
        } else if (ins == "min") {
            if (DS.empty()) continue;
            cout << (*DS.begin()).first << '\n';
        } else if (ins == "sum") {
            cout << sum << '\n';
        } else if (ins == "range_amount") {
            int l, r, amount = 0;
            cin >> l >> r;
            for(auto iter = DS.lower_bound(l); iter != DS.upper_bound(r); iter++)
                amount += (*iter).second;
            cout << amount << '\n';
        }
    }

    return 0;
}