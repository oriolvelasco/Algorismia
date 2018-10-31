#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Taula;
typedef vector<char> VecC;
typedef vector<VecC> TaulaC;

int n, m;
int i0, i1, j0, j1;
VecC Cami;
Taula M;
TaulaC T;

void escriu() {
   for (int i = 0; i < Cami.size(); ++i) cout << Cami[i];
   cout << T[i1][j1] << endl;
}

void f(int i, int j) {
    if(j < 0 or i < 0 or j >= m or i >= n) return;
    if(M[i][j] == -1) return;
    
    if(i == i1 and j == j1) return escriu();
 

    Cami.push_back(T[i][j]);
    M[i][j] = -1;
    f(i-1, j);
    f(i+1, j);
    f(i, j+1);
    f(i, j-1);
    M[i][j] = 0;
    Cami.pop_back();     

}

int main() {
    cin >> n >> m;
    M = Taula(n, Vec(m, 0));
    T = TaulaC(n, VecC(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> T[i][j];
    }
    
    cin >> i0 >> j0 >> i1 >> j1;

    
    f(i0, j0);
}
