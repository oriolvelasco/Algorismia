#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef queue<pair<int,int> > QP;

int n, m;
VVC M;

void visita(int i, int j, VVI& dist, QP& q, int d) {
    if(i < 0 or i >= n or j < 0 or j >= m or M[i][j] == '#') return;
    if(dist[i][j] != -1) return;
    q.push(make_pair(i, j));
    dist[i][j] = d+1;
    return;
}

void BFS(int i1, int j1, VVI& dist) {
    dist[i1][j1] = 0;
    QP q;
    q.push(make_pair(i1, j1));
    while(not q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        visita(i+1, j, dist, q, dist[i][j]);
        visita(i-1, j, dist, q, dist[i][j]);
        visita(i, j+1, dist, q, dist[i][j]);
        visita(i, j-1, dist, q, dist[i][j]);
    }
}

int main() {
    while (cin >> n >> m) {
        int iT = -1, jT = -1;
        M = VVC(n, VC(m));
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> M[i][j];
                if(M[i][j] == 'T') {
                    iT = i;
                    jT = j;
                }
            }
        }
        if(iT == -1) cout << "El telecos ha fugit." << endl;
        else {
            VVI dist1(n, VI(m, -1));
            BFS(0, 0, dist1);
            if(dist1[iT][jT] == -1) cout << "El telecos esta amagat." << endl;
            else {
                VVI dist2(n, VI(m, -1));
                BFS(iT, jT, dist2);
                VVI maxim(n, VI(m, -1));
                //maxim[i][j] val -1 si no hi ha cap cami de longitud minim que passi per (i,j)
                //i en cas contrari val el nombre de persones maxim que es poden trobar en un cami de longitud minima de (0,0) a (iT, jT) que passa per (i,j)
                priority_queue<pair<int, pair<int,int> > > pq;
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        if(dist1[i][j] + dist2[i][j] == dist1[iT][jT]) pq.push(make_pair(-dist1[i][j], make_pair(i,j)));
                    }
                }
                pq.pop();
                if(M[0][0] == 'P') maxim[0][0] = 1;
                else maxim[0][0] = 0;
                while (not pq.empty()) {
                    pair<int, pair<int,int> > aux = pq.top();
                    int d = -aux.first;
                    int i = aux.second.first;
                    int j = aux.second.second;
                    pq.pop();
                    maxim[i][j] = 0;
                    if(i > 0) maxim[i][j] = max(maxim[i][j], maxim[i-1][j]);
                    if(i < n-1) maxim[i][j] = max(maxim[i][j], maxim[i+1][j]);
                    if(j > 0) maxim[i][j] = max(maxim[i][j], maxim[i][j-1]);
                    if(j < m-1) maxim[i][j] = max(maxim[i][j], maxim[i][j+1]);
                    if(M[i][j] == 'P') ++maxim[i][j];
                }
                cout << dist1[iT][jT] << ' ' << maxim[iT][jT] << endl;
            }
        }
    }
}
