#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
};

void selectionSort(int arr[], int n) {

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr, n);
};


void bubbleSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printArray(arr, n);
};

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    printArray(arr, n);
};

int main() {
    int n=5;
    int arr[5] = {1, 5, 8, 3, 4};
    insertionSort(arr, n);
    
    return 0;
}
