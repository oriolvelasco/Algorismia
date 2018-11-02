#include <iostream>
#include <vector>
using namespace std;

//P87501_en
//Walk and jump
int n, m;
int MOD = 1e8 + 7;
typedef vector<char> VC;
typedef vector<VC> VVC;
VVC MAP;
typedef vector<int> VI;
typedef vector<VI> VVI;
VVI M;

int f(int i, int j) {
    if (i >= n or j >= m) return 0;
    int& res = M[i][j];
    if (res != -1) return res; //Already calculated
    if (MAP[i][j] == 'X') return res = 0; //Obstacle
    if (i == n-1 and j == m-1) return res = 1; //End of the matrix
    res = (f(i+1, j)%MOD + f(i, j+1)%MOD)%MOD;
    if (i+2 < n and MAP[i+1][j] == 'X') res = (f(i+2, j)%MOD + res)%MOD; //Jump to the right
    if (j+2 < m and MAP[i][j+1] == 'X') res = (f(i, j+2)%MOD + res)%MOD; //Jump below
    return res;
}

int main() {
    while (cin >> n >> m) {
        MAP = VVC(n, VC(m));
        M = VVI(n, VI(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> MAP[i][j];
        }
        cout << f(0, 0) << endl;
    }
}
