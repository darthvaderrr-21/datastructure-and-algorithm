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
    int arr[] ={1,2,3,7,5};
    givenSum(arr, 5, 12);
    
    return 0;
}
