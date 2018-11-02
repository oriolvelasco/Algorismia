#include <iostream>
#include <vector>
using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VVI;

const long long N = 100000007;

int main() {
    VVI dp(1001, VI(1001, 0));
    //dp[i][j] es el nombre de permutacions amb longitud n i k cicles
    dp[1][1] = 1;
    for (int i = 2; i < 1001; ++i) {
        dp[i][1] = ((i-1)*dp[i-1][1])%N;
        for(int j = 2; j <= i; ++j) {
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]*(i-1))%N;
        }
    }
    int n, k;
    while (cin >> n >> k) cout << dp[n][k] << endl;
}
