#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int n, res=0;
Vec V, posats, Diag, Diag2;

void escriu() {
    cout << "(";
    bool primer = true;

    cout << V[0]+1;
    
   for (int i = 1; i < n; ++i) cout << "," << V[i]+1;
   
    cout << ")" << endl;
}

void f(int p) {
    if(p == n) ++res;


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
    cout << res << endl;
}
