#include<bits/stdc++.h>
using namespace std;

int minEdgeBFS(vector <int> edges[],int u, int v, int n) {
    vector<bool> visited(n, 0);
    vector<int> distance(n, 0);

    queue<int> q;
    q.push(u);
    visited[u] = true;
    distance[u] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it: edges[node]) {
            if(visited[it]) {
                continue;
            }
            distance[it] = distance[node] +1;
            q.push(it);
            visited[it] = true;
        }
    }
    return distance[v];
}

void addEdge(vector <int> edges[], int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
};

int main() {
    int n = 9;

    vector <int> edges[9];

    addEdge(edges, 0, 1);
    addEdge(edges, 0, 7);
    addEdge(edges, 1, 7);
    addEdge(edges, 1, 2);
    addEdge(edges, 2, 3);
    addEdge(edges, 2, 5);
    addEdge(edges, 2, 8);
    addEdge(edges, 3, 4);
    addEdge(edges, 3, 5);
    addEdge(edges, 4, 5);
    addEdge(edges, 5, 6);
    addEdge(edges, 6, 7);
    addEdge(edges, 7, 8);

    int u = 0;

    int v = 5;

    cout << minEdgeBFS(edges, u, v, n);

    return 0;
}
