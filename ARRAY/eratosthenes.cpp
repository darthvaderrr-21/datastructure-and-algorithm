#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n) {
    int mark[100] = {0};
    for(int i=2; i<=n; i++) {
        if(!mark[i]) {
            for(int j = i*i; j<=n; j+=i) {
                mark[j] = 1;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(!mark[i]) {
            cout<<i<<" ";
        }
    }
}

int main() {
    int n;
    cin>>n;
    primeSieve(n);

    return 0;
}
