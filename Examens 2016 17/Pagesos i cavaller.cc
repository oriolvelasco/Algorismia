#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Posicio{
    int fil, col;
};

void insereix (queue<Posicio>& q, vector<vector<int> >& dist, int i, int j, bool& trobat, int d, Posicio& farmer) {
    if (dist[i][j] == -2) {
        dist[i][j] = d;
        trobat = true;
        farmer.fil = i;
        farmer.col = j;
    }
    if (dist[i][j] == -1) {
        dist[i][j] = d;
        Posicio p;
        p.fil = i;
        p.col = j;
        q.push(p);
    }
}

void BFS (queue<Posicio>& q, vector<vector<int> >& dist, bool& trobat, Posicio& farmer) {
    if (q.empty() or trobat) return;
    Posicio p = q.front();
    q.pop();
    insereix(q, dist, p.fil-1, p.col, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil-1, p.col+1, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil, p.col+1, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil+1, p.col+1, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil+1, p.col, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil+1, p.col-1, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil, p.col-1, trobat, dist[p.fil][p.col]+1, farmer);
    insereix(q, dist, p.fil-1, p.col-1, trobat, dist[p.fil][p.col]+1, farmer);
    BFS (q, dist, trobat, farmer);
    return;
}

int main() {
    int n, m;
    while (cin >> n >> m)   {
        vector<vector<int> > dist(n, vector<int> (m, -1));
        int fila, columna;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if (c == 'X') dist[i][j] = -3;
                if (c == 'F') dist[i][j] = -2;
                if (c == 'K') {
                    fila = i;
                    columna = j;
                }
            }
        }
        bool trobat = false;
        Posicio farmer;
        queue<Posicio> q;
        insereix(q, dist, fila, columna, trobat, 1, farmer);
        BFS(q, dist, trobat, farmer);
        if (not trobat) cout << 0 << endl;
        else {
            int d = dist[farmer.fil][farmer.col];
            cout << d;
            vector <Posicio> v(d);
            v[d-1] = farmer;
            int i = farmer.fil;
            int j = farmer.col;
            for (int k = d-1; k > 0; --k) {
                if (dist[i-1][j-1] == k) {
                    --i;
                    --j;
                }
                else if (dist[i-1][j] == k) {
                    --i;
                }
                else if (dist[i-1][j+1] == k) {
                    --i;
                    ++j;
                }
                else if (dist[i][j+1] == k) {
                    ++j;
                }
                else if (dist[i+1][j+1] == k) {
                    ++i;
                    ++j;
                }
                else if (dist[i+1][j] == k) {
                    ++i;
                }
                else if (dist[i+1][j-1] == k) {
                    ++i;
                    --j;
                }
                else if (dist[i][j-1] == k) {
                    --j;
                }
                Posicio p;
                p.fil = i;
                p.col = j;
                v[k - 1] = p;
            }
            for (int k = 0; k < d; ++k) cout << "  " <<  v[k].fil << ' ' << v[k].col;
            cout << endl;
        }
    }
}
