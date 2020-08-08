#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

int n, m;
VVI graf;
VB used;
bool trobat;

void f(int i) {
    if (trobat) return;
    if (i == n/2) {
        trobat = true;
        return;
    }
    bool petit = false;
    for (int j = 0; j < n and not petit; ++j) {
        if(not used[j]) {
            petit = true;
            used[j] = true;
            for (int k = 0; k < graf[j].size(); ++k) {
                if(not used[graf[j][k]]) {
                    used[graf[j][k]] = true;
                    f(i+1);
                    used[graf[j][k]] = false;
                }
            }
            used[j] = false;
        }
    }
    return;
}

int main() {
    while(cin >> n >> m) {
        graf = VVI(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            graf[x-1].push_back(y-1);
            graf[y-1].push_back(x-1);
        }
        used = VB(n, false);
        trobat = false;
        f(0);
        if(trobat) cout << "si" << endl;
        else cout << "no" << endl;
    }
}
