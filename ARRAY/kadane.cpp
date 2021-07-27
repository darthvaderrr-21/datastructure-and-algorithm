#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n) {
    int mx = 0;
    int curr = 0;
    for(int i=0; i<n; i++) {
        if(curr+arr[i] > arr[i]) {
            curr = curr+arr[i];
            mx = max(mx , curr);
        } else {
            curr = arr[i];
            mx = max(mx, curr);
        }
    }
    return mx;
}

int circularKadane(int arr[], int n) {
    int nonWrapSum = 0;
    int wrapSum = 0;
    int mx =0;
    int curr = 0;
    int total = 0;

    nonWrapSum = kadane(arr, n);
    bool flag = true;

    for(int i=0; i<n; i++) {
        if(arr[i]>=0) {
            flag = false;
        }
        total += arr[i];
        arr[i] = -arr[i];
    }

    if(flag) {
        int maxx = INT_MIN;
        for(int i=0; i<n; i++) {
            maxx = max(maxx, -arr[i]);
        }
        return maxx;
    }

    wrapSum = total + kadane(arr, n);

    return max(wrapSum, nonWrapSum);
}

int main() {
    int n; 
    int arr[] = {-18, -12};
    cout<<circularKadane(arr, 2);

    return 0;
}

/*
Input = Output
8, -8, 9, -9, 10, -11, 12 = 22

-18, -12 = -12

-18 = -18

*/
