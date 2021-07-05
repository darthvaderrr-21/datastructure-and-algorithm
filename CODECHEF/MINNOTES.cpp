#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        long long int arr[N];

        long long int minVal = 1e9 + 2;
        long long int maxVal = -1;
        int maxIdx = -1;
        int minIdx = -1;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (arr[i] > maxVal) {
                maxIdx = i;
                maxVal = max(maxVal, arr[i]);
            }
            if (arr[i] < minVal) {
                minIdx = i;
                minVal = min(minVal, arr[i]);
            }
        }
        // cout<<maxVal<<" "<<minVal<<endl;

        int minIdxNum = 0;
        int minSec = 1e9 + 2;
        int minSecIdx = -1;
        for (int i = 0; i < N; i++) {
            if (arr[i] > minVal && arr[i] < minSec) {
                minSec = arr[i];
                minSecIdx = i;
            }
            if (arr[i] == minVal) {
                minIdxNum += 1;
            }
        }
// 
        int count1 = 0;
        int count2 = 0;

        bool divisible = true;
        int notDiviIdx = -1;
        int numb = 0;
        for(int i=0; i<N; i++) {
            if(arr[i] % minVal != 0) {
                numb+=1;
                notDiviIdx = i;
                divisible = false;
            }
        }

        if(divisible) {
        
        arr[maxIdx] = minVal;
        for (int i = 0; i < N; i++) {
            count1 += arr[i] / minVal;
            // cout<<count1<<" ";
        }

        arr[maxIdx] = maxVal;
        if (minIdxNum == 1) {
            bool flag = true;
            for (int i = 0; i < N; i++) {
                if (i != minIdx) {
                    if (arr[i] % minSec != 0) {
                        flag = false;
                    }
                }
            }

            if (flag == true) {
                // cout<<"##";
                arr[minIdx] = minSec;
                for (int i = 0; i < N; i++) {
                    count2 += arr[i] / minSec;
                };
            }
        }
        if(count2) {
            cout<<min(count1, count2)<<endl;
        } else {
            cout << count1 << endl;
        }
        } else{
            bool secBool = true;
            for(int i=0; i<N; i++) {
                if(!minIdx) {
                    if(arr[i] % minSec != 0) {
                        secBool = false;
                    }
                }
            }
            
            if(numb == 1) {
                arr[notDiviIdx] = minVal;
            }
            if(numb > 1 && numb < N-1) {
                arr[maxIdx] = 1;
                minVal = 1;
            }
            if(numb == N-1) {
                if(secBool) {
                    arr[minIdx] = minSec;
                    minVal = minSec;  
                } else {
                    arr[maxIdx] = 1;
                    minVal = 1;
                }
            }
            // cout<<numb<<notDiviIdx<<minVal;

            for (int i = 0; i < N; i++) {
                count1 += arr[i] / minVal;
            }
            cout<<count1;
        }


    }
    return 0;
}
