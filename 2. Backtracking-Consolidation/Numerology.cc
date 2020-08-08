#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;

int N;
string m;
long long n;
VB v;
bool trobat;

long long eleva10(int k) {
    if(k == 0) return 1;
    return 10*eleva10(k-1);
}

void f(int i, long long res, long long act) {
    if (i == N) {
        if(res+act == n){
            trobat = true;
            cout << n << " = " << m[0];
            for (int j = 0; j < N; ++j) {
                if(v[j] == 1) cout << " + ";
                cout << m[j+1];
            }
            cout << endl;
        }
        return;
    }
    if(res+act > n or res+(act+1)*eleva10(N-i) < n) return;
    v[i] = true;
    f(i+1, res + act, m[i+1]-'0');
    v[i] = false;
    f(i+1, res, 10*act+m[i+1]-'0');
}

int main() {
    while (cin >> n >> m) {
        N = m.size() - 1;
        trobat = false;
        v = VB(N, false);
        f(0, 0, m[0]-'0');
        if(not trobat) cout << "No solution for " << n << ' ' << m << '.' << endl;
    }
}
