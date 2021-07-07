#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100;
vector<bool> vis(N);
vector<vector<int>> adj(N);

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        vis[i] = 0;
    }

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        vector<int> :: iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); it++) {
            if(!vis[*it]) {
                vis[*it] = true;
                q.push(*it);
            }
        }
    }

    return 0;
}
