#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void PRINTCHARSET(const vector<vector<int>>& charset)
{
    for (int i = 0; i < 26; i++) {
        if (charset[i].empty()) continue;
        char buf = i + 'a';
        cout << buf << ": ";
        for (auto idx : charset[i])
            cout << idx + 1 << ' ';
        cout << '\n';
    }
}

void DFS(const vector<vector<int>>& nodes, const vector<vector<int>>& charset, bool (&visited)[26], const int now)
{
    visited[now] = true;
    for (auto next : charset[now])
        for (auto idx : nodes[next])
            if (!visited[idx])  DFS(nodes, charset, visited, idx);
}

void SOL()
{
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> nodes(n), charset(26);
    bool visited[26] = {0};
    for (int i = 0; i < n; i++) {
        string buf;
        bool repeated_char[26] = {0};
        cin >> buf;
        for (auto c : buf) {
            int idx = c - 'a';
            if (repeated_char[idx]) continue;
            repeated_char[idx] = true;
            nodes[i].push_back(idx);
            charset[idx].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (auto c : nodes[i]) {
            char buf = c + 'a';
            cout << buf << ' ';
        }
        cout << '\n';
    }

    PRINTCHARSET(charset);

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 26; i++) {
        if (visited[i] || charset[i].empty())   continue;
        ans++;
        DFS(nodes, charset, visited, i);
    }
    cout << ans << "\n\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) SOL();
    return 0;
}