#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Array:


// Stack:
int trappingRainWater(vector<int> v) {
    int n = v.size();
    int ans = 0;
    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && v[st.top()] < v[i]) {
            int curr = v[st.top()];
            st.pop();
            if(st.empty()) {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(v[st.top()], v[i]) - curr) * diff;
        }
        st.push(i);
    }
    return ans;
};

int main() {
    vector<int> v = {1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trappingRainWater(v);

    return 0;
}