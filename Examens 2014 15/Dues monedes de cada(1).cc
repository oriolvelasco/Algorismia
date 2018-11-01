#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int x, n;
VI v, sumaposteriors;
VB used;

void f(int i, int suma) {
    if(i == 2*n) {
        if(suma == x) {
            cout << x << " =";
            bool primer = true;
            for (int j = 0; j < 2*n; ++j) {
                if(used[j]) {
                    if(primer) {
                        cout << " ";
                        primer = false;
                    }
                    else cout << " + ";
                    if(j%2 == 0) cout << v[j];
                    else cout << v[j] << 'p';
                }
            }
            cout << endl;
        }
        return;
    }
    if(suma > x) return;
    if(suma + sumaposteriors[i] < x) return;
    used[i] = true;
    f(i+1, suma+v[i]);
    used[i] = false;
    f(i+1, suma);
}

int main() {
    while (cin >> x >> n) {
        v = VI(2*n);
        used = VB(2*n, false);
        sumaposteriors = VI(2*n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> v[2*i];
            v[2*i+1] = v[2*i];
        }
        sort(v.begin(), v.end());
        sumaposteriors[2*n-1] = v[2*n-1];
        for (int i = 2*n-2; i >= 0; --i) sumaposteriors[i] = sumaposteriors[i+1]+v[i];
        f(0,0);
        cout << "----------" << endl;
    }
}
