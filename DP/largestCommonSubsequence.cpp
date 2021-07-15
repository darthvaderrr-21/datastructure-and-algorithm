#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int lcs(string s1, string s2, int n1, int n2) {

    if( n1 == 0 || n2 == 0) {
        return 0;
    }
    if(dp[n1][n2] != -1) {
        return dp[n1][n2];
    }
    if(s1[n1-1] == s2[n2-1]) {
        dp[n1][n2] = 1+lcs(s1, s2, n1-1, n2-1);
    } else {
        dp[n1][n2] = max(lcs(s1, s2, n1, n2-1), lcs(s1, s2, n1-1, n2));
    }
    return dp[n1][n2];
}

int main() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dp[i][i] = -1;
        }
    }
    string s1;
    string s2;
    cin>>s1>>s2;

    int n1 = s1.size();
    int n2 = s2.size();

    cout<<lcs(s1, s2, n1, n2);
    return 0;
}
