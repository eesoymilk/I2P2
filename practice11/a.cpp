// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>
// #include <tuple>
// #include <string>
#include <bits/stdc++.h>
using namespace std;
using WORD = pair<int, char>;

const set<char> VOWEL = {'a', 'e', 'i', 'o', 'u'};
int PerfectMatch = 0, VowelCntMatch[201] = {0};

int main()
{
    int n, res = 0;
    string buf;
    map<WORD, int> dict;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        int cnt_v = 0;
        char last_v;
        for (auto c : buf) {
            if (VOWEL.find(c) == VOWEL.end())   continue;
            cnt_v++;
            last_v = c;
        }
        WORD word{cnt_v, last_v};
        dict[word]++;
    }

    // count maximum numbers of possible sw;
    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second >= 2)
            PerfectMatch += iter->second / 2;
        if (iter->second %= 2)
            VowelCntMatch[(iter->first).first]++;
    }
    // Greedy matching
    for (auto recur : VowelCntMatch) {
        recur /= 2;
        while (PerfectMatch && recur) {
            PerfectMatch--;
            recur--;
            res++;
        }
    }
    res += PerfectMatch / 2;
    cout << res << endl;

    return 0;
}