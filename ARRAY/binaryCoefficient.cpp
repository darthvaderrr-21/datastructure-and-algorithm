#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n<=1) {
        return 1;
    }
    return factorial(n-1) * n;
}

int binaryCoefficient(int n, int r) {
    return factorial(n)/(factorial(r) * factorial(n-r));
}

int main() {
    int n=5;
    int r=4;

    cout<<binaryCoefficient(n, r);
    return 0;
}
