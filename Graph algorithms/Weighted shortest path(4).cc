#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<pair<int, int> > VP;
typedef vector<VP> VVP;
typedef priority_queue<pair<int, pair<int,int> > > PQ;
typedef vector<int> VI;

int n, m;
VVP G;
VI dist, ways;
int x, y;

void Dijkstra(PQ& p) {
    while(not p.empty()) {
        int d = -p.top().first;
        int node = p.top().second.first;
        int father = p.top().second.second;
        p.pop();
        if(dist[node] == -1) {
            dist[node] = d;
            for(int j = 0; j < G[node].size(); ++j) p.push(make_pair(-d-G[node][j].second, make_pair(G[node][j].first, node)));
            if(dist[y] != -1 and d > dist[y]) return;
        }
        if (node != x and dist[node] == d) ways[node] += ways[father];
    }
}

int main() {
    while(cin >> n >> m) {
        G = VVP(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back(make_pair(v, c));
        }
        cin >> x >> y;
        dist = VI(n, -1);
        ways = VI(n, 0);
        ways[x] = 1;
        PQ p;
        p.push(make_pair(0,make_pair(x,x)));
        Dijkstra(p);
        if(dist[y] == -1) cout << "no path from " << x << " to " << y << endl;
        else cout << "cost " << dist[y] << ", " << ways[y] << " way(s)" << endl;
    }
}
