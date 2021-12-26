#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, i, min = 0, max = 0;
    string order, x;
    vector<string> DS(1, "");

    // DS.push_back("hello");
    // for (int i = 0; i < DS.size(); i++) {
    //     cout << i << ": " << DS[i] << '\n';
    // }

    // cout << DS[0].length() << '\n';
    cin >> n;
    while (n--)
    {
        cin >> order;
        if (order == "Insert") {
            cin >> x;
            DS.push_back(x);
            if (x.length() > DS[max].length()) {
                max = DS.size() - 1;
            } else if (x.length() == DS[max].length()) {
                for (int i = 0; i < x.length(); i++)
                    if (x[i] > DS[max][i]) {
                        max = DS.size() - 1;
                        break;
                    }
            }
            if (x.length() < DS[max].length()) {
                min = DS.size() - 1;
            } else if (x.length() == DS[min].length()) {
                for (int i = 0; i < x.length(); i++)
                    if (x[i] < DS[min][i]) {
                        min = DS.size() - 1;
                        break;
                    }
            }
        } else if (order == "Min") {
            cout << "min = " << min << '\n';
            cout << DS[min] << '\n';
        } else if (order == "Max") {
            cout << "max = " << max << '\n';
            cout << DS[max] << '\n';
        } else if (order == "Index") {
            cin >> i;
            if (i > DS.size() - 1)
            cout << DS[i] << '\n';
        }

        // for (int i = 0; i < DS.size(); i++) {
        //     cout << i << ": " << DS[i] << '\n';
        // }
    }
    return 0;
}