#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef pair<int, int> P;
typedef vector<P> VP;
typedef vector<VP> VVP;

const int INF = 2e9;

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVP G(n);
        for (int i = 0; i < m; ++i) {
            int x, y, l;
            cin >> x >> y >> l;
            G[x].push_back(make_pair(y,l));
            G[y].push_back(make_pair(x,l));
        }
        int p;
        cin >> p;
        VI numstops(n, INF);
        VI dist(n, INF);
        numstops[p] = 0;
        dist[p] = 0;
        queue<int> Q;
        Q.push(p);
        while (not Q.empty()) {
            int x = Q.front();
            Q.pop();
            int mida = G[x].size();
            int nx = numstops[x];
            int lx = dist[x];
            for (int j = 0; j < mida; ++j) {
                int y = G[x][j].first;
                int l = G[x][j].second;
                if (numstops[y] == nx + 1 and l + lx < dist[y]) 
                    dist[y] = l + lx;
                if (numstops[y] == INF) {
                    numstops[y] = nx + 1;
                    dist[y] = l + lx;
                    Q.push(y);
                } 
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            if (numstops[i] == INF) cout << "no" << endl;
            else cout << numstops[i] << ' ' << dist[i] << endl;
        }
        cout << "----------" << endl;
    }
}
