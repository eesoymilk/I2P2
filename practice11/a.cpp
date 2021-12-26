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

// Possible # of first/second words in both lines of the lyric
int PerfectMatch = 0, VowelCntMatch[201] = {0};

// A lyric is good if and only if:

// the first line's first word contains as many vowels as the second line's first word
// the first line's second word contains as many vowels as the second line's second word.
// the last vowel of first line's second word is same as the last vowel of second line's second word

int main()
{
    int n, res = 0;
    string buf;
    map<WORD, int> dict;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        // cout << "You typed: " << buf << '\n';
        int cnt_v = 0;
        char last_v;
        for (auto c : buf) {
            if (VOWEL.find(c) == VOWEL.end())
                continue;
            cnt_v++;
            last_v = c;
        }
        WORD word{cnt_v, last_v};

        // cout << '(' << word.first << ", " << word.second << ")\n";
        // cout << "Vowel Count: " << word.first << '\n';
        // cout << "Last Vowel: " << word.second << '\n';
        dict[word]++;
    }

    // for (auto word : dict) {
    //     cout << '(' << word.first.first << ", " << word.first.second << "): " << word.second << '\n';
    // }

    // count maximum numbers of possible sw;
    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second >= 2) {}
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