#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using EDGE = pair<int, int>;
using EDGES = vector<EDGE>;
using VERTICES = vector<pair<bool, EDGES>>;

int N;
bool found = false;

void DFS(VERTICES& vertices, int now, int prev)
{
    // cout << "DFS on " << now << '\n';
    if (found)  return;
    vertices[now - 1].first = true;
    for (auto edge : vertices[now - 1].second) {
        if (found)  return;
        int next_vertex = (now == edge.first) ? edge.second : edge.first;
        // cout << "next: " << next_vertex << '\n';
        if (next_vertex == prev)    continue;
        if (vertices[next_vertex - 1].first == false) {
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
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ": ";
        auto last_edge = vertices.end();
        last_edge--;
        for (auto edge : vertices[i].second)
            cout << '(' << edge.first << ", " <<  edge.second << "), ";
        cout << '\n';
    }
}

int main()
{
    cin >> N;
    VERTICES vertices(N);
    EDGES edges(N);
    
    for (int i = 0; i < N; i++) {
        cin >> edges[i].first >> edges[i].second;
        vertices[edges[i].first - 1].second.push_back(edges[i]);
        vertices[edges[i].second - 1].second.push_back(edges[i]);
    }
    // PRINTVERTICES(vertices);
    DFS(vertices, 1, 0);

    return 0;
}