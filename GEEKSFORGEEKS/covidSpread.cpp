#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m) {
    return (x>=0 && x<n && y>=0 && y<m);
}

int helpaterp(vector<vector<int>> hospital) {
    int n = hospital.size();
    int m = hospital[0].size();

    int dx[] = {1,-1, 0, 0};
    int dy[] = {0, 0, 1,-1};

    vector<vector<bool>> visi(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visi[i][j] && hospital[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    q.push({-1, -1});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if(x != -1 && y != -1 && !visi[x][y]) {
            visi[x][y] = true;
            for(int k=0; k<4; k++) {
                if((isSafe(x+dx[k], y+dy[k], n, m)) && (hospital[x+dx[k]][y+dy[k]] == 1)) {
                    hospital[x+dx[k]][y+dy[k]] = 2;
                    q.push({x+dx[k], y+dy[k]});
                }
            }
        } else{
            ans++;
            if(!q.empty()) {
                q.push({-1, -1});
            };
        }
    }
    ans--;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(hospital[i][j] == 1) {
                ans = -1;
                break;
            }
        }
    }
    return ans;
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> hospital(n, vector<int>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>hospital[i][j];
        }
    }

    cout<<helpaterp(hospital);

    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1/#

Input:Output

3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
= 2

3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
= -1
*/