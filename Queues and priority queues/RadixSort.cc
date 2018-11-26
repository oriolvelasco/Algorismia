#include <iostream>
#include <queue>
using namespace std;




int main() {
	queue<string> cua;
	string s;
	while (cin >> s) cua.push(s);
	int n = s.size();
	
	vector<queue<string>> llistes(28);
	string par;
	
	for (int i = n-1; i >= 0; --i) {
		while (not cua.empty()) {
			par = cua.front();
			cua.pop();
			int on = par[i] - 'a' + 1;
			llistes[on].push(par);
		} 
		
		for (int j = 0; j < 28; ++j) {
			while (not llistes[j].empty()) {
				par = llistes[j].front();
				llistes[j].pop();
				cua.push(par);
			}
		}
	}
	
	while (not cua.empty()) {
		cout << cua.front();
		cua.pop();
		if (not cua.empty()) cout  << ' ' ;
	}
	cout << endl;
}
