#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<vector<int>> graph(N);
vector<int> distance(N);
vector<bool> vis(N);

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    return 0;
}
