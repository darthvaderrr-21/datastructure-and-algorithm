#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visi, vector<bool> &streak) {
    streak[src] = true;
    if(!visi[src]) {
        visi[src] = true;
        for(auto it: adj[src]) {
            if(streak[it]) {
                return true;
            }
            if(!visi[it] && isCycle(it, adj, visi, streak)) {
                return true;
            }
        }
    }
    streak[src] = false;
    return false;
}

bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
    vector<vector<int>> adj(N);
    int M = prerequisites.size();

    for(int i=0; i<M; i++) {
        int u = prerequisites[i].first;
        int v = prerequisites[i].second;
        adj[v].push_back(u);
    }

    vector<bool> visi(N, 0);
    vector<bool> streak(N, 0);
    bool cycle = false;

    for(int i=0; i<N; i++) {
        if(!visi[i] && isCycle(i, adj, visi, streak)) {
            cycle = true;
        }
    }

    if(cycle) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int N, M;
    cin>>N>>M;
    vector<pair<int, int> > prerequisites;
    for(int i=0; i<M; i++) {
        int u, v;
        cin>>u>>v;
        prerequisites.push_back({u, v});
    }

    cout<<isPossible(N, prerequisites);

    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/?track=amazon-graphs&batchId=192#

Input:Output

4 3
1 0
2 1
3 2
= 1

2 2
1 0
0 1
= 0

*/