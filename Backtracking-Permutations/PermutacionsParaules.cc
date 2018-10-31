#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<string> SVec;

int n;
Vec V, posats;
SVec paraules;

void escriu() {
    cout << "(";
    bool primer = true;

    cout << paraules[V[0]];
    
   for (int i = 1; i < n; ++i) cout << "," << paraules[V[i]];
   
    cout << ")" << endl;
}

void f(int p) {
    if(p==n) {
        escriu();
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(not posats[i]) {
            V[p] = i;
            posats[i] = true;
            f(p+1);
            posats[i] = false;
        }
    }

}

int main() {
    cin >> n;
    V = Vec(n);
    paraules = SVec(n);
    posats = Vec(n, false);

    for(int i = 0; i < n; ++i) cin >> paraules[i];
    
    f(0);
}
