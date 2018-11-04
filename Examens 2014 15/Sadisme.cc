#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<int> VE;

int n, m;
VS pers, act;
VVB Des;
VB usat;
VE perm;

void escriu() {
    for (int i = 0; i < n; ++i) cout << pers[i] << " " << act[perm[i]] << endl;
    cout << string(20,'.') << endl;
}

//Calcula totes les permutacions permeses de les activitats en les persones
void resol(int pos) {
    if (pos == n) return escriu();
    for (int i = 0; i < m; ++i) if (not usat[i] and Des[pos][i]) {
        usat[i] = true;
        perm[pos] = i;
        resol(pos + 1);
        usat[i] = false;
    }

}

int main() {
    while (cin >> n) {
        pers = VS(n);
        for (int i = 0; i < n; ++i) cin >> pers[i];
        cin >> m;
        act = VS(m);
        for (int i = 0; i < m; ++i) cin >> act[i];
        Des = VVB(n, VB(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a;
                cin >> a;
                Des[i][j] = a;
            }
        }
        usat = VB(m, false);
        perm = VE(n);
        resol(0);
        cout << string(30,'-') << endl;
    }
}
