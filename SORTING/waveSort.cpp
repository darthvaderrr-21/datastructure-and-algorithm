#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
};

void waveSort(int arr[], int n) {
    for(int i=1; i<n; i+=2) {
        if(arr[i] > arr[i-1]) {
            swap(arr, i, i-1);
        }
        if(arr[i] > arr[i+1] && i<=n-2) {
            swap(arr, i, i+1);
        }
    }
    printArray(arr, n);
};

int main() {
    int arr[] = {1, 5, 4, 3, 8, 9, 10, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    waveSort(arr, n);
    // printArray(arr, n);

    return 0;
}
