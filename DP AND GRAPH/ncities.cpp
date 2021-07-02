#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 1e5+6;
vector<int> graph[N];
vector<pair<ll,vector<ll>>> pt;

void dfs(ll st,ll e,ll vis[],vector<ll> rs,ll w){
   rs.push_back(st);
   if(st == e){
       pt.push_back({w*(rs.size()-1),rs});
       return;
   }
   for(auto u : graph[st]){
       if(vis[u] == 0){
          vis[st] = 1;
          dfs(u,e,vis,rs,w);
          vis[st] = 0;
       }
   }
}

int main()
{
    ll n,m,t,c,u,v;
    cin>>n>>m>>t>>c;
    while(m--){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if(n == 1)
    cout<<0<<endl;
    else if(n == 2)
    cout<<t<<endl;
    else{
        vector<ll> rs;
        ll w = c;
        ll vis[n+1] = {0};
        dfs(1,n,vis,rs,w);
        if(pt.size() == 0)
        cout<<-1<<endl;
        else{
        sort(pt.begin(),pt.end());
        for(auto it: pt) {
            cout<<it.first<<" "<<endl;
        }
        ll tm = 0;
        ll nt = 0;
        for(int i=1;i<pt[0].second.size();i++){
            tm += c + (nt-tm);
            while(nt < tm)
            nt += t;
        }
        // cout<<tm<<endl;
        }//else
    }
    return 0;
}