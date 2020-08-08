#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<string> VS;

int n, millor;
VI ordre, millorordre;
VVI manies;
VB used;
VS noms;

void f(int i, int actual) {
    if(actual >= millor) return;
    if(i == n) {
        millor = actual;
        for (int j = 0; j < n; ++j) millorordre[j] = ordre[j];
        return;
    }
    for(int j = 0; j < n; ++j) {
        if(not used[j]) {
            used[j] = true;
            ordre[i] = j;
            f(i+1, actual+manies[ordre[i-1]][j]);
            used[j] = false;
        }
    }
    return;
}

int main() {
    while(cin >> n) {
        ordre = VI(n);
        millorordre = VI(n);
        manies = VVI(n, VI(n));
        used = VB(n, false);
        noms = VS(n);
        for (int i = 0; i < n; ++i) cin >> noms[i];
        for (int i = 0; i < n; ++i) for(int j = 0;j < n; ++j) cin >> manies[i][j];
        millor = 1000000000;
        ordre[0] = 0;
        used[0] = true;
        f(1, 0);
        cout << millor << endl;
        for (int i = 0; i < n; ++i) {
            if(i != 0) cout << ' ';
            cout << noms[millorordre[i]];
        }
        cout << endl;
    }
}
