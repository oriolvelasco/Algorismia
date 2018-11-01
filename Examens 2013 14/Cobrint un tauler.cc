#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int n, m;
VVI tauler;

void f(int i, int j, int compt) {
    if(i == n) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cout << char(tauler[j][k]+'a');
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if(j == m) {
        f(i+1,0, compt);
        return;
    }
    if(tauler[i][j] != -1) {
        f(i,j+1, compt);
        return;
    }
    tauler[i][j] = compt;
    if(j < m-1 and tauler[i][j+1] == -1) {
        tauler[i][j+1] = compt;
        f(i, j+2, compt+1);
        tauler[i][j+1] = -1;
    }
    if(i < n-1 and tauler[i+1][j] == -1) {
        tauler[i+1][j] = compt;
        f(i, j+1, compt+1);
        tauler[i+1][j] = -1;
    }
    tauler[i][j] = -1;
}

int main() {
    while (cin >> n >> m) {
        tauler = VVI(n, VI(m, -1));
        f(0,0, 0);
    }
}
