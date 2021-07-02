#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<bool> vis(N);
vector<vector<int>> adj(N);
vector<int> comp;

int get_comp(int idx) {
    if(vis[idx]) {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for(auto it: adj[idx]) {
        if(!vis[it]) {
            ans += get_comp(it);
            vis[it] = true;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin>>n>>m;

    int x, y;
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            comp.push_back(get_comp(i));
        }
    }

    for(auto i: comp) {
        cout<<i<<" ";
    }
    cout<<endl;
    
    int nFriend = 0;
    for(auto i: comp) {
        nFriend += i * (n-i);
    }

    cout<<nFriend/2;

    return 0;
}
