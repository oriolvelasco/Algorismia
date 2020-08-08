#include <iostream>
#include <vector>
using namespace std;

typedef vector<long long> VL;
typedef vector<VL> VVL;
const long long M = 1000000007;
VVL f;

int main() {
    int n, k;
    f = VVL(1001, VL(501,0));
    f[2][1] = 1;
    //recurrencia f(n,k) = (n-1)*f(n-1,k)+(n-1)*f(n-2)(k-2);
    for (int i = 3; i < 1001; ++i) {
        for (int j = 1; j <= i/2; ++j) {
            f[i][j] = ((i-1)*f[i-1][j]+(i-1)*f[i-2][j-1])%M;
        }
    }
    while (cin >> n >> k) {
        cout << f[n][k] << endl;
    }
}
