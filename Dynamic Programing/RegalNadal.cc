#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> Vec;

int main() {
	long long n, count = 1;
	while(cin >> n) {
		cout << "#" << count << endl;
		Vec Bolets;
		Vec T;
		Bolets = Vec(n,0);
		T = Vec(n, 0);

		for (int i = 0; i < n; ++i) cin >> Bolets[i];

		for (int i = 0; i < n; ++i) {
			T[i] = Bolets[i];
			if(i > 0) T[i] += T[i-1];
		}

		int m; 
		cin >> m;

		for (int i = 0; i < m; ++i)
		{
			int p, c;
			cin >> p >> c;
			int res;
			if(p > c) res = T[p-1] - T[c-1] + Bolets[c-1];
			else res = T[c-1] - T[p-1] + Bolets[p-1];
			cout << res << endl;
		}

		/*for (int i = 0; i < n; ++i)
		{
			cout << T[i] << " ";
		}
		cout << endl;*/
		++count;
	}
}
