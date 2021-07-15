#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n<=1) {
        return 1;
    }
    return factorial(n-1) * n;
};

void fibonacci(int n) {
    int t1=0;
    int t2=1;
    int nextterm= t1+t2;

    for(int i=1; i<=n; i++) {
        cout<<t1<<" ";
        t1 = t2;
        t2 = nextterm;
        nextterm = t1+t2;
    }
}

int main() {
    fibonacci(5);
    
    return 0;
}