#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    while (cin >> m) {
        vector<long long> v(m+1);
        for (int i = 0; i <= m; ++i) cin >> v[i];
        vector<vector<long long> > dp(m, vector<long long> (m, 0));
        for(int i = 1; i < m; ++i) {
            dp[i][1] = v[i-1]*v[i]*v[i+1];
            for (int j = 2; j <= i; ++j) {
                dp[i][j] = v[i-j]*v[i]*v[i+1] + dp[i-1][j-1];
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], v[i-j]*v[i-k]*v[i+1] + dp[i][k] + dp[i-k-1][j-k-1]);
                }
            }
        }
        cout << dp[m-1][m-1] << endl;
    }
}
