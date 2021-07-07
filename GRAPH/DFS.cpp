#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100;
vector<bool> vis(N);
vector<vector<int>> adj(N);

void dfs(int val) {
    // Preorder:
    int node = val;
    vis[node] = true;
    cout<<node<<" "; 

    vector<int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++) {
        if(*it && !vis[*it]) {
            dfs(*it);
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0; i<=n; i++) {
        vis[i] = 0;
    }

    int x, y;
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    return 0;
}
