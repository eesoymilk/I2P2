#include <bits/stdc++.h>
using namespace std;
#define INF ((int)2e9)


int main()
{
	int n, x;
	string cmd;
	cin >> n;
	vector<int> v;
	set<pair<int,int>> s;
	while (n--) {
		cin >> cmd;
		if (cmd == "max" && v.size()) {
			auto ite = s.rbegin();
			cout << ite->first << ' ' << ite->second << endl;
		} else if (cmd == "min" && v.size()) {
			auto ite = s.begin();
			cout << ite->first << ' ' << ite->second << endl;
		} else if (cmd == "find") {
			cin >> x;
			if (x <= (int)v.size())
				cout << v[x-1] << endl;
		} else if (cmd == "pop_back") {
			if (!v.empty()) {
				int x = *v.rbegin(), p = v.size();
				v.pop_back();
				s.erase({x, p});
			}
		} else if (cmd == "push_back") {
			cin>>x;
			v.push_back(x);
			s.insert({x, v.size()});
		}
	}
	return 0;
}
