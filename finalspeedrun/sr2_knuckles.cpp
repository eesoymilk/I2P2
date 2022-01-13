#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



void DFS(vector<vector<int>>& K, vector<vector<int>>& C, bool (&V)[26], int now)
{
    V[now] = true;
    for (auto next : C[now]) {
        for (auto idx : K[next]) {
            if (V[idx] || C[idx].empty())   continue;
            DFS(K, C, V, idx);
        }
    }
}

void SOL()
{
    int n, groups = 0;
    cin >> n;
    vector<vector<int>> knuckles(n), charset(26);
    bool visited[26] = {0};
    for (int i = 0; i < n; i++) {
        string buf;
        cin >> buf;
        bool repeated_char[26] = {0};
        for (auto c : buf) {
            int idx = c - 'a';
            if (repeated_char[idx]) continue;
            repeated_char[idx] = true;
            knuckles[i].push_back(idx);
            charset[idx].push_back(i);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (visited[i] || charset[i].empty())   continue;
        DFS(knuckles, charset, visited, i);
        groups++;
    }
    cout << groups << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) SOL();
    return 0;
}