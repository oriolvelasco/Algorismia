#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n, x;
VI v;

void f(int i) {
    if(i == n) {
        for (int j = 0; j < n; ++j) cout << char('a'+v[j]);
        cout << endl;
        return;
    }
    for (int j = 0; j < x; ++j) {
        if(i == 0 or (i == 1 and j != v[0]) or (i > 1 and j != v[i-1] and j != v[i-2])) {
            v[i] = j;
            f(i+1);
        }
    }
}

int main() {
    while (cin >> n >> x) {
        v = VI(n);
        f(0);
    }
}
