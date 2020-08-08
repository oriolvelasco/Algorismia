#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y, N;
    while(cin >> x >> y >> N) {
        vector<vector<long long> > dp(x+1, vector<long long> (y+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                for (int k = 0; k <= i-1; ++k) for (int l = 0; l <= j; ++l) dp[i][j] = (dp[i][j] + dp[k][l]*dp[i-1-k][j-l])%N;
                for (int k = 0; k <= i; ++k) for (int l = 0; l <= j-1; ++l) dp[i][j] = (dp[i][j] + dp[k][l]*dp[i-k][j-1-l])%N;
            }
        }
        cout << dp[x][y] << endl;
    }
}
