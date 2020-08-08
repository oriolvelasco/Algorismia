#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<pair<int,int> > > graf(n);
        vector<vector<pair<int,int> > > grafinv(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            graf[u].push_back(make_pair(v, c));
            grafinv[v].push_back(make_pair(u, c));
        }
        int x, y;
        cin >> x >> y;
        vector<bool> used(n, false);
        vector<int> dist(n, -1);
        priority_queue<pair<int, int> > p;
        p.push(make_pair(0, y));
        dist[y] = 0;
        bool acaba = false;
        while (not p.empty() and not acaba){
            pair <int, int> aux = p.top();
            int d = -aux.first;
            int u = aux.second;
            if(u == x) acaba = true;
            p.pop();
            if (not used[u]){
                used[u] = true;
                for (int i = 0; i < grafinv[u].size(); ++i) {
                    if (not used[grafinv[u][i].first]) {
                        if (dist[grafinv[u][i].first] == -1) dist[grafinv[u][i].first] = d+grafinv[u][i].second;
                        else dist[grafinv[u][i].first] = min(dist[grafinv[u][i].first], d+grafinv[u][i].second);
                        p.push(make_pair(-dist[grafinv[u][i].first], grafinv[u][i].first));
                    }
                }
            }
        }
        if (dist[x] == -1) cout << "no" << endl;
        else {
            cout << "cost " << dist[x] << ':';
            int node = x;
            bool fi = false;
            while (not fi) {
                cout << ' ' << node;
                if(node == y) fi = true;
                else {
                    int newnode = n;
                    for (int i = 0; i < graf[node].size(); ++i) {
                        if (dist[graf[node][i].first] != -1 and dist[node] == graf[node][i].second + dist[graf[node][i].first]) {
                            newnode = min(newnode, graf[node][i].first);
                        }
                    }
                    node = newnode;
                }
            }
            cout << endl;
        }
    }
}
