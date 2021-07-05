#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<vector<int>> Edges;
vector<int> parent(N);
vector<int> size(N);

void makeSet(int v) {
    parent[v] = v;
    size[v] = 1;
}

int findSet(int v) {
    if(parent[v] == v) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void makeUnion(int v1, int v2) {
    int x = findSet(v1);
    int y = findSet(v2);
    if(x != y) {
        if(size[y] > size[x]){
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<=n; i++) {
        makeSet(i);
    }
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        Edges.push_back({w, u, v});
    }
    sort(Edges.begin(), Edges.end());
    int cost = 0;
    // for(auto it: Edges) {
    //     int w = it[0];
    //     int u = it[1];
    //     int v = it[2];
    //     cout<<w<<" "<<u<<" "<<v<<endl;

    // }

    
    for(auto it: Edges) {
        int w = it[0];
        int u = it[1];
        int v = it[2];

        int x = findSet(u);
        int y = findSet(v);

        if(x == y) {
            continue;
        } else {
            cout<<u<<" "<<v<<endl;
            cost += w;
            makeUnion(u,v);
        }
    }
    cout<<cost;
    
    return 0;
}

// 8 9
// 1 2 5
// 2 3 6
// 4 3 2
// 1 4 9
// 3 5 5
// 5 6 10
// 6 7 7
// 7 8 1
// 8 5 1
