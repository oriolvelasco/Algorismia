// Suma cantonades subrectangles


#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V;
typedef vector<V> Taula;
typedef vector<char> C;
typedef vector<C> TaulaChar;


Taula M;
int n, m;

V valors;

const int lletres = 26;



int ompleValors(int i) {
  if(valors[i] != 0) return valors[i];

  if(i == 0) {
    valors[i] = 1;
    return valors[i];
  }
  
  valors[i] = i+1 + ompleValors(i-1);

  return valors[i]; 
}


int main() {
  valors = V(lletres, 0);
  int k = ompleValors('Z'-'A');
  V fila;


  string ubec;
  while(getline(cin, ubec)) {
    int n = M.size();
    if(n == 0) fila = V(ubec.size(), 0);
    else fila = M[n-1];

    for (int i = 0; i < ubec.size(); ++i) {
      fila[i] += valors[ubec[i] - 'A'];
      if(i > 0) {
        fila[i] += fila[i-1];
        if(n > 0) fila[i] -= M[n-1][i-1];
      }
        
    }

    M.push_back(fila);
  }

  for (int i = 0; i < M.size(); ++i) {
    for (int j = 0; j < M[0].size(); ++j) {
      cout << M[i][j];
      if(j != M[0].size() -1) cout << " ";
    }
    cout << endl;
  }

}
