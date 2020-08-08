#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n;
VI v;
VB used;

void escriu() {
    cout << '(';
    for (int j = 0; j < n; ++j) {
        if (j != 0) cout << ',';
        cout << v[j]+1;
    }
    cout << ')' << endl;
}

void f(int i, int pos){
    if (i == n) return escriu();
    if (i == n - 1) {
        if(v[pos] > 0) return;
        int aux = v[pos];
        v[pos] = 0;
        f(i + 1, 0);
        v[pos] = aux;
        return;
    }
    if (v[pos] == 0) return;
    if (v[pos] > 0) {
        f(i + 1, v[pos]);
        return;
    }
    for (int j = 1; j < n; ++j) {
        if (not used[j]) {
            used[j] = true;
            v[pos] = j;
            f(i + 1, j);
            v[pos] = -1;
            used[j] = false;
        }
    }
}

int main() {
    cin >> n;
    v = VI(n);
    used = VB(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        --v[i];
        if (v[i] >= 0) used[v[i]] = true;
    }
    f(0,0);
}
