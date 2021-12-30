#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool GreaterThan(const string& a, const string& b)
{
    if (a.length() < b.length())    return false;
    if (a.length() > b.length())    return true;

    int l = a.length();
    for (int i = 0; i < l; i++)
        if (a[i] > b[i])    return true;
    return false;
}

bool LessThan(const string& a, const string& b)
{
    if (a.length() > b.length())    return false;
    if (a.length() < b.length())    return true;

    int l = a.length();
    for (int i = 0; i < l; i++)
        if (a[i] < b[i])    return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string order, min = "", max = "";
    vector<string>      D(1, "");
    map<string, int>    record;

    cin >> n;
    while (n--)
    {
        cin >> order;
        if (order == "insert") {
            string a_i;
            cin >> a_i;
            D.push_back(a_i);
            // cout << "a_i's length: " << D[D.size()-1].length() << '\n';
            // cout << "a_i: ";
            // for (int i = 0; i < D[D.size()-1].length(); i++)
            //     cout << D[D.size() - 1][i];
            // cout << '\n';
            if (record.find(a_i) == record.end())
                record.insert(pair<string, int>({a_i, 1}));
            else
                record[a_i]++;

            if (max == "" || GreaterThan(a_i, max)) {
                max = a_i;
            }
            if (min == "" || LessThan(a_i, min)) {
                min = a_i;
            }
            // if (a_i.length() < min.length() || min == "") {
            //     min = a_i;
            // } else if (a_i.length() == min.length()) {
            //     int l = a_i.length();
            //     for (int i = 0; i < l; i++)
            //         if (a_i[i] < min[i]) {
            //             min = a_i;
            //             break;
            //         }
            // }
        } else if (order == "min" && min != "") {
            cout << min << '\n';
            // for (int i = 0; i < D[min].length(); i++)
            //     cout << D[min][i];
            // cout << '\n';
        } else if (order == "max" && max != "") {
            cout << max << '\n';
            // for (int i = 0; i < D[max].length(); i++)
            //     cout << D[max][i];
            // cout << '\n';
        } else if (order == "find") {
            int idx;
            cin >> idx;
            if (idx < D.size()) cout << D[idx] << '\n';
            // if (idx < D.size()) {
            //     for (int i = 0; i < D[idx].length(); i++)
            //         cout << D[idx][i];
            //     cout << '\n';
            // }
        } else if (order == "amount") {
            string num;
            cin >> num;
            if (record.find(num) == record.end())
                cout << 0 << '\n';
            else
                cout << record[num] << '\n';
        }

        // for (int i = 0; i < D.size(); i++) {
        //     cout << i << ": " << D[i] << '\n';
        // }
    }
    return 0;
}