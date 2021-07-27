#include <bits/stdc++.h>
using namespace std;

bool canReach(int arr[], int n) {
    int reach = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0 && reach == i) {
            if(reach < n-1) {
                return false;
            }
        }
        reach = max((i+arr[i]), reach);
    }

    if(reach >= n-1) {
        return true;
    }
    return false;
}

int main() {
    int n = 6;
    int arr[] = {1, 2, 0, 3, 0, 0};
    if(canReach(arr, n)) {
        cout<<"Reachable";
    } else {
        cout<<"Unreachable";
    }
    return 0;
}
