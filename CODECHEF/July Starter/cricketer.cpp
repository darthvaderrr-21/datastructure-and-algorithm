#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int r1, w1, c1;
        int r2, w2, c2;
        cin>>r1>>w1>>c1>>r2>>w2>>c2;

        if(r1>r2 && w1>w2) {
            cout<<'A'<<endl;
        }
        else if(c1>c2 && w1>w2) {
            cout<<'A'<<endl;
        }
        else if(r1>r2 && c1>c2) {
            cout<<'A'<<endl;
        }

        else if(r1>r2 && w1==w2 && c1==c2) {
            cout<<'A'<<endl;
        }
        else if(r1==r2 && w1>w2 && c1==c2) {
            cout<<'A'<<endl;
        }
        else if(r1==r2 && w1==w2 && c1>c2) {
            cout<<'A'<<endl;
        }
        else {
            cout<<'B'<<endl;
        }
    }
    return 0;
}
