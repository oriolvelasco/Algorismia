#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Punt {
    int fil, col;
};

void insereix(vector<vector<int> >& M, queue<Punt>& q, int i, int j, int dist) {
    if (i >= 0 and i < M.size() and j >= 0 and j < M[0].size() and M[i][j] == 0) {
        M[i][j] = dist;
        Punt p;
        p.fil = i;
        p.col = j;
        q.push(p);
    }
}

bool arriba_tresor(vector<vector<int> >& M, queue<Punt>& q, vector<vector<char> >& mat, int& dist) {
    if (q.size() == 0) return false;
    Punt p = q.front();
    dist = M[p.fil][p.col];
    if (mat[p.fil][p.col] == 't') return true;
    q.pop();
    insereix(M, q, p.fil - 1, p.col, dist + 1);
    insereix(M, q, p.fil + 1, p.col, dist + 1);
    insereix(M, q, p.fil, p.col - 1, dist + 1);
    insereix(M, q, p.fil, p.col + 1, dist + 1);
    return arriba_tresor(M, q, mat, dist);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > mat(n, vector<char> (m));
    vector<vector<int> > M(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 'X') M[i][j] = -1;
    }
    queue<Punt> q;
    int f, c;
    cin >> f >> c;
    insereix(M, q, f - 1, c - 1, 0);
    int dist;
    if (arriba_tresor(M, q, mat, dist)) cout << "distancia minima: " << dist << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
}
