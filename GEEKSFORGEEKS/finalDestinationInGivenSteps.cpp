#include <bits/stdc++.h>
using namespace std;

int canReach(long long a, long long b, long long x) {
    // code here
    long long step = abs(a)+abs(b);
    if(x < step) {
        return 0;
    }
    double num1 = (x-step)/2.0;
    long long num2 = (x-step)/2;
    if((num1 - num2) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    long long a, b, x;
    cin>>a>>b>>x;

    cout<<canReach(a, b, x);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/final-destination4628/1
*/
