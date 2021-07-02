#include<bits/stdc++.h>
using namespace std;

// Cycle detection:

const int N = 1e5+6;
vector<bool> vis(N);
vector<vector<int>> adj(N);
vector<int> parent(N);
vector<int> sz(N);

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void makeSet(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int findSet(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void makeUnion(int v1, int v2) {
    int x = findSet(v1);
    int y = findSet(v2);
    if(x != y) {
        if(sz[x] < sz[y]) {
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<=n; i++) {
        makeSet(i);
    }

    for(int i=0; i<m; i++) {
        int x, y;
        cin>>x>>y;
        adj.push_back({x, y});
    }

    for(auto i: adj) {
        cout<<i[0]<<i[1]<<endl;
    }

    bool cycle = false;

    for(auto it: adj) {
        int a1 = it[0];
        int b1 = it[1];
        int a = findSet(a1);
        int b = findSet(b1);
        if(a == b) {
            cycle = true;
            // break;
        } else {
            makeUnion(a1, b1);
        }
    }

    if(cycle) {
        cout<<"Cyclic"<<endl;
    } else {
        cout<<"Acyclic"<<endl;
    }

    return 0;
}
