#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m) {
    return (x>=0 && x<n && y>=0 && y<m);
}

int numIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    vector<vector<bool>> visi(n, vector<bool>(m, false));

    int dx[] = {1,-1, 0, 0, 1, -1, 1, -1};
    int dy[] = {0, 0, 1,-1, 1, 1, -1, -1};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visi[i][j] && grid[i][j] == 1) {
                ans++;
                visi[i][j] = true;

                queue<pair<int, int>> q;
                q.push({i, j});

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k=0; k<8; k++) {
                        if(isSafe(x+dx[k], y+dy[k], n, m) && (!visi[x+dx[k]][ y+dy[k]]) && (grid[x+dx[k]][ y+dy[k]] == 1)) {
                            visi[x+dx[k]][ y+dy[k]] = true;
                            q.push({x+dx[k], y+dy[k]});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
        }
    }

    cout<<numIslands(grid);

    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#

Input:
2 7
0 1 1 1 0 0 0
0 0 1 1 0 1 0
=2


4 2
0 1
1 0                    
1 1
1 0
=1

*/
