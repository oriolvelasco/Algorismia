#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

VVI G;

int main() {
    int n;
    while (cin >> n) {
        G = VVI(n, VI(n, false));
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            G[x][y] = true;
        }
        for (int i = 0; i < n; i++) G[i][i] = true;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    G[i][j] = G[i][j] or (G[i][k] and G[k][j]);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                cout << G[i][j];
            }
            cout << endl;
        }
        cout << "--------------------" << endl;
    }
}
