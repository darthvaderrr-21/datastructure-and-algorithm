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
        int minIdx = -1;

        for(int i=0; i<N; i++) {
            cin>>arr[i];
            if( arr[i] > maxVal) {
                maxIdx = i;
                maxVal = max(maxVal, arr[i]);
            }
            if( arr[i] < minVal) {
                minIdx = i;
                minVal = min(minVal, arr[i]);
            }  
        }
        // cout<<"max"<<maxVal<<" "<<"min"<<minVal<<endl;

        int minIdxNum = 0;
        int minSec = 1e9+2;
        for(int i=0; i<N; i++) {
            if(arr[i] > minVal && arr[i] < minSec) {
                minSec = arr[i];
            }
            if(arr[i] == minVal) {
                minIdxNum += 1;
            }
        }
        // cout<<"minIdxNum"<<minIdxNum<<"minSec"<<minSec<<endl;

        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        // if(minIdxNum != 1 && minSec > minVal) {
        //     arr[maxIdx] = minVal;

        //     for(int i=0; i<N; i++) {
        //         count1 +=  arr[i]/minVal;
        //     }
        // }
            arr[maxIdx] = minVal;

            for(int i=0; i<N; i++) {
                count1 +=  arr[i]/minVal;
            }       

        if(minIdxNum == 1) {
            bool flag = true;
            for(int i=0; i<N; i++) {
                if(i != minIdx) {
                    if(arr[i] % minSec != 0) {
                        flag = false;
                    }
                }
            }
            // cout<<"flag"<<flag;
            if(flag == true) {

                // for(int i=0; i<N; i++) {
                //     count1 += arr[i]/minVal;
                // }
                // cout<<"count1 "<<count1<<endl;

                // minSec:  
                arr[minIdx] = minSec;
                for(int i=0; i<N; i++) {;
                    count1 += arr[i]/minSec;
                }
                // cout<<"count1 "<<count1<<endl;
                // count = min(count1, count2);
                
            } else {
                arr[maxIdx] = minVal;
                for(int i=0; i<N; i++) {
                    count2 += arr[i]/minVal;
                }
            }
        }
        // arr[maxIdx] = minVal;
        int count;
        cout<<min(count1, min(count2,count3));

    }
    return 0;
}
