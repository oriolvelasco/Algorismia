#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, t, u;
    while(cin >> s >> t >> u) {
        vector<vector<int> > M(t.size()+1, vector<int> (s.size()+1, 0));
        M[0][0] = 1;
        for (int i = 0; i <= t.size(); ++i) {
            for (int j = 0; j <= s.size(); ++j) {
                if (j > 0 and s[j-1] == u[i+j-1]) M[i][j] = max(M[i][j-1], M[i][j]);
                if (i > 0 and t[i-1] == u[i+j-1]) M[i][j] = max(M[i-1][j], M[i][j]);
            }
        }
        if(M[t.size()][s.size()] == 0) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}
