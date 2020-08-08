#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<string> SVec;

int n, p;
Vec V;
SVec S;

void escriu() {
    for(int i = 0; i < p; ++i) {
        cout << "subconjunt " << i+1 << ": {";
        int j = 0;
    
        while (V[j]!=i and j <= n) {
            ++j;
        }
        
        if(j >= n) {
            cout << "}" << endl;
        }
        
        else {
            cout << S[j];
            for(int k = j+1; k < V.size(); ++k) if(V[k] == i) cout << "," << S[k];
            cout << "}" << endl;
        }
    }
    cout << endl;
	
	
}

void f(int pos) {
	if (pos == n) {
		escriu();
		return;
	}
    
    for (int i = 0; i < p; ++i) {
        V[pos] = i;
        f(pos+1);
    }
}

int main() {
	cin >> n;
    V = Vec(n);
    S = SVec(n);
    
    for(int i = 0; i < n; ++i) cin >> S[i];
    
    cin >> p;
	
	f(0);
}
