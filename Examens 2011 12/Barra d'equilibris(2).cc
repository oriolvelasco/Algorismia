#include <iostream>
#include <vector>
using namespace std;

const int N = 100000007;

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<int> l(n);
        for (int i = 0; i < n; ++i) cin >> l[i];
        vector<vector<int> > dp(n+1, vector<int> (m+1, 0));
        dp[0][m/2] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j+l[i] <= m) dp[i+1][j+l[i]] = (dp[i+1][j+l[i]]+dp[i][j])%N;
                if (j-l[i] >= 0) dp[i+1][j-l[i]] = (dp[i+1][j-l[i]]+dp[i][j])%N;
            }
        }
        for (int i = 0; i <= m; ++i) if(dp[n][i] != 0) cout << i-m/2 << ' ' << dp[n][i] << endl;
    }
}
Jutge.org 
