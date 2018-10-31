#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<char> CharVec;
typedef vector<int> Vec;
typedef vector<Vec> Taula;

int n, incomp;
CharVec especies;
Taula compatibles;
Vec posats, V;

void escriu() {    
   for (int i = 0; i < n; ++i) cout << especies[V[i]];
   cout << endl;
   
}

void f(int p) {
    if(p == n) return escriu();

    for (int i = 0; i < n; ++i) {
        if(not posats[i]) {
            if(p == 0 or compatibles[i][V[p-1]]) {
                posats[i] = true;
                V[p] = i;
                f(p+1);
                posats[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;

    especies = CharVec(n);
    compatibles = Taula(n, Vec(n, true));
    posats = Vec(n, false);
    V = Vec(n);

    for(int i = 0; i < n; ++i) cin >> especies[i];

    cin >> incomp;

    char esp1, esp2;
    int e1, e2;
    for(int i = 0; i < incomp; ++i) {
        cin >> esp1 >> esp2;
        for (int j = 0; j < n; ++j)
        {
            if(esp1 == especies[j]) e1 = j;
            if(esp2 == especies[j]) e2 = j;
        }
        compatibles[e1][e2] = false;
        compatibles[e2][e1] = false;
    }

    
    f(0);
}
