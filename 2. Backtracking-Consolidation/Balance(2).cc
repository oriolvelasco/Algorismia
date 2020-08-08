#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n;
VI v;
VB used;

int f(int sum, int i) {
    if(sum < 0) return 0;
    if(i == n) return 1;
    int res = 0;
    for (int j = 0; j < n; ++j) {
        if(not used[j]) {
            used[j] = true;
            res += f(sum+v[j], i+1) + f(sum-v[j], i+1);
            used[j] = false;
        }
    }
    return res;
}

int main() {
    while (cin >> n) {
        v = VI(n);
        used = VB(n, false);
        for (int i = 0; i < n; ++i) cin >> v[i];
        cout << f(0, 0) << endl;
    }
}
