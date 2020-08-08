#include <iostream>
#include <vector>
using namespace std;

int main() {
    int W, L;
    while (cin >> W >> L) {
        vector<vector<int> > mat(L, vector<int> (W,-1));
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < W; ++j) {
                char c;
                cin >> c;
                if (c == 'M') mat[i][j] = 0;
                if (c == 'T') mat[i][j] = -3;
                if (c == '*' or (i == 0 and c != 'M')) mat[i][j] = -2;
            }
        }
        for (int i = 1; i < L; ++i) {
            for (int j = 0; j < W; ++j) {
                if (mat[i][j] != -2) {
                    int val = 0;
                    if (mat[i][j] == -3) val = 3;
                    if(j > 0 and mat[i-1][j-1] != -2) mat[i][j] = mat[i-1][j-1] + 1;
                    if(mat[i-1][j] != -2) {
                        if(mat[i][j] < 0) mat[i][j] = mat[i-1][j];
                        else mat[i][j] = min(mat[i][j],mat[i-1][j]);
                    }
                    if(j < W - 1 and mat[i-1][j+1] != -2) {
                        if(mat[i][j] < 0) mat[i][j] = mat[i-1][j+1] + 1;
                        else mat[i][j] = min(mat[i][j],mat[i-1][j+1] + 1);
                    }
                    if (mat[i][j] < 0) mat[i][j] = -2;
                    else mat[i][j] += val;
                }
            }
        }
        int minim = -2;
        for (int i = 0; i < W; ++i) {
            if (minim < 0 and mat[L-1][i] >= 0) minim = mat[L-1][i];
            else if(minim >= 0 and mat[L-1][i] >= 0) minim = min(minim, mat[L-1][i]);
        }
        if(minim < 0) cout << "IMPOSSIBLE" << endl;
        else cout << minim << endl;
    }
}
