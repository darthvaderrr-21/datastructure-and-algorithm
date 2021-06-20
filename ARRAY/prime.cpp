#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool prime(int n) {
    bool flag = true;
    for(int i=2; i<sqrt(n); i++) {
        if(n%i == 0){
            flag = false;
        }
    }
    return flag;
}

int main() {
    int a = 10 , b = 20;

    for(int i=a; i<=b; i++) {
        if(prime(i)) {
            cout<<i<<endl;
        }
    }

    return 0;
}
