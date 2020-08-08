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
VVI VIS; //Array to indicate if a cell is already visited

/* IDEA:
    If we code this problem as dynamic programming we can enter
    into a cycle.
    Example:
    (n, m) = (2, 3), p = (i, j) = (1, 1); t = treasure
    . . X
    . p t
    We return M[i][j] = f(i-1, j) or f(i+1, j);
    First, we go up and if it is not possible (invalid i or there
    is an obstacle), we go down
    f(1, 1) == '.' ok, options i-1, i+1
       --> f(0, 1) == '.' ok options i-1, i+1
            . p X
            . . t
            --> f(-1, 1) not ok (invalid i)
                __p__
                . . X
                . . t
            --> f(1, 1) CYCLE!!
*/
bool f(int i, int j) {
    if (i < 0 or i >= n or j < 0 or j >= m) return false;
    if (VIS[i][j]) return false; //We have already visited this cell
    VIS[i][j] = true;
    if (Map[i][j] == 'X') return false;
    return Map[i][j] == 't' or f(i-1, j) or f(i, j-1) or f(i+1, j) or f(i, j+1);
}

int main() {
    cin >> n >> m;
    Map = VVC(n, VC(m));
    VIS = VVI(n, VI(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> Map[i][j];
    int r, c;
    cin >> r >> c;
    if (f(r-1, c-1)) cout << "yes" << endl;
    else cout << "no" << endl;
}
