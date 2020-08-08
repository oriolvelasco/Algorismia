#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> VI;

int n, k;
VI s, us;

void print() {
	cout << "(";
	bool first = true;
	for (int k = 1; k <= n; ++k) {
		if (first) first = false;
		else cout << ", ";
		cout << s[k];
	}
	cout << ")" << endl;
}

int non_used() {
	for (int p = 1; p <= n; ++p) {
		if (not us[p]) return p;
	}
	return -1;		// quan s'hagi omplert s no hi haura cap element no usat
}

/* i: posicio actual; ini: posicio inici cicle actual;
caselles: caselles buides de la permutacio; cicles: cicles a crear;*/
void f(int i, int ini, int caselles, int cicles) {
	if (cicles > caselles or cicles < 0) return;
	if (caselles == 0 and cicles == 0) return print();
	for (int x = 1; x <= n; ++x) {
		if (not us[x]) {
			s[i] = x;
			us[x] = true;
			if (x == ini) f(non_used(), non_used(), caselles - 1, cicles - 1);	// hem tancat un cicle (x = ini)
			else f(x, ini, caselles - 1, cicles); 								// no hem tancat un cicle (x != ini)
			us[x] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	s = VI(n + 1, -1);
	us = VI(n + 1, false);
	f(1, 1, n, k);
}
