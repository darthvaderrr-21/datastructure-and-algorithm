#include <bits/stdc++.h>
using namespace std;

int isCircle(int N, vector<string> A) {
    // code here
    string s1 = "";
    string s2 = "";   
    for(int i=0; i<N; i++) {
        string temp = A[i];
        int n = temp.size() - 1;
        s1 = s1 + temp[0];
        s2 = s2 + temp[n];
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    

    for(int i=0; i<s1.size(); i++) {
        if(s1 != s2) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    cin>>n;
    vector<string> A(n);
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }
    cout<<isCircle(n, A);

    return 0;
}
