#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

const int MOD = 100000007;

int main() {
    int n, b, v;
    VVVI dp(201, VVI(201, VI(201, 0)));
    //dp[i][j][k] es el nombre de distribucions possibles amb i retoladors negres, j retoladors blaus i k retoladors vermells
    dp[0][0][0] = 1;
    for (int i = 1; i < 201; ++i) dp[0][i][i] = (2*dp[0][i-1][i-1])%MOD;
    for (int i = 1; i < 201; ++i) dp[i][0][i] = (2*dp[i-1][0][i-1])%MOD;
    for (int i = 1; i < 201; ++i) dp[i][i][0] = (2*dp[i-1][i-1][0])%MOD;
    for (int i = 1; i < 201; ++i) {
        for (int j = 1; j < 201; ++j) {
            for (int k = 1; k < 201; ++k) {
                if((i+j+k)%2 == 0) dp[i][j][k] = (2*(dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i][j-1][k-1]))%MOD;
            }
        }
    }
    while (cin >> n >> b >> v) {
        cout << dp[n][b][v] << endl;
    }
}
