#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<vector<int> > graf(n, vector<int> (n));
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> graf[i][j];
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) dp[i] = max(dp[i], dp[j]+graf[j][i]);
        int maxim = 0;
        for (int i = 0; i < n; ++i) maxim = max(maxim, dp[i]);
        cout << maxim << endl;
    }
}
