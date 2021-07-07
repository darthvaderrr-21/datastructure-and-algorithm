#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int mod = 1e7;
int dp[N];

int minSqur(int n) {
    if(n == 0 || n == 1 || n == 2 || n == 3) {
        return n;
    }

    if(dp[n] != mod) {
        return dp[n];
    }

    for(int i=1; i*i<=n; i++) {
        dp[n] = min(dp[n], 1+minSqur(n-i*i));
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<N; i++) {
        dp[i] = mod;
    }

    cout<<minSqur(n);
    return 0;
}
