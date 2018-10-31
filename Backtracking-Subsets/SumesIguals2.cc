#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<string> SVec;

int s, n, suma;
Vec V, posats;
bool trobat = false;

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
    if(trobat) return;

	if (p == n and suma == s) {
		escriu();
        trobat = true;
		return;
	}
    
    if(p==n) return;

    posats[p] = true;
    suma += V[p];
    f(p+1);   
    
    suma -= V[p];
    posats[p] = false;
    f(p+1);
}


int main() {
	cin >> s >> n;
    V = Vec(n);
    posats = Vec(n, false);
    suma = 0;

    for(int i = 0; i < n; ++i) cin >> V[i];

    sort(V.begin(),V.end(), greater<int>());
	
	f(0);

    if(!trobat) cout << "no solution" << endl;
}
