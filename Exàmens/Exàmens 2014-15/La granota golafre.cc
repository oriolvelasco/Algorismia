#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

const int INF = 1e9;
VVI dp;
VI flies;
int n, j;

int calculate(int i, int j) {
    if (i == n-1) return flies[n-1];
    int& res = dp[i][j];
    if (res != INF) return res;
    res = calculate(i+1, j);
    if (j > 0 and i < n-2) res = min(res, calculate(i+2, j-1));
    if (j > 0 and i < n-3) res = min(res, calculate(i+3, j-1));
    return res = res + flies[i];
}

int main() {
    while (cin >> n >> j) {
        //dp[i][j] = minim nombre de mosques menjades a la posicio i amb j salts restants
        dp = VVI(n, VI(j+1, INF));
        flies = VI(n);
        for (int i = 0; i < n; i++) cin >> flies[i];
        cout << calculate(0, j) << endl;
    }
}
