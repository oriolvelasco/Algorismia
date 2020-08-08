#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Punt {
    int fil, col;
};

void insereix(vector<vector<bool> >& M, queue<Punt>& q, int i, int j) {
    if (i >= 0 and i < M.size() and j >= 0 and j < M[0].size() and not M[i][j]) {
        M[i][j] = true;
        Punt p;
        p.fil = i;
        p.col = j;
        q.push(p);
    }
}

void pinta_alfil(vector<vector<bool> >& M, queue<Punt>& q, vector<vector<char> >& mat) {
    if (q.empty()) return;
    Punt p = q.front();
    q.pop();
    insereix(M, q, p.fil - 1, p.col - 1);
    insereix(M, q, p.fil + 1, p.col - 1);
    insereix(M, q, p.fil - 1, p.col + 1);
    insereix(M, q, p.fil + 1, p.col + 1);
    pinta_alfil(M, q, mat);
}

void pinta_cavall(vector<vector<bool> >& M, queue<Punt>& q, vector<vector<char> >& mat) {
    if (q.empty()) return;
    Punt p = q.front();
    q.pop();
    insereix(M, q, p.fil - 1, p.col - 2);
    insereix(M, q, p.fil - 1, p.col + 2);
    insereix(M, q, p.fil + 1, p.col - 2);
    insereix(M, q, p.fil + 1, p.col + 2);
    insereix(M, q, p.fil - 2, p.col - 1);
    insereix(M, q, p.fil - 2, p.col + 1);
    insereix(M, q, p.fil + 2, p.col - 1);
    insereix(M, q, p.fil + 2, p.col + 1);
    pinta_cavall(M, q, mat);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char> > mat(n, vector<char> (m));
        vector<vector<bool> > M(n, vector<bool> (m, false));
        vector<Punt> alfil;
        vector<Punt> cavall;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 'T') M[i][j] = true;
            if (mat[i][j] == 'B') {
                Punt p;
                p.fil = i;
                p.col = j;
                alfil.push_back(p);
            }
            if (mat[i][j] == 'K') {
                Punt p;
                p.fil = i;
                p.col = j;
                cavall.push_back(p);
            }
        }
        vector<vector<bool> > Malfil(n, vector<bool> (m));
        Malfil = M;
        for (int i = 0; i < alfil.size(); ++i) {
            queue<Punt> q;
            insereix(Malfil, q, alfil[i].fil, alfil[i].col);
            pinta_alfil(Malfil, q, mat);
        }
        vector<vector<bool> > Mcavall(n, vector<bool> (m));
        Mcavall = M;
        for (int i = 0; i < cavall.size(); ++i) {
            queue<Punt> q;
            insereix(Mcavall, q, cavall[i].fil, cavall[i].col);
            pinta_cavall(Mcavall, q, mat);
        }
        int monedes = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (mat[i][j] >= '0' and mat[i][j] <= '9' and (Malfil[i][j] or Mcavall[i][j])) monedes += mat[i][j] - '0';
        }
        cout << monedes << endl;
    }
}
