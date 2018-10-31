#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<vector<int> > > dp(600, vector<vector<int> > (20, vector<int> (10, 0)));
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(11);
    v.push_back(13);
    v.push_back(17);
    v.push_back(19);
    v.push_back(23);
    v.push_back(29);
    for (int i = 0; i < 10; ++i) dp[v[i]][0][i] = 1;
    for (int i = 1; i < 20; ++i) {
        // i es el numero de monedes (-1)
        for (int j = 0; j < 600; ++j) {
            //j es el valor
            for (int k = 0; k < 10; ++k) {
                //v[k] es el valor de la moneda mes alta
                for (int l = 0; l <= k; ++l) {
                    if(j >= v[k]) dp[j][i][k] += dp[j-v[k]][i-1][l];
                }
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int c, val;
        cin >> c >> val;
        if(val > 590) cout << 0 << endl;
        else{
            int sum = 0;
            for (int j = 0; j < 10; ++j) sum += dp[val][c-1][j];
            cout << sum << endl;
        }
    }
}
