#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int n, m;
VVI dist;
int dmin;
queue<pair<int, int> > q;

void visita(int i, int j, int d) {
    if(i >= 0 and i < n and j >= 0 and j < m and (dist[i][j] == -1 or dist[i][j] == -2)) {
        if(dist[i][j] == -2 and dmin == -1) dmin = d;
        dist[i][j] = d;
        q.push(make_pair(i, j));
    }
}

int main() {
    while(cin >> n >> m) {
        dist = VVI(n, VI(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if(c == 'X') dist[i][j] = -3;
                else if(c == 'p') dist[i][j] = -2;
                else dist[i][j] = -1;
            }
        }
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        dist[x][y] = 0;
        q.push(make_pair(x, y));
        dmin = -1;
        while(not q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            int d = dist[i][j]+1;
            q.pop();
            visita(i+1, j+2, d);
            visita(i+1, j-2, d);
            visita(i-1, j+2, d);
            visita(i-1, j-2, d);
            visita(i+2, j+1, d);
            visita(i+2, j-1, d);
            visita(i-2, j+1, d);
            visita(i-2, j-1, d);
        }
        if (dmin == -1) cout << "no" << endl;
        else cout << dmin << endl;
    }
}
