#include<bits/stdc++.h>
using namespace std;

int minDistBFS(vector<int> adj[], int u, int v, int n) {
    vector<bool> visited(n, 0);
    vector<int> distance(n, 0);

    queue<int> q;
    q.push(u);
    visited[u] = true;
    distance[u] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]) {
            if(visited[it]) {
                continue;
            }
            distance[it] = distance[node] + 1;
            q.push(it);
            visited[it] = true;
        }
    }
    return distance[v];
}

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int N, Q;
        cin>>N>>Q;

        vector<int> adj[N+1];
        for(int i=1; i<N; i++) {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<Q; i++) {
            int count = 0;
            int k, d;
            cin>>k>>d;
            int arr[k];
            for(int i=0; i<k; i++) {
                cin>>arr[i];
            }

            // int pairCollec = 1e9;
            vector<vector<int>> collec;
            for(int i=0; i<k-1; i++) {
                for(int j=i+1; j<k; j++) {
                    collec.push_back({arr[i], arr[j]});
                    // int dist = minDistBFS(adj, arr[i], arr[j], N);
                    //     if(dist == d) {
                    //         count +=1;
                    //     }
                }
            }
            for(auto it: collec) {
                int dist = minDistBFS(adj, it[0], it[1], N);
                if(dist == d) {
                    count +=1;
                }
            }
            
            cout<<count<<endl;
        }
    } 
    return 0;
}
