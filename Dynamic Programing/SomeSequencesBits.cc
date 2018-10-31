#include <iostream>
#include <vector>
using namespace std;


const int N = 151;


typedef long long ll;
typedef vector<ll> VL;


VL Total(N);
VL Zeros(N);
VL ZerosUn(N);
VL UnUn(N);


int main() {
  Zeros[2] = ZerosUn[2] = UnUn[2] = 1;
  Total[0] = 1;
  Total[1] = 2;
  Total[2] = 3;

  for (int i = 3; i < N; ++i)
  {
    Zeros[i] = ZerosUn[i-1] + UnUn[i-1];
    ZerosUn[i] = Zeros[i-1];
    UnUn[i] = ZerosUn[i-1];
    Total[i] = Zeros[i] + ZerosUn[i] + UnUn[i];
  }

  int n;

  while (cin >> n) {
  	cout << Total[n] << endl;
  }
}
