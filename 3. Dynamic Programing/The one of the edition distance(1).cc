#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> l(n);
        for (int i = 0; i < n; ++i) cin >> l[i];
        string s, t;
        cin >> s >> t;
        vector<vector<int> > M(s.size()+1, vector<int> (t.size()+1, 0));
        for (int i = 1; i <= s.size(); ++i) M[i][0] = M[i-1][0] + l[s[i-1]-'a'];
        for (int j = 1; j <= t.size(); ++j) M[0][j] = M[0][j-1] + l[t[j-1]-'a'];
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i-1] == t[j-1]) M[i][j] = M[i-1][j-1];
                else M[i][j] = min(M[i-1][j] + l[s[i-1]-'a'], M[i][j-1] + l[t[j-1]-'a']);
            }
        }
        cout << M[s.size()][t.size()] << endl;
    }
}
