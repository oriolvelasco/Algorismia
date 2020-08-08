#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<pair<int,int> > VP;
typedef vector<VP> VVP;
typedef priority_queue<pair<pair<int, int>, int> > PQ;

int n, m, k;
VVP G;
PQ p;

int main() {
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; ++i) {
        cin >> n >> m;
        G = VVP(n);
        for (int j = 0; j < m; ++j) {
            int u, v, d;
            cin >> u >> v >> d;
            G[u].push_back(make_pair(v, d));
            G[v].push_back(make_pair(u, d));
        }
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int node;
            cin >> node;
            p.push(make_pair(make_pair(0,-node), node));
        }
        VP dist(n, make_pair(-1,-1));
        while(not p.empty()) {
            int d = -p.top().first.first;
            int bombers = -p.top().first.second;
            int node = p.top().second;
            p.pop();
            if(dist[node].first == -1) {
                dist[node].first = d;
                dist[node].second = bombers;
                for (int j = 0; j < G[node].size(); ++j)
                    p.push(make_pair(make_pair(-d-G[node][j].second, -bombers), G[node][j].first));
            }
        }
        int q;
        cin >> q;
        if(i != 0) cout << endl;
        cout << "Case #" << i+1 << endl;
        for (int j = 0; j < q; ++j) {
            int city;
            cin >> city;
            cout << "To get to " << city << ", distance " << dist[city].first << ", from city " << dist[city].second << "." << endl;
        }
    }
}
