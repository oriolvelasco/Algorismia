#include <iostream>
#include <vector>
using namespace std;

const int N = 1000000007;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int> > mat(n, vector<int> (m));
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
        vector<vector<long long> > dp(n+1, vector<long long> (m, 0));
        for (int i = 0; i < m; ++i) dp[0][i] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 1; i+k <= n and k <= mat[i][j]; ++k) dp[i+k][j] = (dp[i+k][j]+dp[i][j])%N;
                for (int k = 1; i+k <= n and j+k < m and k <= mat[i][j]; ++k) dp[i+k][j+k] = (dp[i+k][j+k]+dp[i][j])%N;
                for (int k = 1; i+k <= n and j-k >= 0 and k <= mat[i][j]; ++k) dp[i+k][j-k] = (dp[i+k][j-k]+dp[i][j])%N;
            }
        }
        int sum = 0;
        for (int i = 0; i < m; ++i) sum = (sum + dp[n][i])%N;
        cout << sum << endl;
    }
}
