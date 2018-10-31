#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int a, b, n;
VVB ocup;
VB used;
VI alt, ampl;

int f(int i, int j) {
    if(i == a) return 1;
    if(j == b) return f(i+1, 0);
    if(ocup[i][j]) return f(i, j+1);
    int res = 0;
    for (int k = 0; k < n; ++k) {
        if(not used[k] and i + alt[k] - 1 < a and j + ampl[k] - 1 < b) {
            bool okay = true;
            for (int m = 0; m < ampl[k]; ++m) {
                if (ocup[i][j+m]) okay = false;
            }
            if(okay) {
                used[k] = true;
                for (int l = 0; l  < alt[k]; ++l) {
                    for (int m = 0; m < ampl[k]; ++m) {
                        ocup[i+l][j+m] = true;
                    }
                }
                res += f(i, j+1);
                for (int l = 0; l  < alt[k]; ++l) {
                    for (int m = 0; m < ampl[k]; ++m) {
                        ocup[i+l][j+m] = false;
                    }
                }
                used[k] = false;
            }
        }
    }
    return res;
}

int main() {
    int compt = 1;
    while (cin >> a >> b >> n) {
        ocup = VVB(a, VB(b, false));
        used = VB(n, false);
        alt = ampl = VI(n);
        for (int i = 0; i < n; ++i) cin >> alt[i] >> ampl[i];
        cout << '#' << compt << ": " << f(0, 0) << endl;
        ++compt;
    }
}
