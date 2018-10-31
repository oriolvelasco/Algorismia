#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<long long> > M(50, vector<long long> (50, 0));
    for (int i = 0; i < 50; ++i) {
        vector<vector<long long> > mat(50, vector<long long> (i+1, 1));
        for (int j = 1; j < 50; ++j) {
            for (int k = 0; k < i+1; ++k) {
                mat[j][k] = 0;
                if(k > 0) mat[j][k] += mat[j-1][k-1];
                if(k < i) mat[j][k] += mat[j-1][k+1];
                M[i][j] += mat[j][k];
            }
        }
        M[i][0] = i+1;
    }
    M[0][0] = 1;
    int r, c;
    while (cin >> r >> c) {
        cout << M[c-1][r-1] << endl;
    }
}
