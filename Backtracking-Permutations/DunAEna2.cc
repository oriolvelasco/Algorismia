#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int n;
Vec V, posats;

void escriu() {
    cout << "(";
    bool primer = true;

    cout << V[0]+1;
    
   for (int i = 1; i < n; ++i) cout << "," << V[i]+1;
   
    cout << ")" << endl;
}

void f(int p, int k, int cicles) {
    if(V[k] != -1) ++cicles;

    if(cicles >= 2) return;
    if(p == n) return escriu();

    if(V[k] != -1) {
        for (int i = 0; i < n; ++i) {
            if (V[i] == -1) return f(p, i, cicles);
        }
    }


    for (int i = 0; i < n; ++i) {
        if(not posats[i]) {
            //cout << i << " " << k << " " << posats[i] << " " << cicles << endl;
            V[k] = i;
            posats[i] = true;
            f(p+1, i, cicles);
            posats[i] = false;
            V[k] = -1;
        }
    }

}

int main() {
    cin >> n;
    V = Vec(n, -1);
    posats = Vec(n, false);
    
    f(0,0,0);
}
