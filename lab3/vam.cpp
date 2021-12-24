#include <iostream>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long sum = 0;
    string order;
    cin >> n;
    map<int, int> DS;

    while (n--)
    {
        cin >> order;
        if (order == "insert") {
            int a_i;
            cin >> a_i;
            sum += a_i;
            if (DS.find(a_i) == DS.end())
                DS.insert(pair<int, int>(a_i, 1));
            else
                DS[a_i]++;
        } else if (order == "print") {
            if (DS.empty()) continue;
            for (auto iter = DS.begin(); iter != DS.end(); iter++) {
                for (int i = 0; i < (*iter).second; i++) {
                    cout << (*iter).first;
                    if (i + 1 < (*iter).second)
                        cout << ' ';
                }
                if (iter != --DS.end())
                    cout << ' ';
            }
            // for (auto pair : DS) {
            //     for (int i = 0; i < pair.second; i++)
            //         cout << pair.first << ' ';
            // }
            cout << '\n';
        } else if (order == "min") {
            if (DS.empty()) continue;
            cout << (*DS.begin()).first << '\n';
        } else if (order == "sum") {
            cout << sum << '\n';
        } else if (order == "range_amount") {
            int l, r, amount = 0;
            cin >> l >> r;
            for(auto iter = DS.lower_bound(l); iter != DS.upper_bound(r); iter++)
                amount += (*iter).second;
            cout << amount << '\n';
        }
    }
    return 0;
}