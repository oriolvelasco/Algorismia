#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<string> SVec;

int n;
Vec V;
SVec S;

void escriu() {
    cout << "{";
    int j = 0;
    
    while (not V[j] and j <= n) {
        ++j;
    }
    
    if(j == n) {
        cout << "}" << endl;
        return;
    }
    
    cout << S[j];
	
    for(int i = j+1; i < V.size(); ++i) if(V[i]) cout << "," << S[i];
    
    cout << "}" << endl;
	
	
}

void f(int p) {
	if (p==n) {
		escriu();
		return;
	}

	V[p] = 0;
	f(p+1);
	V[p] = 1;
	f(p+1);
}

int main() {
	cin >> n;
    V = Vec(n);
    S = SVec(n);
    
    for(int i = 0; i < n; ++i) cin >> S[i];
	
	f(0);
}
