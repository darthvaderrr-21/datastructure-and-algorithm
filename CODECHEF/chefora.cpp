#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 1e5+2;
int dp[N];

int chefora(int n) {
    if(n >=1 && n<=9) {
        return n;
    }
    if(n == 10) {
        return 11;
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n-1] = chefora(n-1);

    int digit = 0;
    int num = dp[n-1];
    
    while(num > 0) {
        num = num/10;
        digit++;
    }

    int ones = 0;
    while(digit--) {
        ones = ones*10+1;
    }

    int nines = 9*ones;
    
    if(dp[n-1] % nines == 0) {
        dp[n] = dp[n-1] + 2;
    } else if(dp[n-1] % ones == 0) {
        dp[n] = dp[n-1] * 9;
    } else {
        int num2 = (ones-11)/10;
        dp[n] = dp[n-1] +num2;
    }
    return dp[n];
}

int main() {
    for(int i=1; i<=N; i++) {
        dp[i] = -1;
    }
    dp[10] = 11;

    int n;
    cin>>n;

    cout<<chefora(n);

    return 0;
}




// =========================================
