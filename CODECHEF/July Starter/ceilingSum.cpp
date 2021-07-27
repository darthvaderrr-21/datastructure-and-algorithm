#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int a, b;
        cin>>a>>b;
        int ans = INT_MIN;

        int s = min(a, b);
        int e = max(a, b);

        for(int x = s; x<=e; x++) {
            float t1f = ((b-x)/2.0);
            int t1i = ((b-x)/2);

            float t2f = ((x-a)/2.0);
            int t2i = ((x-a)/2);

            if(t1f-t1i >= 0.5) {
                t1i +=1;
            }
            if(t2f-t2i >= 0.5) {
                t2i +=1;
            }

            
            int temp = t1i + t2i;
            ans = max(ans, temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}
