#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    while (cin >> r >> c) {
        vector<vector<char> > mat(r, vector<char> (c));
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) cin >> mat[i][j];
        int num = 0;
        vector<vector<int> > dp(r, vector<int> (c, 0));
        dp[r-1][c-1] = 1;
        for (int i = r-1; i >= 0; --i) {
            for (int j = c-1; j >= 0; --j) {
                if(mat[i][j] == 'R') {
                    if(i > 0) dp[i-1][j] += dp[i][j];
                    else num += dp[i][j];
                    if(j > 0) dp[i][j-1] += dp[i][j];
                    else num += dp[i][j];
                    if(i > 0 and j > 0) dp[i-1][j-1] += dp[i][j];
                    else num += dp[i][j];
                }
                if(mat[i][j] == 'C') {
                    if(i > 0 and j > 1) dp[i-1][j-2] += dp[i][j];
                    else num += dp[i][j];
                    if(j > 0 and i > 1) dp[i-2][j-1] += dp[i][j];
                    else num += dp[i][j];
                }
            }
        }
        cout << num << endl;
    }
}
