#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <string>
using namespace std;

set<char> VOWEL = {'a', 'e', 'i', 'o', 'u'};

class WORD
{
private:
    int cnt_v = 0;
    char last_v = '\0';
public:
    WORD(string& word)
    {
        for (auto c : word) {
            if (VOWEL.find(c) != VOWEL.end()) {
                cnt_v++;
                last_v = c;
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
    int n;
    string buf;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> buf;
        // WORD word(buf);
        cout << "hi\n";
    }

    return 0;
}