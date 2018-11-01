#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;
VVB M;
int cont;
int n, m, c;

bool ok(int i, int j){
	return (i >= 0 and i < n and j >= 0 and j < m and M[i][j]);
}

void f(int i, int j, int& cont){
	if (i == n and j == 0) {
		++cont;
		return;
	}
	//Comprovo que la casella on miro estigui lliure
	if (not M[i][j]) {
		if (j < m - 1) return f(i,j+1,cont);
		else return f(i+1,0,cont);
	}
	//Intentem colocarla horitzontalment
	if (ok(i,j) and ok(i,j+1)) {
		M[i][j] = M[i][j+1] = false;
		if (j < m - 2) f(i,j+2,cont);
		else f(i+1,0,cont);
		M[i][j] = M[i][j+1] = true;
	}
	//Intentem colocarla verticalment
	if (ok(i,j) and ok(i+1,j)) {
		M[i][j] = M[i+1][j] = false;
		if (j < m - 1) f(i,j+1,cont);
		else f(i+1,0,cont);
		M[i][j] = M[i+1][j] = true;
	}
	//Si no puc colocarla vertical ni horitzontalment, distribucio incorrecta
	return;
	

}

int main(){
	while (cin >> n >> m >> c){
		M = VVB(n, VB(m,true)); //True representa que no esta ocupat
		int x, y;
		for (int i = 0; i < c; ++i) {
			cin >> x >> y;
			M[x][y] = false;
		}

		cont = 0;
		f(0,0,cont);
		cout << cont << endl;

	}
}
