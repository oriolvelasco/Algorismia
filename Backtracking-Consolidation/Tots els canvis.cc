#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI monedes = {50, 20, 10, 5, 2, 1};
VI v;

void f(int num, int imax) {
    if(num < 0) return;
    if(num == 0) {
        for (int i = 0; i < v.size(); ++i) {
            if (i != 0) cout << ' ';
            cout << v[i];
        }
        cout << endl;
        return;
    }
    for (int i = imax; i < 6; ++i) {
        v.push_back(monedes[i]);
        f(num - monedes[i], i);
        v.pop_back();
    }
}

int main() {
    int n;
    while (cin >> n) {
        f(n, 0);
        cout << endl;
    }
}
