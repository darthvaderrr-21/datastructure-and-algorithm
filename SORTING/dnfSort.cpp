#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
};

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
};

void dnfSort(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr, low, mid);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr, mid, high);
            high--;
        }
    }
    printArray(arr, n);
};

int main() {
    int arr[] = {1, 0, 0, 2, 1, 2, 2, 0, 1, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    dnfSort(arr, n);

    return 0;
}
