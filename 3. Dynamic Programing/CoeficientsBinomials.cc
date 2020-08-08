// Nombres combinatoris amb PD.


#include <iostream>
#include <vector>
using namespace std;


const int N = 101;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


VVL C(N, VL(N, -1));


// nombre binomial amb n i x
ll f(int n, int x) {
  if (C[n][x] != -1) return C[n][x];
  if (x == 0 or x == n) return C[n][x] = 1;
  return C[n][x] = f(n - 1, x - 1) + f(n - 1, x);
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << f(n, x) << endl;
}
