#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recordBreakerDay(int arr[], int n) {
    int max_visitor = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        if((arr[i] > max_visitor) && arr[i] > arr[i+1]) {
            count += 1;
        };
        max_visitor = max(max_visitor, arr[i]);
    };
    return count;
};

int main() {
    int n=10;
    int arr[n] = {0,2,1,3,7,3,6,8,7,12};
    cout<<recordBreakerDay(arr, n);

    return 0;
}
