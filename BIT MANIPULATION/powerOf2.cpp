#include<bits/stdc++.h>
using namespace std;

bool powerOf2(int n) {
    if(n == 0) {
        return 0;
    }

    return !(n & (n-1));
}

int main() {
    int n;
    cin>>n;
    cout<<powerOf2(n);
    
    return 0;
}
