#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using EDGE = pair<int, int>;
using EDGES = vector<EDGE>;
using VERTICES = vector<pair<bool, EDGES>>;

int n;
bool found;

void DFS(VERTICES& vertices, int now, int prev)
{
    // cout << "DFS on " << now << '\n';
    if (found)  return;
    vertices[now].first = true;
    for (auto edge : vertices[now].second) {
        if (found)  return;
        int next_vertex = (now == edge.first) ? edge.second : edge.first;
        // cout << "next: " << next_vertex << '\n';
        if (next_vertex == prev)    continue;
        if (vertices[next_vertex].first == false) {
            DFS(vertices, next_vertex, now);
        } else {
            cout << next_vertex << '\n';
            found = true;
            return;
        }
    }
    return;
}

void PRINTVERTICES(VERTICES& vertices)
{
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        auto last_edge = vertices.end();
        last_edge--;
        for (auto edge : vertices[i].second)
            cout << '(' << edge.first << ", " <<  edge.second << "), ";
        cout << '\n';
    }
}

void Sol()
{
    cin >> n;
    VERTICES vertices(n);
    EDGES edges(n);
    
    for (int i = 0; i < n; i++) {
        cin >> edges[i].first >> edges[i].second;
        vertices[edges[i].first].second.push_back(edges[i]);
        vertices[edges[i].second].second.push_back(edges[i]);
    }
    // PRINTVERTICES(vertices);
    DFS(vertices, 0, -1);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        found = false;
        Sol();
    }

    return 0;
}