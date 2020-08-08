#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> ME;
typedef vector<ME> QE;


ME M(9, VE(9));
ME fila, colu;
QE quad;


void escriu() {
  cout << endl;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cout << M[i][j];
      if(j != 8) cout << " ";
    }
    cout << endl;
  }
}


bool sudoku(int i, int j) {
  if (i == 9) {
    escriu();
    return true;
  }

  if (j == 9) return sudoku(i + 1, 0);

  if (M[i][j]) return sudoku(i, j + 1);

  for (int x = 1; x <= 9; ++x)
    if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
      M[i][j] = x;
      if (sudoku(i, j + 1)) return true;
      M[i][j] = 0;
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
    }
  return false;
}


int main() {
  int t;
  cin >> t;
  cout << t << endl;
  for (int k = 0; k < t; ++k) {
    fila = colu = ME(9, VE(10, false));
    quad = QE(3, ME(3, VE(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.') M[i][j] = 0;
        else {
          int x = c - '0';
          M[i][j] = x;
          fila[i][x] = true;
          colu[j][x] = true;
          quad[i/3][j/3][x] = true;
        }
      }
    sudoku(0, 0);
  }
}
