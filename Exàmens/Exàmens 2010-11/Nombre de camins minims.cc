#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int n, m;
VVI G, G2;
VI dist, numcam;

int calcula(int i) {
    if(numcam[i] != 0) return numcam[i];
    for(int j = 0; j < G2[i].size(); ++j) if(dist[i] == dist[G2[i][j]]+1) numcam[i] += calcula(G2[i][j]);
    return numcam[i];
}

int main() {
    while(cin >> n >> m) {
        G = VVI(n);
        G2 = VVI(n);
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G2[y].push_back(x);
        }
        dist = VI(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while(not q.empty()) {
            int i = q.front();
            q.pop();
            for(int j = 0; j < G[i].size(); ++j){
                if(dist[G[i][j]] == -1) {
                    dist[G[i][j]] = dist[i]+1;
                    q.push(G[i][j]);
                }
            }
        }
        numcam = VI(n, 0);
        numcam[0] = 1;
        for(int i = 0; i < n; ++i) {
            cout << i << ": " << dist[i];
            if(dist[i] != -1) cout << ' ' << calcula(i);
            cout << endl;
        }
        cout << endl;
    }
}
