#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

int n, freq;
VI sol;

void f(int i) {
    if(i == n) {
        for(int j = 0; j < n; ++j) cout << char('a'+sol[j]);
        cout << endl;
        return;
    }
    if(sol[i] != -1) {
        if(i == 0 or sol[i] != sol[i-1]) f(i+1);
        return;
    }
    for (int j = 0; j < 3; ++j) {
        if(i == 0 or j != sol[i-1]) {
            sol[i] = j;
            f(i+1);
            sol[i] = -1;
        }
    }
}

int main() {
    while(cin >> n >> freq) {
        sol = VI(n, -1);
        for (int i = 0; i < freq; ++i) {
            int p;
            char c;
            cin >> p >> c;
            sol[p] = c-'a';
        }
        f(0);
        cout << "--------------------" << endl;
    }
}
