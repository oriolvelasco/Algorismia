#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
    int t, n;
    while (cin >> t >> n) {
        VI temps(n);
        VI coneixement(n);
        for (int j = 0; j < n; ++j) cin >> temps[j] >> coneixement[j];
        VVI dp(t+1, VI(n+1, 0)); 
        //dp[i][j] es el maxim coneixement que pot tenir a l'instant i 
        //si ha pogut veure vĂ­deos d'entre els j primers videos
        for (int i = 1; i <= t; ++i) {
            dp[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1];
                if (i-temps[j-1] >= 0) {
                    int aux = dp[i-temps[j-1]][j-1] + coneixement[j-1];
                    dp[i][j] = max(dp[i][j], aux);
                }
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][j]);
            }
        }
        cout << dp[t][n] << endl;
    }
}
