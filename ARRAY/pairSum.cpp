#include<bits/stdc++.h>
using namespace std;

void pairSum(int arr[], int n, int sum) {
    int start = 0;
    int end = n-1;

    while(start < end) {
        int total = arr[start] + arr[end];
        if(total == sum) {
            cout<<start+1<<" "<<end+1<<endl;
            return;
        } else if(total < sum) {
            start++;
        } else {
            end--;
        }
    }
}

int main() {
    // Sorted Array:
    int arr[] = {2,4,7,11,14,16,20,21};
    pairSum(arr, 8, 31);

    return 0;
}
