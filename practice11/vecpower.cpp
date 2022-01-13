#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> V;
    set<pair<int, int>> S;
    while (n--) {
        string order;
        cin >> order;
        if (order == "push_back") {
            int num;
            cin >> num;
            V.push_back(num);
            S.insert({num, V.size()});
        } else if (order == "pop_back") {
            if (V.empty())  continue;
            S.erase({*V.rbegin(), V.size()});
            V.pop_back();
        } else if (order == "find") {
            int idx;
            cin >> idx;
            if (idx > V.size()) continue;
            cout << V[idx - 1] << '\n';
        } else if (order == "min") {
            if (V.empty())  continue;
            auto itr = S.begin();
            cout << itr->first << ' ' << itr->second << '\n';
        } else if (order == "max") {
            if (V.empty())  continue;
            auto itr = S.rbegin();
            cout << itr->first << ' ' << itr->second << '\n';
        }
    }
    return 0;
}