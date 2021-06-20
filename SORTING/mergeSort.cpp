#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int array[], int left[], int right[], int n1, int n2) {
    int i=0, j=0, k=0;

    while(i<n1 && j<n2) {
        if(left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while(j<n2) {
        array[k] = right[j];
        j++;
        k++;
    }
};

void mergeSort(int arr[], int n) {
    if(n<=1) {
        return;
    };

    int mid = n/2;
    int left[mid];
    int right[n-mid];

    for(int i=0; i<mid; i++) {
        left[i] = arr[i];
    }

    for(int i=0; i<(n-mid); i++) {
        right[i] = arr[mid+i];
    }

    mergeSort(left, mid);
    mergeSort(right, n-mid);

    merge(arr, left, right, mid, n-mid);

};

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

int main() {

    int arr[] = {1, 5, 4, 3, 54, 4, 543, 5, 643, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);
    printArray(arr, n);

    return 0;
}
