#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

int n, m;
VI v, dv;

void f(int i, int pref) {
    if(i == n) {
        for (int j = 0; j < n; ++j) cout << v[j];
        cout << endl;
        return;
    }
    for(int j = 0; j < 10; ++j) {
        bool okay = true;
        for (int k = 0; k < m; ++k) if((10*pref+j)%dv[k] == 0) okay = false;
        if(okay) {
            v[i] = j;
            f(i+1, 10*pref+j);
        }
    }
}

int main() {
    while (cin >> n >> m) {
        dv = VI(m);
        v = VI(n);
        for (int i = 0; i < m; ++i) cin >> dv[i];
        f(0,0);
        cout << "----------" << endl;
    }
}
