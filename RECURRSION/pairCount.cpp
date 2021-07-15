#include<bits/stdc++.h>
using namespace std;

int countPair(int n) {
    if(n == 0 || n == 1 || n == 2) {
        return n;
    }

    return countPair(n-1) + (countPair(n-2) * (n-1));
}

int main() {
    int n;
    cin>>n;
    cout<<countPair(n);
    return 0;
}
