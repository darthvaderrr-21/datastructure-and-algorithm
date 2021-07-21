#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

bool isCycle(int src,  vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &streak) {
    streak[src] = true;
    if(!vis[src]) {
        vis[src] = true;
        for(auto it: adj[src]) {
            if(streak[it]) {
                return true;
            }
            if(!vis[it] && isCycle(it, adj, vis, streak)) {
                return true;
            }
        }
    }
    streak[src] = false;
    return false;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<bool> streak(n, 0);
    vector<bool> vis(n, 0);
    vector<vector<int>> adj(n);

    int x, y;
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
    }

    bool cycle = false;
    for(int i=0; i<n; i++) {
        if(!vis[i] && isCycle(i, adj, vis, streak)) {
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
