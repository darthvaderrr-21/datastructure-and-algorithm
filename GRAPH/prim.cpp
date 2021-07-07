#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<vector<vector<int>>> graph(N);
vector<int> dist(N);
vector<int> parent(N);
vector<bool> visi(N);
int cost = 0;
const int inf = 1e9;

void primMST(int src) {
    for(int i=1; i<N; i++) {
        dist[i] = inf;
    }
    dist[src] = 0;

    set<vector<int>> s;
    s.insert({src,dist[src]});

    while(!s.empty()) {
        auto node = *(s.begin());
        s.erase(node);

        int u = node[0];
        int w = node[1];
        visi[u] = true;
        cost += w;

        for(auto it: graph[node[0]]) {
            if(visi[it[0]]) {
                continue;
            }
            if(dist[it[0]] > it[1]) {
                s.erase({it[0], dist[it[0]]});
                dist[it[0]] = it[1];
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
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
       
    }

    primMST(0);
    cout<<cost<<endl;
    
    return 0;
}

// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40