#include <bits/stdc++.h>
using namespace std;

// count vowel, last vowel
using word = pair<int, char>;
map<word, int> words;
int bin[207]; // same countv, different lastv
int duo = 0;  // number of pairs of word with same countv and same lastv

word getword(const string &s)
{
	set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
	int countv = 0;
	char lastv = 0;
	for (auto c : s)
		if (vowel.find(c) != vowel.end()) {
			countv++;
			lastv = c;
		}
	return { countv, lastv };
}

void debug()
{
	for (auto ite = words.begin(); ite != words.end(); ite++)
		printf("(%d, %c) %d\n", ite->first.first, ite->first.second, ite->second);
	printf("duo = %d\n", duo);
	for (int i=1; i<= 200; i++)
		if (bin[i])
			printf("bin[%d] = %d\n", i, bin[i]);
}

int main()
{
	string s;
	int n;
	memset(bin, 0, sizeof(bin));
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		word w = getword(s);
		if (words.find(w) == words.end()) {
			words[w] = 1;
		} else {
			words[w]++;
		}
	}
	// preprocess
	for (auto ite = words.begin(); ite != words.end(); ite++)
		if (ite->second >= 2) {
			duo += ite->second / 2;
			ite->second %= 2;
		}
	for (auto ite = words.begin(); ite != words.end(); ite++)
		if (ite->second == 1)
			bin[ite->first.first]++;
	/* debug(); */
	// greedy matching
	int ans = 0;
	for (int i=1; i<=200; i++)
		while (duo && bin[i] >= 2) {
			duo--;
			bin[i] -= 2;
			ans++;
		}
	ans += duo / 2;
	cout << ans << endl;
	return 0;
}
