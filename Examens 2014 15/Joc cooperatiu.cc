#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<pair<double, int> > VP;
typedef vector<VP> VVP;

int main() {
    cout.setf(ios::fixed);
    cout.precision(5);
    int n, m;
    while(cin >> n >> m) {
        VVP G(n);
        for(int i = 0; i < m; ++i) {
            int x, y;
            double p;
            cin >> x >> y >> p;
            G[x].push_back(make_pair(p, y));
        }
        priority_queue<pair<double, int> > q;
        vector<double> prob(n, 0);
        int x, y;
        cin >> x >> y;
        prob[x] = 1;
        q.push(make_pair(1, x));
        while(not q.empty()) {
            int node = q.top().second;
            double p = q.top().first;
            q.pop();
            if(prob[node] == p) {
                for(int j = 0; j < G[node].size(); ++j) {
                    int z = G[node][j].second;
                    double p2 = G[node][j].first;
                    if(prob[z] < p*p2) {
                        prob[z] = p*p2;
                        q.push(make_pair(prob[z], z));
                    }
                }
            }
        }
        if(prob[y] == 0) cout << "impossible" << endl;
        else cout << prob[y] << endl;
    }
}
