// Suma cantonades subrectangles

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> Vec;

const int N = 68;

Vec F(N, 0);


ll f(int n) {
  if (F[n] != 0) return F[n];
  if(n <= 1) {
    F[n] = 1;
    return F[n];
  }

  int i = 0;
  while(i <= n-1 and n-i-1 >= 0) {
    F[n] += f(n-1-i)*f(i);
    ++i;
  }
  return F[n];
}


int main() {
  int n;

  while(cin >> n) {
    if(n%2 == 1) cout << 0 << endl;
    else cout << f(n/2) << endl;
  }
}
