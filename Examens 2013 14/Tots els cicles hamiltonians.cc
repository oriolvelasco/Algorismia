#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

int n;
VVI graf;
VI ordre;
VB used;

void f(int i, int cost) {
    if(i == n) {
        if(graf[ordre[n-1]][0] == 0) return;
        cost += graf[ordre[n-1]][0];
        for (int j = 0; j < n; ++j) {
            cout << ordre[j] << ' ';
        }
        cout << "0 (" << cost << ")" << endl;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if(not used[j] and graf[ordre[i-1]][j] != 0) {
            used[j] = true;
            ordre[i] = j;
            f(i+1, cost+graf[ordre[i-1]][j]);
            used[j] = false;
        }
    }
}

int main() {
    while (cin >> n) {
        graf = VVI(n, VI(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graf[i][j];
            }
        }
        ordre = VI(n);
        used = VB(n, false);
        ordre[0] = 0;
        used[0] = true;
        f(1,0);
        cout << "--------------------" << endl;
    }
}
