#include <bits/stdc++.h>
using namespace std;
using WORD = pair<int, char>;

const set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

int main()
{
    int n, PM = 0, res = 0;
    map<WORD, int>  dict;
    map<int, int>   SV;
    cin >> n;
    while (n--) {
        WORD tmp = {0, '\0'};
        string buf;
        cin >> buf;
        for (auto c : buf) {
            if (VOWELS.find(c) == VOWELS.end()) continue;
            tmp.first++;
            tmp.second = c;
        }
        dict[tmp]++;
    }

    for (auto itr = dict.begin(); itr != dict.end(); itr++) {
        PM += (itr->second) / 2;
        if (itr->second % 2)    SV[(itr->first).first]++;
    }

    for (auto itr : SV) {
        int match = itr.second / 2;
        while (PM && match) {
            PM--;
            match--;
            res++;
        }
    }
    res += PM / 2;
    cout << res << '\n';

    return 0;
}