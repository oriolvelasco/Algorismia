#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n;
VI nombres, x, y;
VB used;

void f(int i) {
    if (i == 2*n) {
        for (int j = 0; j < n; ++j) {
            if(j != 0) cout << ' ';
            cout << x[j];
        }
        cout << endl;
        for (int j = 0; j < n; ++j) {
            if(j != 0) cout << ' ';
            cout << y[j];
        }
        cout << endl << endl;
        return;
    }
    if (i < n) {
        for (int j = i; j < 2*i+1; ++j) {
            if(not used[j]) {
                used[j] = true;
                x[i] = nombres[j];
                if(i == 0 or nombres[j] > x[i-1]) f(i+1);
                used[j] = false;
            }
        }
    }
    else {
        i = i-n;
        for (int j = 2*i+1; j < n+i+1; ++j) {
            if(not used[j]) {
                used[j] = true;
                y[i] = nombres[j];
                if((i == 0 or nombres[j] > y[i-1]) and y[i] > x[i]) f(i+n+1);
                used[j] = false;
            }
        }
    }
}

int main() {
    while (cin >> n) {
        nombres = VI(2*n);
        for (int i = 0; i < 2*n; ++i)  cin >> nombres[i];
        sort(nombres.begin(), nombres.end());
        x = y = VI(n);
        used = VB(n, false);
        f(0);
    }
}
