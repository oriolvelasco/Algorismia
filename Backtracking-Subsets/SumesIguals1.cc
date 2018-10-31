#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<string> SVec;

int s, n, suma;
Vec V, posats;

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
    suma = 0;
    
    for(int i = 0; i < n; ++i) cin >> V[i];
	
	f(0);
}
