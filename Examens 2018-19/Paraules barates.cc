#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int n, m, fi, ci, ff, cf, costmax;
VVC lletres;
VVI valors;
VVB used;
VC paraula;

void f(int i, int j, int cost) {
    if (i < 0 or i >= n or j < 0 or j >= m) return;
    if (used[i][j] or cost + valors[ff][cf] > costmax) return;
    if (i == ff and j == cf) {
        int mida = paraula.size();
        for (int k = 0; k < mida; ++k) cout << paraula[k];
        cout << lletres[ff][cf] << endl;
        return;
    }
    used[i][j] = true;
    paraula.push_back(lletres[i][j]);
    cost += valors[i][j];
    f(i+1, j, cost);
    f(i-1, j, cost);
    f(i, j+1, cost);
    f(i, j-1, cost);
    used[i][j] = false;
    paraula.pop_back();
    cost -= valors[i][j];
}

int main() {
    cin >> n >> m;
    lletres = VVC(n, VC(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) cin >> lletres[i][j];
    valors = VVI(n, VI(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) cin >> valors[i][j];
    used = VVB(n, VB(m, false));
    cin >> fi >> ci >> ff >> cf >> costmax;
    f(fi, ci, 0);
}
