#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &vis, int parent) {
    vis[src] = true;
    for(auto it: adj[src]) {
        if(src != parent) {
            if(vis[it]) {
                return true;
            } else {
                if(!vis[it] && isCycle(it, adj, vis, src)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<bool> vis(n,0);
    vector<vector<int>> adj(n);
    bool cycle = false;

    int x, y;
    for (int i=0; i<m; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<n; i++) {
        if(!vis[i] && isCycle(i, adj, vis, -1)) {
            cycle = true;
            break;
        }
    }

    if(cycle) {
        cout<<"Cyclic"<<endl;
    } else {
        cout<<"Acyclic"<<endl;
    }
    return 0;
}
