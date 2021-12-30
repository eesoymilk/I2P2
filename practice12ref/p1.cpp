#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	string cmd;
	set<pair<int, string>> s;
	string name;
	int age;
	for (int i=0; i<n; i++) {
		cin >> cmd;
		if (cmd == "born") {
			cin >> name >> age;
			s.insert({age, name});
		} else if (cmd == "find") {
			cin >> name >> age;
			cout <<  (s.find({age, name}) != s.end() ? "YES" : "NO") << endl;
		} else if (cmd == "kill") {
			cin >> name >> age;
			if (s.find({age, name}) != s.end())
				s.erase({age, name});
		} else if (cmd == "young") {
			if (!s.empty())
				cout << s.begin()->second << ' ' << s.begin()->first << endl;
		}
	}
	return 0;
}
