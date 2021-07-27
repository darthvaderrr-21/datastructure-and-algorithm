#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int a, b;
        cin>>a>>b;
        int sum = a+b;

        if((a+b)<3) {
            cout<<"1"<<endl;
        }
        if(3<=(a+b) && (a+b)<=10) {
            cout<<"2"<<endl;
        }
        if(11<=(a+b) && (a+b)<=60) {
            cout<<"3"<<endl;
        }
        if(60<(a+b)) {
            cout<<"4"<<endl;
        }
    }
    return 0;
}
