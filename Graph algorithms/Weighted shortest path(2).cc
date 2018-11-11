#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef vector<pair<int, int> > VP;
typedef vector<VP> VVP;
typedef priority_queue<pair<int, pair<int,int> > > PQ;
typedef vector<int> VI;

int n, m;
VVP G;
VI dist;
VI pare;
int x, y;

void Dijkstra(PQ& p) {
    while(not p.empty()) {
        int d = -p.top().first;
        int node = p.top().second.first;
        int father = p.top().second.second;
        p.pop();
        if(dist[node] == -1) {
            dist[node] = d;
            pare[node] = father;
            for(int j = 0; j < G[node].size(); ++j) p.push(make_pair(-d-G[node][j].second, make_pair(G[node][j].first, node)));
            if(node == y) return;
        }
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
        pare = VI(n, -1);
        PQ p;
        p.push(make_pair(0,make_pair(x,x)));
        Dijkstra(p);
        if(dist[y] == -1) cout << "no path from " << x << " to " << y << endl;
        else {
            stack<int> S;
            int z = y;
            while(z != x) {
                S.push(z);
                z = pare[z];
            }
            cout << x;
            while(not S.empty()) {
                cout << ' ' << S.top();
                S.pop();
            }
            cout << endl;
        }
    }
}
