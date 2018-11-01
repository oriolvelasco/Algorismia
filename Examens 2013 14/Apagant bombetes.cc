#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;

int n, m;
VVB M;
int minim;

void canvia(int i, int j) {
    for (int k = i-1; k <= i+1; ++k) {
        for(int l = j-1; l <= j+1; ++l) {
            if(k >= 0 and k < n and l >= 0 and l < m) M[k][l] = not M[k][l];
        }
    }
}

bool correcte() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(M[i][j]) return false;
        }
    }
    return true;
}

void f(int i, int j, int compt) {
    if(correcte()) {
        minim = min(minim, compt);
        return;
    }
    if(compt > minim) return;
    if(i == n){
        return;
    }
    if(j == m) {
        if(i == 0 or (not M[i-1][j-2] and not M[i-1][j-1])) f(i+1, 0, compt);
        return;
    }
    if(i > 0 and j > 1 and M[i-1][j-2]) return;
    if(i == n-1 and j > 1 and M[i][j-2]) return;
    f(i, j+1, compt);
    canvia(i, j);
    f(i, j+1, compt+1);
    canvia(i, j);
    return;
}

int main() {
    while (cin >> n >> m) {
        M = VVB(n, VB(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if(c == '.') M[i][j] = false;
                else M[i][j] = true;
            }
        }
        minim = n*m+1;
        f(0, 0, 0);
        if(minim == n*m+1) cout << "no" << endl;
        else cout << minim << endl;
    }
}
