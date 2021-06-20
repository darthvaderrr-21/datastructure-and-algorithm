#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxHistogram(vector<int> v) {
    int n = v.size();
    int maxArea = 0;
    stack<int> st;
    v.push_back(0);

    for(int i=0; i<n; i++) {
        while(!st.empty() && v[st.top()] > v[i]) {
            int t = st.top();
            int height = v[t];
            st.pop();

            if(st.empty()) {
                maxArea = max(maxArea, height * i);
            }
            else {
                int len = i-st.top()-1;
                maxArea = max(maxArea , height * len);
            }
        }
        st.push(i);
    }
    return maxArea;
};

int main() {
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout<<maxHistogram(v);

    return 0;
}