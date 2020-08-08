#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<long long> > dp(26, vector<long long> (26,0));
    //dp[n][b] is the number of ways to distribute n distinct objects in b bags with at least one object in every bag
    for (int i = 0; i < 26; ++i) {
        dp[i][1] = dp[i][i] = 1;
        for (int j = 2; j < i; ++j) {
            dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
        }
    }
    vector<vector<long long> > comb(26, vector<long long> (26,0));
    for (int i = 0; i < 26; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    int n, x, y;
    while(cin >> n >> x >> y) {
        if(x+y > n) cout << 0 << endl;
        else cout << comb[n][y]*dp[n-y][x] << endl;
    }
}
