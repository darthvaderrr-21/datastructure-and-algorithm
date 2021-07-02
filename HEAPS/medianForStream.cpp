#include<bits/stdc++.h>
#include<algorithm>
#include<stack>
using namespace std;

# define vi vector<int>
# define rep for(int i=0; i<n; i++)

priority_queue<int, vi> pqmax;
priority_queue<int, vi, greater<int>> pqmin;

void insert(int a) {
    if(pqmax.size() == pqmin.size()) {
        if(pqmax.size() == 0 && pqmin.size() == 0) {
            pqmax.push(a);
        } else if(a < pqmax.top()) {
            pqmax.push(a);
        } else {
            pqmin.push(a);
        }
    }
    else if(pqmax.size() > pqmin.size()) {
        if(a < pqmax.top()) {
            int temp = pqmax.top();
            pqmax.pop();
            pqmax.push(a);
            pqmin.push(temp);
        } else {
            pqmin.push(a);
        }
    }
    else {
        if(a < pqmax.top()) {
            pqmax.push(a);
        } else {
            int temp = pqmin.top();
            pqmin.pop();
            pqmin.push(a);
            pqmax.push(temp);
        }
    }
};

double median() {
    if(pqmax.size() == pqmin.size()) {
        return (pqmax.top() + pqmin.top())/2.0;
    } else if(pqmax.size() > pqmin.size()) {
        return pqmax.top();
    } else {
       return pqmin.top(); 
    }
}

signed main() {
    int a;
    cin>>a;
    insert(a);
    cout<<median()<<endl;

    cin>>a;
    insert(a);
    cout<<median()<<endl;

    cin>>a;
    insert(a);
    cout<<median()<<endl;

    cin>>a;
    insert(a);
    cout<<median()<<endl;

    return 0;
}
