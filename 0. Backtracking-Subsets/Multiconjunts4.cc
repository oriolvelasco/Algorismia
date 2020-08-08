#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<string> SVec;

int n, t, x, y;
Vec V;

void escriu() {
    cout << "{";
    int j = 0;
    bool primer = true;

    while (V[j] == 0 and j <= n) {
        ++j;
    }
    
    if(j >= n) {
        cout << "}" << endl;
        return;
    }
    
    while(j < n) {
        if(V[j] != 0) {
            if(not primer) cout << ",";
            primer = false;
            cout << j+1;
            for(int k = 0; k < V[j]-1; ++k) cout << "," << j+1;
        }
        ++j;
    }
    cout << "}" << endl;
	
	
}

void f(int p, int times) {
	if (p == n and times==t) {
		escriu();
		return;
	}
    
    if(p==n or times > t) return;
    
    for (int i = x; i <= y; ++i) {
        V[p] = i;
        f(p+1, times+i);
    }
}

int main() {
	cin >> n >> x >> y >> t;
    V = Vec(n);
	
	f(0,0);
}
