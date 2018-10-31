#include <iostream>
#include <vector>
using namespace std;


const int N = 91;


typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> Taula;


Taula F01(N, VL(N, -1));
Taula F11(N, VL(N, -1));
Taula F0(N, VL(N, -1));

ll f01(int z, int u);
ll f11(int z, int u);
ll f0(int z, int u);

ll f01(int z, int u) {
  if(z < 0 or u < 0) return 0;
  if(F01[z][u] != -1) return F01[z][u];

  if(z <= 1 and u == 1) {
    F01[z][u] = 1;
    return F01[z][u];
  }

  F01[z][u] = f0(z, u-1);
  return F01[z][u];
}

ll f11(int z, int u) {
  if(z < 0 or u < 0) return 0;
  if(F11[z][u] != -1) return F11[z][u];

  if(z == 0 and u == 2) {
    F11[z][u] = 1;
    return F11[z][u];
  }

  F11[z][u] = f01(z, u-1);
  return F11[z][u];
}

ll f0(int z, int u) {
  if(z < 0 or u < 0) return 0;
  if(F0[z][u] != -1) return F0[z][u];

  if(z == 1 and u <= 1) {
    F0[z][u] = 1;
    return F0[z][u];
  }

  F0[z][u] = f01(z-1, u) + f11(z-1, u);
  return F0[z][u];
}

int main() {
  int z, u;

  while (cin >> z >> u) {
    if(z == 0 and u == 0) cout << 1 << endl;
  	else cout << f0(z, u) + f01(z, u) + f11(z, u) << endl;
  }
}
