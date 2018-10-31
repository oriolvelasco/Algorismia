#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        vector<vector<int> > dp(s.size()+1, vector<int> (t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) dp[i][0] = 10*i;
        for (int j = 0; j <= t.size(); ++j) dp[0][j] = 10*j;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 10+min(dp[i-1][j], dp[i][j-1]);
                    int aux = abs(s[i-1]-t[j-1]);
                    dp[i][j] = min(dp[i][j], aux+dp[i-1][j-1]);
                }
            }
        }
        cout << dp[s.size()][t.size()] << endl;
    }
}
