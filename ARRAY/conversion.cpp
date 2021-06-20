#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int decimalToBinary(int n) {
    int x = 1;
    int ans = 0;

    while(n>0) {
        int quotient = n%2;
        ans += (x*quotient);
        x *= 10;
        n /= 2;
    }
    return ans;
};

int binaryToDecimal(int n) {
    int x=1;
    int ans=0;
    
    while(n>0) {
        int lastdigit = n%10;
        ans += lastdigit*x;
        x *=2;
        n /= 10;
    }
    return ans;
};

int main() {
    int n = 101;
    cout<<binaryToDecimal(n);
    return 0;
}
