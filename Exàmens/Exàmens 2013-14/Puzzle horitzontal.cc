#include <iostream>
#include <vector>
using namespace std;

const int N = 100000007;

int main() {
    vector<vector<int> > dp(10001, vector<int> (2, 0));
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[2][0] = 8;
    dp[2][1] = 1;
    for (int i = 3; i < 10001; ++i) {
        dp[i][1] = (dp[i-2][0]+dp[i-2][1]+dp[i-3][0])%N;
        dp[i][0] = (2*(dp[i-2][0]+dp[i-1][0]+dp[i][1]))%N;
    }
    int n;
    while(cin >> n) cout << dp[n][0] << endl;
}
