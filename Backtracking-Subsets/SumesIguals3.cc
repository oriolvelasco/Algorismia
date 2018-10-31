#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int s, n, suma, total;
Vec V, posats, suma_parcial;

void escriu() {
    cout << "{";
    int j = 0;
    bool primer = true;

    while (posats[j] == 0 and j <= n) {
        ++j;
    }
    
    if(j >= n) {
        cout << "}" << endl;
        return;
    }
    
    while(j < n) {
        if(posats[j]) {
            if(not primer) cout << ",";
            primer = false;
            cout << V[j];
        }
        ++j;
    }
    cout << "}" << endl;
}

void f(int p) {
    if(suma > s) return;
    int queda = suma_parcial[n]-suma_parcial[p];
    if(queda+suma < s) return;

    if (p == n and suma == s) {
        escriu();
        return;
    }
    
    if(p==n) return;
    
    f(p+1);
    
    suma += V[p];
    posats[p] = true;
    f(p+1);
    
    suma -= V[p];
    posats[p] = false;

}

int main() {
    cin >> s >> n;
    V = Vec(n);
    posats = Vec(n, false);
    suma_parcial = Vec(n+1, 0);
    suma = 0;
    total = 0;
    
    for(int i = 0; i < n; ++i) {
        cin >> V[i];

        for(int j = 0; j < i; ++j) {
            suma_parcial[i] += V[j];
        }
    }

    suma_parcial[n] = suma_parcial[n-1] + V[n-1];
    
    f(0);
}
