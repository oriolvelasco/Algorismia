#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Roca {
    double x, y, r;
};

void insereix(queue<int>& q, vector<int>& distancia, vector<vector<bool> >& mat, int i, int dist) {
    if (distancia[i] == -1) {
        q.push(i);
        distancia[i] = dist;
    }
}

int cerca(queue<int>& q, vector<int>& distancia, vector<vector<bool> >& mat) {
    if (q.empty()) return 0;
    int pos = q.front();
    if (pos == mat.size() - 1) return distancia[pos];
    q.pop();
    for (int i = 0; i < mat.size(); ++i) {
        if (mat[pos][i]) insereix(q, distancia, mat, i, distancia[pos] + 1);
    }
    return cerca(q, distancia, mat);
}

int main() {
    int n;
    double d;
    while (cin >> n >> d) {
        vector<Roca> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y >> v[i].r;
        vector<vector<bool> > mat(n, vector<bool> (n, false));
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
            if(sqrt((v[j].x - v[i].x)*(v[j].x - v[i].x) + (v[j].y - v[i].y)*(v[j].y - v[i].y)) - (v[i].r + v[j].r) <= d) mat[i][j] = mat[j][i] = true;
        }
        vector<int> distancia(n, -1);
        queue<int> q;
        insereix(q, distancia, mat, 0, 0);
        int dist = cerca(q, distancia, mat);
        if (dist == 0) cout << "Xof!" << endl;
        else cout << dist << endl;
    }
}
