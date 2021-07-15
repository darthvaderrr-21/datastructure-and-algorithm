#include<bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2) {
    if(n1 == n2) {
        return n1;
    }
    while(n2) {
        int rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    }
    return n1;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    if(n2 > n1) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    cout<<gcd(n1, n2);

    return 0;
}
