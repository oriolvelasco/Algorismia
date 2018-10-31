#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        string t = "";
        for (int i = s.size()-1; i >= 0; --i) t += s[i];
        vector<vector<int> > M(s.size()+1, vector<int> (s.size()+1, 0));
        for (int i = 1; i <= s.size(); ++i) M[i][0] = M[0][i] = i;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if(s[i-1] == t[j-1]) M[i][j] = M[i-1][j-1];
                else M[i][j] = 1 + min(M[i-1][j], M[i][j-1]);
            }
        }
        if(M[s.size()][s.size()] == 0) cout << "Passes the Dislex-Wonga test" << endl;
        else cout << M[s.size()][s.size()]/2 << endl;
    }
}
