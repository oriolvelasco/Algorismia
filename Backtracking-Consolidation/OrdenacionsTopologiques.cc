#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Taula;

int n, m;
Vec V, posats, numRes;
Taula Restriccions;

void escriu() {
   cout << V[0];
   for (int i = 1; i < n; ++i) cout << " " << V[i];
    cout << endl;
}

void f(int p) {
    if(p == n) return escriu();

    for (int i = 0; i < n; ++i) {
        if(numRes[i] == 0) {          
            V[p] = i;
            numRes[i]--;
            for(int j = 0; j < Restriccions[i].size(); ++j) {
                numRes[Restriccions[i][j]]--;
            }
            f(p+1);
            numRes[i]++;
            for(int j = 0; j < Restriccions[i].size(); ++j) {
                numRes[Restriccions[i][j]]++;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    V = Vec(n);
    numRes = Vec(n, 0);
    Restriccions = Taula(n);

    int i, j;
    for (int k = 0; k < m; ++k) {
        cin >> i >> j;
        Restriccions[i].push_back(j);
        numRes[j]++;
    }
    
    f(0);
}
