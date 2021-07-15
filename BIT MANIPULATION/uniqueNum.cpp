#include <bits/stdc++.h>
using namespace std;

// int findUnique(int arr[], int n) {
//     int xorsum =0;
//     for(int i=0; i<n; i++) {
//         xorsum = xorsum ^ arr[i];
//     }
//     return xorsum;
// }

void findUnique(int arr[], int n) {
    int xorsum = 0;
    for(int i=0; i<n; i++) {
        xorsum = xorsum ^ arr[i];
    }

    int pos =0;
    bool flag = true;
    while(flag && xorsum) {
        flag = !(xorsum & (1<<pos));
        pos++;
    }
    pos--;

    int xorsum2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] & (1<<pos)) {
            xorsum2 = xorsum2 ^ arr[i];
        }
    }

    int n1 = xorsum ^ xorsum2;
    int n2 = xorsum2;
    cout<<n1<<" "<<n2<<endl;

}

int main() {
    int arr[] = {1, 3, 1, 2, 5, 1, 2, 3};
    findUnique(arr, 8);
    return 0;
}
