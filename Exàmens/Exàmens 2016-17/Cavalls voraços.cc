#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
int n, m, maxim, cont;
VVE M, P;

bool dins (int i, int j) {
	if (i < 0 or j < 0 or i > n - 1 or j > m - 1) return false;
	return true;
}

bool ok(int i, int j){
	if (not dins(i,j)) return false;
	if (dins(i+2,j+1) and P[i+2][j+1] == 1) return false;
	if (dins(i+2,j-1) and P[i+2][j-1] == 1) return false;
	if (dins(i-2,j+1) and P[i-2][j+1] == 1) return false;
	if (dins(i-2,j-1) and P[i-2][j-1] == 1) return false;
	if (dins(i+1,j+2) and P[i+1][j+2] == 1) return false;
	if (dins(i+1,j-2) and P[i+1][j-2] == 1) return false;
	if (dins(i-1,j+2) and P[i-1][j+2] == 1) return false;
	if (dins(i-1,j-2) and P[i-1][j-2] == 1) return false;
	return true;
}

void f(int i, int j){
	if (i == n and j == 0) {
		if (cont > maxim) maxim = cont;
		return;
	}
	if (j < m - 1) f(i,j+1);
	else f(i+1,0);
	if (ok(i,j)) {
		P[i][j] = 1;
		cont += M[i][j];
		if (j < m - 1) f(i,j+1);
		else f(i+1,0);
		P[i][j] = 0;
		cont -= M[i][j];
	}
}

int main(){
	while (cin >> n >> m) {
		M = VVE(n, VE(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> M[i][j];
		}
		P = VVE(n, VE(m,0));
		maxim = 0;
		cont = 0;
		f(0,0);
		cout << maxim << endl;
	}
}
