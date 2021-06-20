#include<iostream>
using namespace std;

void makeRec(int row, int col) {
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++){
            cout<<"*";
        }
        cout<<endl;
    }
};

void makeHollowRec(int row, int col) {
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++) {
            if( i==1 || i==row || j==1 || j==col ) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
};

void makePyramid(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
};

void makeSpacedPyramid(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            if( j <= (n-i) ) {
                cout<<" ";
            } else {
                cout<<"*";
            }
        }
        cout<<endl;
    }
};

void makeNumberTriangle(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<i;
        }
        cout<<endl;
    }
};

void floydTriangle(int n) {
    int count = 1;
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
};

void butterfly(int n) {
    for(int i=1; i<=n; i++) {
        int space = 2*n - 2*i;
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=space; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n; i>=1; i--) {
        int space = 2*n - 2*i;
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=space; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
};

void binaryPattern(int n) {
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            int m = i+j;
            if( m%2 == 0) {
                cout<<"1";
            } else {
                cout<<"0";
            }
        }
        cout<<endl;
    }
};

void palindromicPattern(int n) {
    for (int i=1; i<=n; i++) {
        int j;
        for(j=1; j<=(n-i); j++) {
            cout<<" ";
        }
        int k = i;
        for(; j<=n; j++) {
            cout<<k;
            k--;
        }
        k = 2;
        for(; j<=(n+i-1); j++) {
            cout<<k;
            k++;
        }
        cout<<endl;
    }
};

void starPattern(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=(n-i); j++) {
            cout<<" ";
        }
        int m = 2*i - 1;
        for(int j=1; j<=m; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=(n-i); j++) {
            cout<<" ";
        }
        int m = 2*i - 1;
        for(int j=1; j<=m; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
};

void zigzagPattern(int n) {
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=n; j++){
            int m = i+j;
            if( (m%4 == 0) || (i==2 && j%4==0) ){
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int row = 4, col = 5;
    int n = 5;
    zigzagPattern(9);
    
    return 0;
}
