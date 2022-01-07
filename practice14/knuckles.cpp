#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using CHARSET = pair<bool, vector<int>>;

void PrintCharSet(vector<vector<int>>& C)
{
    for (int i = 0; i < 26; i++) {
        if (C[i].empty())   continue;
        char c = i + 'a';
        cout << c << ": ";
        for (auto key : C[i])
            cout << key << ' ';
        cout << '\n';
    }
}

void DFS(vector<vector<int>>& K, CHARSET (&C)[26], int now)
{
    C[now].first = true;
    for (auto idx : C[now].second) {
        for (auto c_idx : K[idx]) {
            if (C[c_idx].first) continue;
            DFS(K, C,  c_idx);
        }
    }
}

void SOL()
{
    int n, g = 0;
    CHARSET charset[26];
    cin >> n;
    vector<vector<int>> knuckles(n);

    for (int i = 0; i < n; i++) {
        bool repeated_char[26] = {0};
        string buf;
        cin >> buf;
        for (auto c : buf) {
            int idx = c - 'a';
            if (repeated_char[idx]) continue;
            repeated_char[idx] = true;
            knuckles[i].push_back(idx);
            charset[idx].second.push_back(i);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (charset[i].first || charset[i].second.empty())   continue;
        DFS(knuckles, charset, i);
        g++;
    }
    cout << g << '\n';
    return;
}

int main(){int t;cin>>t;while(t--)SOL();return 0;}