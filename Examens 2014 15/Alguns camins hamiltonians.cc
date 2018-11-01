#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int n;
VVB graf;
int nombre;
VB used;

void f(int i, bool pintat, int nodant) {
    if(i == n) {
        ++nombre;
        return;
    }
    if(i < n-1) {
        for (int j = 0; j < n-1; ++j) {
            if(not used[j]) {
                used[j] = true;
                if(graf[nodant][j] and not pintat) f(i+1, true, j);
                else if(not graf[nodant][j]) f(i+1, false, j);
                used[j] = false;
            }
        }
        return;
    }
    if(graf[nodant][n-1] and not pintat) f(i+1, true, n-1);
    else if(not graf[nodant][n-1]) f(i+1, false, n-1);
    return;
}

int main() {
    while (cin >> n) {
        nombre = 0;
        graf = VVB(n, VB(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                if(x == 0) graf[i][j] = false;
                else graf[i][j] = true;
            }
        }
        used = VB(n, false);
        used[0] = true;
        f(1, false, 0);
        cout << nombre << endl;
    }
}
