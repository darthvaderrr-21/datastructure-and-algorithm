#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void maxSumk(vector<int> a, int k) {
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<k; i++) {
        while(!dq.empty() && dq.back()<a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);

    for(int i=k; i<a.size(); i++) {
        if(dq.front() == i-k) {
            dq.pop_front();
        }
        while(!dq.empty() && dq.back()<a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        ans.push_back(a[dq.front()]);
    }
    for(auto i : ans) {
        cout<<i<<" ";
    }
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    
    maxSumk(a, k);

    return 0;
}