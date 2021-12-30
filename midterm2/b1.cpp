#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, min = -1, max = -1;
    string order;
    vector<int>     DS(1);
    map<int, int>   record;

    cin >> n;
    while (n--)
    {
        cin >> order;
        if (order == "insert") {
            int a_i;
            cin >> a_i;
            DS.push_back(a_i);
            if (record.find(a_i) == record.end())
                record.insert(pair<int, int>({a_i, 1}));
            else
                record[a_i]++;
            if (a_i > max || max == -1) {
                max = a_i;
            }
            if (a_i < min || min == -1) {
                min = a_i;
            }
        } else if (order == "min" && min != -1) {
            cout << min << '\n';
        } else if (order == "max" && max != -1) {
            cout << max << '\n';
        } else if (order == "find") {
            int idx;
            cin >> idx;
            if (idx < DS.size())
                cout << DS[idx] << '\n';
        } else if (order == "amount") {
            int num;
            cin >> num;
            if (record.find(num) == record.end())
                cout << 0 << '\n';
            else
                cout << record[num] << '\n';
        }

        // for (auto log : record) {
        //     cout << log.first << ": " << log.second << '\n';
        // }
        // for (int i = 0; i < DS.size(); i++) {
        //     cout << i << ": " << DS[i] << '\n';
        // }
    }
    return 0;
}