#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];
int wt[N];
int val[N];

int maxKnapsack(int n, int w) {
    if(w <= 0) {
        return 0;
    }
    if(n <= 0) {
        return 0;
    }

    if(dp[n][w] != -1) {
        return dp[n][w];
    }

    if(wt[n-1] > w) {
        dp[n-1][w] = maxKnapsack(n-1, w);
    }

    dp[n][w] = max(maxKnapsack(n-1, w), maxKnapsack(n-1, w-wt[n-1]) + val[n-1]);
    return dp[n][w];
}

int main() {

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dp[i][j] = -1;
        }
    }
    
    int n;
    int wt[n];
    int val[n];
    for(int i=0; i<n; i++) {
        cin>>wt[i];
    }
    for(int i=0; i<n; i++) {
        cin>>val[i];
    }

    int wtKnap;
    cin>>wtKnap;

    cout<<maxKnapsack(n, wtKnap);
    return 0;
}
