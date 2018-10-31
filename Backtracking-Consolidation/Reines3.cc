#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int n;
Vec V, posats, Diag, Diag2;
bool trobat = false;

void escriu() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(V[i]==j) cout << "Q";
            else cout << ".";
        }
        cout << endl;
    }
}

void f(int p) {
    if(p == n) {
        trobat = true;
        return escriu();
    }

    if(trobat) return;


    for (int i = 0; i < n; ++i) {
        if(not posats[i] and not Diag[i+p] and not Diag2[i-p+n-1]) {
            V[p] = i;
            posats[i] = true;
            Diag[i+p] = true;
            Diag2[i-p+n-1] = true;
            f(p+1);
            posats[i] = false;
            Diag[i+p] = false;
            Diag2[i-p+n-1] = false;
        }
    }

}

int main() {
    cin >> n;
    V = Vec(n);
    Diag = Vec(2*n-1, false);
    Diag2 = Vec(2*n-1, false);

    posats = Vec(n, false);
    
    f(0);

    if(not trobat) cout << "NO SOLUTION" << endl;
}
