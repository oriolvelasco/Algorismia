#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> VI;

int n, k;
VI s, us;

void print() {
	bool first = true;
	for (int k = 0; k < n; ++k) {
		if (first) first = false;
		else cout << " ";
		cout << s[k];
	}
	cout << endl;
}


void f(int i, int falta) {
	if (i == n and falta == 0) return print();
	if (i == n or falta > n - i or falta < 0) return;
	if (s[i] == -1) {
		for (int x = 0; x < n; ++x) {
			if (not us[x]) {
				s[i] = x;
				us[x] = true;
				if (i > 0 and abs(s[i - 1] - x) == 1) f(i + 1, falta - 1);
				else f(i + 1, falta);
				s[i] = -1;
				us[x] = false;
			}
		}
	}
	else {
		if (i > 0 and abs(s[i - 1] - s[i]) == 1) f(i + 1, falta - 1);
		else f(i + 1, falta);
	}
}

int main() {
	int m;
	while (cin >> n >> k >> m) {
		s = VI(n, -1);
		us = VI(n, false);
		while (m--) {
			int i, x;
			cin >> i >> x;
			s[i] = x;
			us[x] = true;
		}
		f(0, k);
		cout << string(20, '*') << endl;
	}
}
