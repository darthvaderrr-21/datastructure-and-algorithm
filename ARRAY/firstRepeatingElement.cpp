#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

int firstRepeatingElement(int arr[], int n) {
    int m = 10;
    int idx[m];
    int min_idx = INT_MAX;


    for(int i=0; i<m; i++) {
        idx[i] = -1;
    };

    for(int i=0; i<n; i++) {
        if(idx[arr[i] == -1]) {
            idx[arr[i]] == i;
        } else {
            min_idx = min(min_idx, idx[arr[i]]);
        }
    }
    return min_idx+1;
};

int main() {
    int n=7;
    int arr[n] = {1, 5, 3, 4, 3, 5, 2};
    cout<<firstRepeatingElement(arr, n);
  
    return 0;
}