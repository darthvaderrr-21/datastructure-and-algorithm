#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        long long e, k;
        cin>>e>>k;
        long long ans = 0;
        while(e>0) {
            e = e/k;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
