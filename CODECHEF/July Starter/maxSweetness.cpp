#include <bits/stdc++.h>
using namespace std;

// int const N = 1e3;
// int dp[N][N];

int maxSweet(int n, int d, vector<int> price, vector<int> sweetness, int t) {
    if(t <= 0) {
        return 0;
    }
    if(d <= 0) {
        return 0;
    }
    if(n <= 0) {
        return 0;
    }
    // if(dp[n][d] != -1) {
    //     return dp[n][d];
    // }
    if(price[n-1] > d) {
        return maxSweet(n-1, d, price, sweetness, t);  
    }
    
    return max(maxSweet(n-1, d, price, sweetness, t), maxSweet(n-1, d-price[n-1], price, sweetness, t-1)+sweetness[n-1]);
}

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        // for(int k=0; k<N; k++) {
        //     for(int l=0; l<N; l++) {
        //         dp[k][l] = -1;
        //     }
        // }

        long long int n,d;
        cin>>n>>d;
        vector<int> price(n);
        vector<int> sweetness(n);
        for(int j=0; j<n; j++) {
            cin>>price[j];
        }
        for(int j=0; j<n; j++) {
            cin>>sweetness[j];
        }
        cout<<maxSweet(n, d, price, sweetness, 2)<<endl;
    }
    return 0;
}
