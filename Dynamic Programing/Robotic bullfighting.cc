#include <iostream>
#include <vector>
using namespace std;

int main() {
    int w, h, c;
    cin >> w >> h >> c;
    vector<vector<int> > mat(h+1, vector<int> (w+1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> mat[i][j];
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    int maxim = 0;
    int fil = 0;
    int col = 0;
    for (int i = 0; i <= h - c; ++i) {
        for (int j = 0; j <= w - c; ++j) {
            int val = mat[i][j] + mat[i+c][j+c] - mat[i+c][j] - mat[i][j+c];
            if(val > maxim) {
                maxim = val;
                fil = i;
                col = j;
            }
        }
    }
    cout << fil << ' ' << col << endl;
}
