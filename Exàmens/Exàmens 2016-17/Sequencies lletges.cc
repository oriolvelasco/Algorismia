#include <iostream>
#include <vector>
using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

const long long MOD = 100000007;

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        VI v(n+1, -1);
        for (int i = 0; i < m; ++i) {
            int pos, val;
            cin >> pos >> val;
            v[pos+1] = val;
        }
        VVVI dp(n+1, VVI(k+1, VI(n, 0)));
        //dp[i][j][l] es el nombre de sequencies j-lletges als i primers elements del vector posant el nombre l a la posicio i
        VVI dp2(n+1, VI(k+1, 0));
        //dp2[i][j] es el nombre de sequencies j-lletges als i primers elements del vector
        if(v[1] == -1) {
            for(int l = 0; l < n; ++l) dp[1][0][l] = 1;
            dp2[1][0] = n;
        }
        else {
            dp[1][0][v[1]] = 1;
            dp2[1][0] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= min(i-1, k); ++j) {
                if(v[i] == -1){
                    for(int l = 0; l < n; ++l) {
                        dp[i][j][l] = dp2[i-1][j];
                        if(l > 0 and j > 0) dp[i][j][l] += (dp[i-1][j-1][l-1] - dp[i-1][j][l-1]);
                        else if (l > 0) dp[i][j][l] -= dp[i-1][j][l-1];
                        if(l < n-1 and j > 0) dp[i][j][l] += (dp[i-1][j-1][l+1] - dp[i-1][j][l+1]);
                        else if (l < n-1) dp[i][j][l] -= dp[i-1][j][l+1];
                        dp[i][j][l] %= MOD;
                        //ens assegurem que sigui positiu
                        while(dp[i][j][l] < 0) dp[i][j][l] += MOD;
                        dp2[i][j] += dp[i][j][l];
                        dp2[i][j] %= MOD;
                    }
                }
                else {
                    int l = v[i];
                    dp[i][j][l] = dp2[i-1][j];
                    if(l > 0 and j > 0) dp[i][j][l] += (dp[i-1][j-1][l-1] - dp[i-1][j][l-1]);
                    else if (l > 0) dp[i][j][l] -= dp[i-1][j][l-1];
                    if(l < n-1 and j > 0) dp[i][j][l] += (dp[i-1][j-1][l+1] - dp[i-1][j][l+1]);
                    else if (l < n-1) dp[i][j][l] -= dp[i-1][j][l+1];
                    dp[i][j][l] %= MOD;
                    //ens assegurem que sigui positiu
                    while(dp[i][j][l] < 0) dp[i][j][l] += MOD;
                    dp2[i][j] = dp[i][j][l];
                }
            }
        }
        cout << dp2[n][k] << endl;
    }
}
