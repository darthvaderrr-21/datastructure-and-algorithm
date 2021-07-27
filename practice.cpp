#include <bits/stdc++.h>
using namespace std;

int maxNum1(int arr[], int n, int m) {
    int curr;
    int mx;

    queue<int> q;
    int count = 0;
    int i = 0;

    while(i < n) {
        if(count == m && arr[i] == 0) {
            break;
        }
        if(count < m || arr[i] == 1) {
            curr++;
        }
        if(arr[i] == 0 && count < m) {
            count++;
            q.push(i);
        }
        i++;
    }

    mx = curr;
    for(i; i<n; i++) {
        if(arr[i] == 1) {
            curr++;
        }
        else if(arr[i] == 0 && !q.empty()) {
            int idx = q.front();
            q.pop();
            q.push(i);
            curr = i-idx;
        } else {
            curr = 0;
        }
        mx = max(mx, curr);
    }

    return mx;
}

int main() {
    int n = 11;
    int m = 2;
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    cout<<maxNum1(arr, n, m);

    return 0;
}

//=======================================

/*
https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
*/

//=======================================
    // int n = 77;
    // int m = 60;
    // int arr[] = {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0};
    // cout<<maxNum1(arr, n, m);
//=======================================
    // int n, m;
    // cin>>n;

    // int arr[n];
    // for(int i=0; i<n; i++) {
    //     cin>>arr[i];
    // }
    // cin>>m;

    // cout<<maxNum1(arr, n, m);