#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M,N;
    while (cin >> M >> N) {
        vector<int> u(M);
        vector<int> v(N);
        for (int i = 0; i < M; ++i) cin >> u[i];
        for (int i = 0; i < N; ++i) cin >> v[i];
        vector<vector<int> > mat(M+1, vector<int> (N+1, 0));
        for (int i = 1; i < M+1; ++i) {
            for (int j = 1; j < N+1; ++j) {
                if(u[i-1] == v[j-1]) mat[i][j]=1+mat[i-1][j-1];
                else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
        cout << mat[M][N] << endl;
    }
}
