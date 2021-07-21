#include <bits/stdc++.h>
using namespace std;

int minCntFoun(int arr[], int n) {
    int min = 0;
    int max = 0;
    int index = 0;
    int ans = 0;

    while(max < n-1) {
        for(int i= index; i<n; i++) {
            if((i - arr[i] <= min) && (i+arr[i] > max)) {
                max = i+arr[i];
                index = i;
            }
        }
        if(min == max) {
            return -1;
        }
        ans++;      
        min = max;
    }
    return ans;
}

int main()
{
    int a[] = {2, 1, 1, 2, 1} ;
    int N = sizeof(a) / sizeof(a[0]);
    cout << minCntFoun(a, N);
}