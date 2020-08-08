#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int x, n;
VI m;
const int N = 100000007;

int main() {
    while (cin >> x >> n) {
        m = VI(n);
        for (int i = 0; i < n; ++i) cin >> m[i];
        VVI dp(n, VI(x+1, 0));
        //dp[i][j] es el nombre de maneres d'aconseguir el valor j amb les i+1 primeres monedes
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= x; ++j) {
                if(i > 0) dp[i][j] = dp[i-1][j];
                if(m[i] == j) dp[i][j] += 2;
                if(2*m[i] == j) ++dp[i][j];
                if(i > 0 and j - m[i] > 0) dp[i][j] += 2*dp[i-1][j-m[i]];
                if(i > 0 and j - 2*m[i] > 0) dp[i][j] += dp[i-1][j-2*m[i]];
                dp[i][j] %= N;
            }
        }
        cout << dp[n-1][x] << endl;
    }
}
