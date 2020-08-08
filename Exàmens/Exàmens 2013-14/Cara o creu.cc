#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    int n, m;
    while (cin >> m >> n) {
        vector<double> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        vector<vector<double> > dp (n+1, vector<double> (m+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if(i != 0) dp[i][j] += dp[i-1][j]*(1-p[i-1]);
                if(j != 0) dp[i][j] += dp[i][j-1]*p[i-1];
            }
        }
        double prob = 1;
        for (int j = 0; j < m; ++j) prob -= dp[n][j];
        if(prob < 0) prob = -prob;
        cout << prob << endl;
    }
}
