#include <iostream>
#include <vector>

using namespace std;

int n, g;
vector<vector<int> > M1, M2;
vector<int> iaies;

int prot0(int i, int j);

//Màxim nombre de iaies que es poden protegir de les primeres j+1 escoles amb i bombers si a l'escola j+1 hi ha un grup de bombers
int prot1(int i, int j) {
    if (j == -1) return 0;
    int& res = M2[i][j];
    if (res != -1) return res;
    if (i == 0) return res = iaies[j]/2;
    return res = max(iaies[j] + prot1(i-1, j-1), iaies[j]/2 + prot0(i, j-1));
}

//Màxim nombre de iaies que es poden protegir de les primeres j+1 escoles amb i bombers si a l'escola j+1 no hi ha un grup de bombers
int prot0(int i, int j) {
    if (j == -1) return 0;
    int& res = M1[i][j];
    if (res != -1) return res;
    if (i == 0) return res = 0;
    int a = (j != n-1);
    return res = max(iaies[j] + a*iaies[j+1]/2 + prot1(i-1, j-1), prot0(i, j-1));
}

int main() {
    while (cin >> g >> n) {
        iaies = vector<int> (n);
        for (int i = 0; i < n; ++i) cin >> iaies[i];
        M1 = M2 = vector<vector<int> > (g + 1, vector<int>(n, -1));
        cout << prot0(g, n-1) << endl;
    }
}
