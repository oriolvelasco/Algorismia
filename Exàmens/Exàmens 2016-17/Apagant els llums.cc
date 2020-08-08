#include <iostream>
#include <vector>
using namespace std;

void backtracking(int i, vector<int>& v, vector<vector<int> >& M, int& compt){
    if (i == M.size()) {
        for (int j = 0; j < v.size(); ++j) if (v[j] != 0) return;
        ++compt;
        return;
    }
    
    backtracking(i+1, v, M, compt);
    
    for (int k = 0; k < M[i].size(); ++k) v[M[i][k]] = (v[M[i][k]]+1)%2;
    backtracking(i+1, v, M, compt);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int m;
        cin >> m;
        vector<vector<int> > M(m);
        for (int i = 0; i < m; ++i) {
            int f;
            cin >> f;
            int x;
            for (int j = 0; j < f; ++j) {
                cin >> x;
                M[i].push_back(x);
            }
        }
        int compt = 0;
        backtracking(0, v, M, compt);
        cout << compt << endl;
    }
}
