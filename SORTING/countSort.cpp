#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void countSort(int arr[], int n) {
    int mx = arr[0];
    for(int i=1; i<n; i++) {
        mx = max(mx, arr[i]);
    };

    int count[mx+1] = {0};
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }

    for(int i=1; i<mx; i++) {
        count[i] += count[i-1];
    }

    int output[n];

    for(int i=n-1; i>=0; i--) {
        output[--count[arr[i]]] = arr[i];
    }
    
    printArray(output, n);
};

int main() {
    int arr[] = {1, 5, 4, 3, 8, 9, 10, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);
    // printArray(arr, n);

    return 0;
}
