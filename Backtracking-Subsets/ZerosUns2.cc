#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int n, u;
Vec V;

void escriu() {
	cout << V[0];
	for(int i = 1; i < V.size(); ++i) {
		cout << " " << V[i];
	}
	cout << endl;
}

void f(int p, int uns) {
	if (p==n) return escriu();

	if(p-uns < n-u) {
		V[p] = 0;
		f(p+1, uns);
	}

	if(uns < u) {
		V[p] = 1;
		f(p+1, uns+1);
	}

	
}

int main() {
	cin >> n >> u;
	V = Vec(n);
	f(0, 0);
	
}
