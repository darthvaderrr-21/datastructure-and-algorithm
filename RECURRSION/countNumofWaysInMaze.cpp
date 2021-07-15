#include<bits/stdc++.h>
using namespace std;

int countMazePath(int n, int i, int j) {
    if(i == n-1 && j == n-1) {
        return 1;
    }
    if(i > n-1 || j > n-1) {
        return 0;
    }

    return countMazePath(n, i+1, j) + countMazePath(n, i, j+1);
}

int main() {
    cout<<countMazePath(3, 0, 0);
    return 0;
}
