#include <iostream>
#include <vector>
using namespace std;

const int N = 100000007;


int main() {
    string s, t, u;
    while(cin >> s >> t >> u) {
        vector<vector<int> > M(t.size()+1, vector<int> (s.size()+1, 0));
        M[0][0] = 1;
        for (int i = 0; i <= t.size(); ++i) {
            for (int j = 0; j <= s.size(); ++j) {
                if (j > 0 and s[j-1] == u[i+j-1]) M[i][j] = (M[i][j] + M[i][j-1])%N;
                if (i > 0 and t[i-1] == u[i+j-1]) M[i][j] = (M[i][j] + M[i-1][j])%N;
            }
        }
        cout << M[t.size()][s.size()] << endl;
    }
}
