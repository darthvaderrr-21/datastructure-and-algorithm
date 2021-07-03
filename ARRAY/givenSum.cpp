#include<bits/stdc++.h>
using namespace std;

void givenSum(int arr[], int n, int sum) {
    int s=0;
    int e=0;
    int total = 0;
    while(e < n && s < n) {
        if(total < sum) {
            total += arr[e];
            e++;
        } else if(total > sum) {
            total -= arr[s];
            s++;
        } else {
            cout<<s+1<<" "<<e<<endl;
            return;
        }
    }
}

int main() {
    int arr[] ={1,2,3,8};
    givenSum(arr, 4, 5);
    
    return 0;
}
