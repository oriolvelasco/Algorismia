#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

int n;
VVI graf;
int minim;
VB used;
VI ordre;

void f(int i, int cost) {
    if (i == n) {
        if(minim > cost) minim = cost;
        for (int j = 0; j < n; ++j){
            if(j != 0) cout << ' ';
            cout << ordre[j]+1;
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if(not used[j] and graf[ordre[i-1]][j] != 0) {
            used[j] = true;
            ordre[i] = j;
            f(i+1, cost+graf[ordre[i-1]][j]);
            used[j] = false;
        }
    }
}

int main() {
    while (cin >> n){
        graf = VVI(n, VI(n));
        minim = 15000000;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cin >> graf[i][j];
        }
        ordre = VI(n);
        used = VB(n, false);
        used[0] = true;
        ordre[0] = 0;
        f(1,0);
        cout << "min: " << minim << endl;
    }
}
