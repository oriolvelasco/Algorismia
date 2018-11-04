#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

const int MOD = 1e8 +7;

int main() {
    int N = 5e4;
    VVVI dp(N+1, VVI(19, VI(10, 0)));
    //dp[i][j][k] es el nombre de nombres j-xulos de longitud i acabats en k;
    VVI dp2(N+1, VI(19, 0));
    //dp2[i][j] es el nombre de nombres j-xulos de longitud i
    for (int j = 0; j < 19; ++j) {
        for (int k = 0; k < 10; ++k) dp[1][j][k] = 1;
        dp2[1][j] = 10;
    }
    for (int i = 2; i < N+1; ++i) {
        for (int j = 0; j < 19; ++j) {
            for (int k = 0; k < 10; ++k) {
                dp[i][j][k] = dp2[i-1][j];
                if(j - k < 10 and j - k >= 0) dp[i][j][k] -= dp[i-1][j][j-k];
                if(dp[i][j][k] < 0) dp[i][j][k] += MOD;
                dp2[i][j] += dp[i][j][k];
            }
            dp2[i][j] %= MOD;
        }
    }
    int n, K;
    while (cin >> K >> n) cout << dp2[n][K] << endl;
}
