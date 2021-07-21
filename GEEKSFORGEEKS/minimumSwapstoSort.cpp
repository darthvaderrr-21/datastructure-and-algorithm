#include <bits/stdc++.h>
using namespace std;

void swap(pair<int, int> &p1, pair<int, int> &p2) {
    pair<int, int> temp = p1;
    p1 = p2;
    p2 = temp;
}

int minSwaps(vector<int> nums) {
    int n = nums.size();
    vector<pair<int, int>> p(n);
    int ans = 0;
    for(int i=0; i<n; i++) {
        p[i].first = nums[i];
        p[i].second = i;
    }
    sort(p.begin(), p.end());

    for(int i=0; i<n; i++) {
        if(i == p[i].second) {
            continue;
        }
        swap(p[i], p[p[i].second]);
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<minSwaps(nums);
    return 0;
}
