#include <iostream>
#include <vector>
using namespace std;

const int M = 100000007;

int main() {
    int N = 2001;
    vector<vector<int> > dp(N, vector<int> ((N+1)/2, 0));
    dp[0][0] = 1;
    for (int i = 1; i < (N+1)/2; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%M;
            if (j < i) dp[i][j] = (dp[i][j] + dp[i-1][j])%M;
            if (j < i-1) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%M;
        }
    }
    for (int i = (N+1)/2; i < N; ++i) {
        for (int j = 0; j < N-i; ++j) {
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%M;
            dp[i][j] = (dp[i][j] + dp[i-1][j])%M;
            dp[i][j] = (dp[i][j] + dp[i-1][j+1])%M;
        }
    }
    int n;
    while (cin >> n) cout << dp[n][0] << endl;
}
