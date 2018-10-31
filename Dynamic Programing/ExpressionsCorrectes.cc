// Nombres de Fibonacci amb PD.


#include <iostream>
#include <vector>
using namespace std;


const int N = 26;
int m;


typedef long long ll;
typedef vector<ll> VL;


VL F;


ll f(int n) {
  if (F[n] != 0) return F[n];
  if (n == 1) {
    F[n] = m;
    return F[n];
  }

  if (n == 0) return 0;

  F[n] = f(n - 2);

  if(n - 5 > 0) {
    int i = 1;
    int j = n - 5 - i;
  	while(i < n - 5 and j > 0) {
      F[n] += f(i)*f(j);
      i += 2;
      j -= 2;
    }
  }

  return F[n];
}


int main() {
  int n;
  while (cin >> n >> m) {
    if(n%2 == 0) cout << 0 << endl;
    else {
      F = VL(N, 0);
    	cout << f(n) << endl;
    }
  }
}
