#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n;
VI v, t;
VB uv, ut;

void f(int i) {
    if(i == 2*n) {
        for (int j = 0; j < n; ++j) {
            if(j != 0) cout << '-';
            cout << char('A'+j) << v[j] << char('a'+t[j]);
        }
        cout << endl;
        return;
    }
    if(i%2 == 0) {
        for(int j = 0; j < n; ++j) {
            if(not uv[j]) {
                uv[j] = true;
                v[i/2] = j;
                f(i+1);
                uv[j] = false;
            }
        }
        return;
    }
    for (int j = 0; j < n; ++j) {
        if(not ut[j]) {
            ut[j] = true;
            t[i/2] = j;
            f(i+1);
            ut[j] = false;
        }
    }
    return;
}

int main() {
    int compt = 1;
    while(cin >> n and n != 0) {
        cout << "Case " << compt << endl;
        v = t = VI(n);
        uv = ut = VB(n, false);
        f(0);
        ++compt;
    }
}
