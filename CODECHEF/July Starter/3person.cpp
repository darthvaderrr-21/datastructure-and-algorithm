#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int a, b;
        cin>>a>>b;
        int num =6 - (a+b);
        if(num < 0) {
            cout<<0<<endl;
        } else {
            float prob = num/6.0;
            prob = floorf(prob * 1000000) / 1000000;
            cout<<prob<<endl;
        }
    }
    return 0;
}
