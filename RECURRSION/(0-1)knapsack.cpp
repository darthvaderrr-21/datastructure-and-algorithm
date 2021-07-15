#include<bits/stdc++.h>
using namespace std;

int maxKnapsack(int n, int w, int wt[], int val[]) {
    if(w <= 0) {
        return 0;
    }
    if(n <= 0) {
        return 0;
    }
    if(wt[n-1] > w) {
        maxKnapsack(n-1, w, wt, val);
    }

    return max(maxKnapsack(n-1, w, wt, val), maxKnapsack(n-1, w-wt[n-1], wt, val) + val[n-1]);
}

int main() {
    int n;
    cin>>n;
    int val[n];
    int wt[n];
    for(int i=0; i<n; i++) {
        cin>>wt[i];
    }
    for(int i=0; i<n; i++) {
        cin>>val[i];
    }
    int knapWt;
    cin>>knapWt;

    cout<<maxKnapsack(n, knapWt, wt, val);

    return 0;
}
