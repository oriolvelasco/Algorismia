#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<VVVI> VVVVI;

const int MOD = 1e8+7;

int main() {
    int N = 51;
    VVVVI dp(N, VVVI(N, VVI(N, VI(N, 0))));
    //dp[i][j][k][l] es el nombre de paraules de longitud i amb un maxim
    //de j lletres 'a', k lletres 'b' i c lletres 'c';
    for (int j = 0; j < N; ++j) {
        for(int k = 0; k < N; ++k) {
            for (int l = 0; l < N; ++l) {
                dp[1][j][k][l] = min(1, j) + min(1, k) + min(1, l);
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                for (int l = 0; l < N; ++l) {
                    if (j + k + l >= i) {
                        if (j > 0) dp[i][j][k][l] += dp[i-1][j-1][k][l];
                        if (k > 0) dp[i][j][k][l] += dp[i-1][j][k-1][l];
                        if (l > 0) dp[i][j][k][l] += dp[i-1][j][k][l-1];
                        dp[i][j][k][l] %= MOD;
                    }
                }
            }
        }
    }
    int n, a, b, c;
    while (cin >> n >> a >> b >> c) cout << dp[n][a][b][c] << endl;
}
Jutge.org 
