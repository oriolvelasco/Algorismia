#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;

int n, a, b, c;
VC v;

void f(int i, int a1, int b1, int c1) {
    if (a1 < 0 or b1 < 0 or c1 < 0) return;
    if (i == n) {
        for (int j = 0; j < n; ++j) cout << v[j];
        cout << endl;
        return;
    }
    v[i] = 'a';
    f(i + 1, a1 - 1, b1, c1);
    v[i] = 'b';
    f(i + 1, a1, b1 - 1, c1);
    v[i] = 'c';
    f(i + 1, a1, b1, c1 - 1);
}

int main() {
    while (cin >> n >> a >> b >> c) {
        v = VC(n);
        f(0, a, b, c);
        cout << "----------" << endl;
    }
}
