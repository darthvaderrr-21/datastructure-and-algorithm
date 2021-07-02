#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<int> parent(N);
vector<int> size(N);

void makeSet(int v) {
    parent[v] = v;
    size[v] = 1;
}

int findSet(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void makeUnion(int v1, int v2) {
    v1 = findSet(v1);
    v2 = findSet(v2);
    if(v1 != v2) {
        if(size[v1] < size[v2]) {
            swap(v1, v2);
        }
        parent[v2] = v1;
        size[v1] += size[v2];
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        makeSet(i);
    }

    int cost = 0;
    vector<vector<int>> edge(m);
    for(int i=0; i<m; i++) {
        int w, u, v;
        cin>>w>>u>>v;
        edge.push_back({w, u, v});
    }

    sort(edge.begin(),edge.end());

    for(auto it: edge) {
        int w = it[0];
        int u = it[1];
        int v = it[2];

        int x = findSet(u);
        int y = findSet(v);
        if(x == y) {
            continue;
        } else {
            makeUnion(x, y);
            cost += w;
        }
    }

    cout<<cost<<endl;
    
    return 0;
}

// 1 5 8
// 1 8 7
// 2 4 3
// 5 1 2
// 5 3 5
// 6 2 3
// 7 6 7
// 9 1 4
// 10 5 6