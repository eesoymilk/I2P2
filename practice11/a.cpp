#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <string>
using namespace std;

const set<char> VOWEL = {'a', 'e', 'i', 'o', 'u'};

// Possible # of first/second words in both lines of the lyric
int PerfectMatch = 0, VowelCntMatch[201] = {0};

class WORD
{
private:
public:
    int cnt_v = 0;
    char lst_v = '\0';
    WORD(const string& word)
    {
        for (auto c : word) {
            if (VOWEL.find(c) != VOWEL.end()) {
                cnt_v++;
                lst_v = c;
            }
        }
    }
};

// A lyric is good if and only if:

// the first line's first word contains as many vowels as the second line's first word
// the first line's second word contains as many vowels as the second line's second word.
// the last vowel of first line's second word is same as the last vowel of second line's second word

int main()
{
    int n, res;
    string buf;
    map<WORD, int> dict;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        WORD word(buf);
        if (dict.find(word) != dict.end()) {
            dict.insert(pair<WORD, int>(word, 1));
        } else {
            dict[word]++;
        }
    }

    // count maximum numbers of possible sw;
    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second >= 2)
            PerfectMatch += iter->second / 2;
        if (iter->second %= 2)
            VowelCntMatch[(iter->first).cnt_v]++;
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