#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> ti(n);
        for (int j = 0; j < n; ++j) cin >> ti[j];
        vector<int> v(n, 1);
        v[0] = 1;
        int maxim = 1;
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < j; ++k) {
                if(ti[j]-ti[k] >= 10) v[j] = max(v[j], 1+v[k]);
            }
            maxim = max(maxim, v[j]);
        }
        cout << maxim << endl;
    }
}
