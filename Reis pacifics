#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int n, r;
VVI tauler;

void f(int i, int j, int reis) {
    if(i == n and reis == r) {
        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < n; ++l) {
                if(tauler[k][l] == 2) cout << 'K';
                else cout << '.';
            }
            cout << endl;
        }
        cout << "----------" << endl;
        return;
    }
    if(i == n or reis > r) return;
    if(j == n)  {
        f(i+1, 0, reis);
        return;
    }
    if(tauler[i][j] != 0) {
        f(i, j+1, reis);
        return;
    }
    f(i, j+1, reis);
    tauler[i][j] = 2;
    int aux = 0;
    if(j < n-1) aux = tauler[i][j+1];
    if(i < n-1 and j < n-1) tauler[i+1][j+1] = 1;
    if(i < n-1) tauler[i+1][j] = 1;
    if(i < n-1 and j > 0) tauler[i+1][j-1] = 1;
    if(j < n-1) tauler[i][j+1] = 1;
    f(i, j+1, reis+1);
    tauler[i][j] = 0;
    if(i < n-1 and j < n-1) tauler[i+1][j+1] = 0;
    if(i < n-1) tauler[i+1][j] = 0;
    if(i < n-1 and j > 0) tauler[i+1][j-1] = 0;
    if(j < n-1) tauler[i][j+1] = aux;
}

int main() {
    while (cin >> n >> r) {
        tauler = VVI(n, VI(n, 0));
        f(0,0,0);
    }
}
