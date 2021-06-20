#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subarray(int arr[], int n, int sum) {
    int start = 0;
    int end = 0;
    int curr_sum = 0;
    while(end<n && start<=end) {
        if(curr_sum == sum) {
            cout<<start+1<<" "<<end+1<<endl;
            break;
        } else if(curr_sum < sum) {
            curr_sum = curr_sum + arr[end+1];
            end++;
        } else {
            curr_sum = curr_sum - arr[start];
            start++;
        }
    }
};

int main() {
    int n=5;
    int arr[n] = {1, 2, 4, 2, 5};
    int s=8;
    subarray(arr, n, s);

    return 0;
}