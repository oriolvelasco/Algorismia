#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<vector<long long> > > dp(16, vector<vector<long long> > (16, vector<long long> (2, 0)));
    dp[1][0][1] = 21;
    dp[1][1][0] = 5;
    for (int i = 2; i < 16; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j > 0)dp[i][j][0] = 5*(dp[i-1][j-1][0]+dp[i-1][j-1][1]);
            dp[i][j][1] = 21*(dp[i-1][j][0]);
        }
    }
    int n, v;
    while (cin >> n >> v) cout << dp[n][v][0]+dp[n][v][1] << endl;
}
