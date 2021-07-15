#include<bits/stdc++.h>
using namespace std;

void towerMove(int n, char src, char dest, char helper) {
    if(n == 0) {
        return;
    }
    towerMove(n-1, src, helper, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerMove(n-1, helper, dest, src);
}

int main() {
    
    towerMove(3, 'A', 'B', 'C');
    
    return 0;
}