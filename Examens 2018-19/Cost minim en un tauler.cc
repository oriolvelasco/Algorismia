#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        VVI cost(n, VI(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> cost[i][j];
            }
        }
        VVVI dp(n, VVI(m, VI(k+1, 1e7)));
        //dp[i][j][c] es el cost minim per arribar a la posicio (i,j)
        //amb com a molt c salts de cavall
        for (int j = 0; j < m; ++j) {
            for (int c = 0; c < k + 1; ++c) {
                dp[0][j][c] = cost[0][j];
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int c = 0; c < k + 1; ++c) {
                    int minaux = dp[i - 1][j][c];
                    if (j > 0) 
                        minaux = min(minaux, dp[i - 1][j - 1][c]);
                    if (j < m - 1) 
                        minaux = min(minaux, dp[i - 1][j + 1][c]);
                    if (c > 0 and j > 1) 
                        minaux = min(minaux, dp[i - 1][j - 2][c - 1]);
                    if (c > 0 and j > 0 and i > 1) 
                        minaux = min(minaux, dp[i - 2][j - 1][c - 1]);
                    if (c > 0 and j < m - 2) 
                        minaux = min(minaux, dp[i - 1][j + 2][c - 1]);
                    if (c > 0 and j < m - 1 and i > 1) 
                        minaux = min(minaux, dp[i - 2][j + 1][c - 1]);
                    dp[i][j][c] = cost[i][j] + minaux;
                }
            }
        }
        int minim = dp[n-1][0][k];
        for (int j = 1; j < m; ++j) minim = min(minim, dp[n - 1][j][k]);
        cout << minim << endl;
    }
}
