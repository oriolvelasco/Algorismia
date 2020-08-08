#include <iostream>
#include <stack>
using namespace std;

void escriu(int n) {
  stack<int> pila;
  bool entrat = false;
  cout << " " << n;
  --n;
  while (n >= 0) {
    if(n == 0 and not pila.empty()){
       n = pila.top();
       pila.pop();
       entrat = true;
     }
    if (n != 0) cout << " " << n;
    if (not entrat) pila.push(n);
    --n;
    entrat = false;
  }
}

int main() {
  int n;
  while (cin >> n) {
    escriu(n);
    cout << endl;
  }
}
