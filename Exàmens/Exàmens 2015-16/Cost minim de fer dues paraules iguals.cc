#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int n = s.size()+1;
        int m = t.size()+1;
        VVI dp(n, VI(m, 3*(n+m)));
        //dp[i][j] es el cost minim de fer iguals les i primeres lletres de s i les j primeres lletres de t
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(i == 0 or j == 0) dp[i][j] = 3*max(i,j);
                else {
                    if(s[i-1] == t[j-1]) dp[i][j] = min(dp[i-1][j-1], 2 + min(dp[i][j-1], dp[i-1][j]));
                    else dp[i][j] = 3 + min(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        cout << dp[n-1][m-1] << endl;
    }
}
