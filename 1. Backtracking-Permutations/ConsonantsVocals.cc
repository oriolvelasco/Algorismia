#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<char> CharVec;

int n;
Vec V, posatsV, posatsC;
CharVec vocals;
CharVec consonants;

void escriu() {  
    for(int i = 0; i < 2*n; ++i) {
        if(i%2 == 0) cout << consonants[V[i]];
        if(i%2 == 1) cout << vocals[V[i]];
    }
    cout << endl;
}

void f(int p) {
    if(p==2*n) return escriu();
    
    if(p%2 == 0) {
        for (int i = 0; i < n; ++i) {
        if(not posatsC[i]) {
            V[p] = i;
            posatsC[i] = 1;
            f(p+1);
            posatsC[i] = 0;
        }
    }
        
    }
    
    else {
        for (int i = 0; i < n; ++i) {
        if(not posatsV[i]) {
            V[p] = i;
            posatsV[i] = 1;
            f(p+1);
            posatsV[i] = 0;
        }
    }
        
    }
}

int main() {
    cin >> n;
    V = Vec(2*n);
    posatsV = Vec(n, false);
    posatsC = Vec(n, false);
    vocals = CharVec(n);
    consonants = CharVec(n);
    
    for(int i = 0; i < n; ++i) cin >> consonants[i];
    for(int i = 0; i < n; ++i) cin >> vocals[i];
    
    f(0);
}
