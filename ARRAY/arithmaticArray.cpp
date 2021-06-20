#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arithmaticArray(int arr[], int n) {
    int difference = arr[1]-arr[0];
    int max_len = 2;
    int curr_len = 2;
    for(int i=2; i<n; i++) {
        if((arr[i]-arr[i-1]) == difference){
            curr_len +=1;
            max_len = max(max_len, curr_len);
        } else {
            curr_len = 2;
            difference = arr[i] - arr[i-1];
        }
    };
    return max_len;
};

int main() {
    int n=10;
    int arr[n] = {1,2,3,4,5,6,7,8,9,10};
    cout<<arithmaticArray(arr, n);

    return 0;
}
