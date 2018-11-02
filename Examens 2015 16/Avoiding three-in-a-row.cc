#include <iostream>
#include <vector>
using namespace std;

//P51064_en
//Avoiding three-in-a-row
int n, m;
typedef vector<char> VC;
typedef vector<VC> VVC;
VVC MAP;

//Returns true if there is a three-in-a-row (by column)
bool three_col(int i, int j, char c) {
    //Checking
    //   (1)      (2)      (3)
    //   |M|      |.|      |.|
    //   |.|      |.|      |M|
    //   |.|      |M|      |.|
    if (i+2 < n and MAP[i+1][j] == c and MAP[i+2][j] == c) return true;
    if (i-2 >= 0 and MAP[i-2][j] == c and MAP[i-1][j] == c) return true;
    if (i-1 >= 0 and i+1 < n and MAP[i-1][j] == c and MAP[i+1][j] == c) return true;
    return false;
}

//Returns true if there is a three-in-a-row (by row)
bool three_row(int i, int j, char c) {
    //Checking
    //    (1)      (2)        (3)
    //   |M..|    |..M|      |.M.|
    if (j+2 < m and MAP[i][j+1] == c and MAP[i][j+2] == c) return true;
    if (j-2 >= 0 and MAP[i][j-2] == c and MAP[i][j-1] == c) return true;
    if (j-1 >= 0 and j+1 < m and MAP[i][j-1] == c and MAP[i][j+1] == c) return true;
    return false;
}

//Prints the matrix
void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << MAP[i][j];
        cout << endl;
    }
    cout << string(10, '-') << endl;
}

void f(int i, int j) {
    if (i == n and j == 0) return print();
    if (j == m) return f(i+1, 0); //Next row
    if (MAP[i][j] != '.') return f(i, j+1); //Cell marked with O or X
    //It's possible to write O
    if (not three_col(i, j, 'O') and not three_row(i, j, 'O')) {
        MAP[i][j] = 'O';
        f(i, j+1);
        MAP[i][j] = '.';
    }
    //It's possible to write X
    if (not three_col(i, j, 'X') and not three_row(i, j, 'X')) {
        MAP[i][j] = 'X';
        f(i, j+1);
        MAP[i][j] = '.';
    }
    return;
}

int main() {
    while (cin >> n >> m) {
        MAP = VVC(n, VC(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> MAP[i][j];
        }
        f(0,0);
        cout << string(20, '*') << endl;
    }
}
