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

    for(int i=0; i<n; i++) {
        total += arr[i];
        arr[i] = -arr[i];
    }

    wrapSum = total + kadane(arr, n);

    return max(wrapSum, nonWrapSum);
}

int main() {
    int n;
    int arr[] = {4, -4, 6, -6, 10, -11, 12};
    cout<<circularKadane(arr, 7);

    return 0;
}
