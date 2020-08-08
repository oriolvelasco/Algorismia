#include <iostream>
#include <vector>
using namespace std;

const int N = 100000007;

int main() {
    int n, f;
    while (cin >> n >> f) {
        vector<int> v(n, -1);
        for (int i = 0; i < f; ++i) {
            int pos;
            char c;
            cin >> pos >> c;
            v[pos] = c - 'a';
        }
        bool incorrecte = false;
        for (int i = 1; i < n; ++i) if(v[i-1] == v[i] and v[i] != -1) incorrecte = true;
        vector<vector<int> > dp(n, vector<int> (3, 0));
        if(v[0] != -1) dp[0][v[0]] = 1;
        else dp[0][0] = dp[0][1] = dp[0][2] = 1;
        for(int i = 1; i < n; ++i) {
            if(v[i] == 0) dp[i][0] = (dp[i-1][1] + dp[i-1][2])%N;
            else if(v[i] == 1) dp[i][1] = (dp[i-1][0] + dp[i-1][2])%N;
            else if(v[i] == 2) dp[i][2] = (dp[i-1][1] + dp[i-1][0])%N;
            else {
                dp[i][0] = (dp[i-1][1] + dp[i-1][2])%N;
                dp[i][1] = (dp[i-1][0] + dp[i-1][2])%N;
                dp[i][2] = (dp[i-1][1] + dp[i-1][0])%N;
            }
        }
        cout << (dp[n-1][0]+dp[n-1][1]+dp[n-1][2])%N << endl;

    }
}
