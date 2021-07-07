#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<vector<int>> g[N];
vector<bool> visited(N);
vector<int> dist(N);
const int inf = 1e9;

void dijkstraMinDist(int src) {
    for(int i=0; i<N; i++) {
        dist[i] = inf;
    }

    dist[src] = 0;
    set<vector<int>> s;
    s.insert({src, dist[src]});

    while(!s.empty()) {
        auto node = *(s.begin());
        s.erase(node);

        for(auto it: g[node[0]]) {
            if(dist[it[0]] > it[1] + dist[node[0]]) {
                s.erase({it[0], dist[it[0]]});
                dist[it[0]] = it[1] + dist[node[0]];
                s.insert({it[0], dist[it[0]]});
            }
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int src;
    cin>>src;

    dijkstraMinDist(src);

    for(int i=1; i<=n; i++) {
        if(dist[i] == inf) {
            cout<<"-1"<<endl;
        } else {
            cout<<dist[i]<<" ";
        }
    }
    
    return 0;
}

// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1