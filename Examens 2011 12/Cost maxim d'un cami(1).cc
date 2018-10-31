#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

int n, x, millor;
VI ordre;
VVI costos;
VB used;

void f(int i, int cost) {
    if (cost > millor) millor = cost;
    if(i == n) return;
    for (int j = 0; j < n; ++j) {
        if(not used[j]) {
            used[j] = true;
            ordre[i] = j;
            f(i+1, cost+costos[ordre[i-1]][j]);
            used[j] = false;
        }
    }
}

int main() {
    while(cin >> n) {
        ordre = VI(n);
        costos = VVI(n, VI(n));
        used = VB(n, false);
        for (int i = 0; i < n; ++i) for(int j = 0;j < n; ++j) cin >> costos[i][j];
        cin >> x;
        millor = -1000000000;
        used[x] = true;
        ordre[0] = x;
        f(1,0);
        cout << millor << endl;
    }
}
