#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int N;
        cin>>N;
        long long int arr[N];

        long long int minVal = 1e9+2;
        long long int maxVal = -1;
        int maxIdx = -1;

        for(int i=0; i<N; i++) {
            cin>>arr[i];
            if( arr[i] > maxVal) {
                maxIdx = i;
                maxVal = max(maxVal, arr[i]);
            }
            minVal = min(minVal, arr[i]);
        }
        
        // for(int i=0; i<N; i++) {
        //     if( arr[i] > maxVal) {
        //         maxIdx = i;
        //         maxVal = max(maxVal, arr[i]);
        //     }
        //     minVal = min(minVal, arr[i]);
        // }
        for(int i=0; i<N; i++) {
            if(arr[i]%minVal != 0) {
                arr[i] == minVal;
                break;
            }
            else {
                arr[maxIdx] = minVal;
            }
        }
        
        int count = 0;
        for(int i=0; i<N; i++) {
            int currcy = arr[i]/minVal;
            count += currcy;
        }
        cout<<count<<endl;
    }
    return 0;
}
