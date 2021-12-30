#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int n, age;
    string order, name;
    set<pair<int, string>> ppl;
    cin >> n;

    while (n--) {
        cin >> order;
        if (order == "born") {
            cin >> name >> age;
            ppl.insert({age, name});
        } else if (order == "find") {
            cin >> name >> age;
            if (ppl.find({age, name}) != ppl.end()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (order == "kill") {
            cin >> name >> age;
            if (ppl.find({age, name}) != ppl.end()) {
                ppl.erase({age, name});
            }
        } else if (order == "young") {
            if (!ppl.empty()) {
                cout << ppl.begin()->second << ' ' << ppl.begin()->first << '\n';
            }
        }
    }

    return 0;
}