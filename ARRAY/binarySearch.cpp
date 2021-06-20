#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;

    while(start<=end) {
    int mid = (start+end)/2;

        if(arr[mid] == key) {
            return mid+1;
        } else if(arr[mid] >> key) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return -1;
}

int main() {
    int n = 5;
    int arr[n] = {1, 7, 8, 23, 54};
    cout<<binarySearch(arr, n, 7);

    return 0;
}
