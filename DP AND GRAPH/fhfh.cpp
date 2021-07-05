#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<vector<int>> adj(N);
        for (int e = 1; e < N - 1; e++)
        {
            int u, v;
            cin >> u >> v;
            // u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        vector<int> st(N);
        vector<int> en(N);
        vector<int> par(N);
        int idx = 0;
        function<void(int, int)> dfs = [&](int cur, int prv)
        {
            par[cur] = prv;
            st[cur] = idx++;
            for (int nxt : adj[cur])
            {
                if (nxt == prv)
                    continue;
                dfs(nxt, cur);
            }
            en[cur] = idx;
        };
        dfs(0, 0);
        
        int Q;
        cin>>Q;
        while (Q--)
        {
            int K;
            cin >> K;
            int lo = 0;
            int hi = N;
            while (K--)
            {
                int v;
                cin >> v;
                v--;
                v = par[v];
                lo = max(lo, st[v]);
                hi = min(hi, en[v]);
            }
            cout << ((lo < hi) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}