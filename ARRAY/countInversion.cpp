#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int merge(int array[], int left[], int right[], int n1, int n2) {
    int i=0, j=0, k=0;
    int count = 0;

    while(i<n1 && j<n2){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
            count += 1;
        }
        k++;
    }

    while(i<n1) {
        array[k] = left[i];
        i++;
        k++;
        count += 1;
    }

    return count;
};

int inv = 0;

int inversion(int arr[], int n) {
    if(n<=1) {
        return 0;
    }
      
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    
    inversion(left, mid);
    inversion(right, n-mid);

    inv += merge(arr, left, right, mid, n-mid);
    return inv;
};

int main() {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout<<inversion(arr, n);
    // printArray(arr, n);

    return 0; 
}