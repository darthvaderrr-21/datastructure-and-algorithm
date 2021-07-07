#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int coinChange(int arr[], int n, int v) {
    if(v == 0) {
        return 1;
    }
    if(v < 0) {
        return 0;
    }
    if(n <= 0) {
        return 0;
    }

    if(dp[n][v] != -1) {
        return dp[n][v];
    }

    dp[n][v] = coinChange(arr, n, v-(arr[n-1])) + coinChange(arr, n-1, v);
    
    return dp[n][v];
}

int main() {
    int n, v;
    cin>>n>>v;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dp[i][j] = -1;
        }
    }

    cout<<coinChange(arr, n, v);
    return 0;
}

// Input:
// 3 6
// 1 2 3

// Output:
// 7
