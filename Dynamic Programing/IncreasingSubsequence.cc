#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> VL;


VL F;
string s;

//retorna el numero de increasing subsequences acabant en la posiciรณ
//k de la paraula.
ll f(int k) {
    if(F[k] != -1) return F[k];
    if(k == 0) {
        F[k] = 0;
        return F[k];
    }
    F[k] = 0;
    for(int i = 0; i < k; ++i) {
        if(s[i] < s[k]) F[k] += f(i) + 1;
    }
    return F[k];
}


int main() {
  while (cin >> s) {
    F = VL(s.size(), -1);
    int res = 0;
   
    for(int i = 1; i < s.size(); ++i) {
        res += f(i);
    }
      cout << res << endl;
  }
}
