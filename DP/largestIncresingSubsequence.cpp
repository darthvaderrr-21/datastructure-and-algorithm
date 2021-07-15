#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

int lis(vector<int> v, int n) {
    if(n == 0) {
        return 1;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = 1;

    for(int i=0; i<n; i++) {
        if(v[n] > v[i]) {
            dp[n] = max(dp[n], 1+lis(v, i));
        }
    }
    return dp[n];
}

int main() {
    for(int i=0; i<N; i++) {
        dp[i] = -1;
    }
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    cout<<lis(v, n-1);

    // Tabulation:
    // int n;
    // cin>>n;
    // vector<int> v(n);
    // vector<int> dp(n+1, 1);

    // for(int i=0; i<n; i++) {
    //     cin>>v[i];
    // }

    // int ans = 1;

    // for(int i=1; i<n; i++) {
    //     for(int j=0; j<i; j++) {
    //         if(v[i] > v[j]) {
    //             dp[i] = max(dp[i], 1+dp[j]);
    //         }     
    //     }
    //     ans = max(ans, dp[i]);
    // }
    // cout<<ans;


    return 0;
}

