#include <iostream>
#include <vector>
using namespace std;

//P70690_en
//Treasures in a map (1)
int n, m;
typedef vector<char> VC;
typedef vector<VC> VVC;
VVC Map;
typedef vector<int> VI;
typedef vector<VI> VVI;
VVI M;

int f(int i, int j) {
    if (i < 0 or i >= n or j < 0 or j >= m) return 0;
    int& res = M[i][j];
    if (res != -1) return res;
    if (Map[i][j] == 't') return res = 1;
    if (Map[i][j] == 'X') return res = 0;
    res = max(f(i-1, j), f(i, j-1));
    if (res) return res;
    res = max(res, f(i+1, j));
    if (res) return res;
    res = max(res, f(i, j+1));
    return res;
}

int main() {
    cin >> n >> m;
    Map = VVC(n, VC(m));
    M = VVI(n, VI(m, -1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> Map[i][j];
    int r, c;
    cin >> r >> c;
    if (f(r-1, c-1)) cout << "yes" << endl;
    else cout << "no" << endl;
}
