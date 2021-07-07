#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<vector<int>> g;
vector<int> dist(N);
const int inf = 1e9;


void bellmanFordMinDist(int src, int n) {
    for(int i=0; i<N; i++) {
        dist[i] = inf;
    }

    dist[src] = 0;
    for(int i=1; i<n; i++) {
        for(auto it: g) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] +w;
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        g.push_back({u, v, w});
    }

    int src;
    cin>>src;
    bellmanFordMinDist(src, n);
    for(int i=0; i<n; i++) {
        cout<<dist[i]<<" ";
    }

    return 0;
}

// 5 8
// 1 2 3
// 3 2 5
// 1 3 2
// 3 1 1
// 1 4 2
// 0 2 4
// 4 3 -3
// 0 1 -1
// 0