#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c, s;
    while (cin >> f >> c >> s) {
        vector<vector<int> > mat(f, vector<int> (c));
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j) cin >> mat[i][j];
        }
        vector<vector<vector<int> > > dp(f, vector<vector<int> > (c, vector<int> (s+1, 0)));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                dp[i][j][0] = mat[i][j];
                int maxim = 0;
                if(i > 0) maxim = max(maxim, dp[i-1][j][0]);
                if(j > 0) maxim = max(maxim, dp[i][j-1][0]);
                dp[i][j][0] += maxim;
            }
        }
        for (int k = 1; k <= s; ++k) {
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < c; ++j) {
                    dp[i][j][k] = mat[i][j];
                    int maxim = 0;
                    if(i > 0) maxim = max(maxim, dp[i-1][j][k]);
                    if(j > 0) maxim = max(maxim, dp[i][j-1][k]);
                    if(i > 0 and j > 1) maxim = max(maxim, dp[i-1][j-2][k-1]);
                    if(i > 1 and j > 0) maxim = max(maxim, dp[i-2][j-1][k-1]);
                    if(i < f-1 and j > 1) maxim = max(maxim, dp[i+1][j-2][k-1]);
                    if(i < f-2 and j > 0) maxim = max(maxim, dp[i+2][j-1][k-1]);
                    if(i > 0 and j < c-2) maxim = max(maxim, dp[i-1][j+2][k-1]);
                    if(i > 1 and j < c-1) maxim = max(maxim, dp[i-2][j+1][k-1]);
                    if(i < f-1 and j < c-2) maxim = max(maxim, dp[i+1][j+2][k-1]);
                    if(i < f-2 and j < c-1) maxim = max(maxim, dp[i+2][j+1][k-1]);
                    dp[i][j][k] += maxim;
                }
            }
        }



        int maxim = dp[f-1][c-1][0];
        for (int k = 1; k <= s; ++k) maxim = max(maxim, dp[f-1][c-1][k]);
        cout << maxim << endl;
    }
}
