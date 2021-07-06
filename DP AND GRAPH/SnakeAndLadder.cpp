#include<bits/stdc++.h>
using namespace std;

int movesCount(map<int, int> lad, map<int, int> snak) {
    int moves = 0;
    vector<int> visi(101, 0);
    visi[1] = true;
    bool found = false;

    queue<int> q;
    q.push(1);

    while(!q.empty() && !found) {
        int size = q.size();
        while(size--) {
            int pos = q.front();
            q.pop();
            for(int die=1; die<=6; die++) {
                if(pos+die == 100) {
                    found = true;
                    break;
                }

                if(pos+die < 100 && lad[pos+die] && !visi[lad[pos+die]]) {
                    visi[lad[pos+die]] = true;
                    if(lad[pos+die] == 100) {
                        found = true;
                        break;
                    }
                    q.push(lad[pos+die]);
                }

                else if(pos+die < 100 && snak[pos+die] && !visi[snak[pos+die]]) {
                    visi[snak[pos+die]] = true;
                    if(snak[pos+die] == 100) {
                        found = true;
                        break;
                    }
                    q.push(snak[pos+die]);
                }
                else if(pos+die < 100 && !visi[pos+die] && !lad[pos+die] && !snak[pos+die]) {
                    visi[pos+die] = true;
                    q.push(pos+die);
                }
            }
        }
        moves++;
    }
    if(found) {
        return moves;
    } else {
        return -1;
    }
}

int main() {
    int ladder, snake;
    cin>>ladder>>snake;

    map<int, int> lad;
    map<int, int> snak;

    for(int i=0; i<ladder; i++) {
        int u, v;
        cin>>u>>v;
        lad[u] = v;
    }
    for(int i=0; i<snake; i++) {
        int u, v;
        cin>>u>>v;
        snak[u] = v;
    }

    cout<<movesCount(lad, snak);

    return 0;
}
