#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int n;
Vec V;

void escriu() {
	cout << V[0];
	for(int i = 1; i < V.size(); ++i) {
		cout << " " << V[i];
	}
	cout << endl;
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
	f(0);
	
}
