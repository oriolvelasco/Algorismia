#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;

int n, m;
VVS tauler;
VVI component;

int valor(string s) {
    int mida = s.length();
    int val = s[0] - '0';
    for (int i = 1; i < mida; ++i) val = 10*val + s[i] - '0';
    return val;
}

void DFS(int i, int j, int& suma, int& elements, int& comp) {
    if(i < 0 or j < 0 or j >= m or i >= n) return;
    if(tauler[i][j] == "X" or component[i][j] != -1) return;
    ++elements;
    suma += valor(tauler[i][j]);
    component[i][j] = comp;
    DFS(i+1, j+1, suma, elements, comp);
    DFS(i+1, j-1, suma, elements, comp);
    DFS(i-1, j+1, suma, elements, comp);
    DFS(i-1, j-1, suma, elements, comp);
}

bool OK() {
    component = VVI(n, VI(m, -1));
    int comp = 0;
    int num = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(component[i][j] == -1 and tauler[i][j] != "X") {
                int suma = 0;
                int elements = 0;
                DFS(i, j, suma, elements, comp);
                if(suma%elements != 0) return false;
                if(num == -1) num = suma/elements;
                else if(num != suma/elements) return false;
                ++comp;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; ++k) {
        cin >> n >> m;
        tauler = VVS(n, VS(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> tauler[i][j];
            }
        }
        cout << "Case " << k+1 << ": ";
        if(OK()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
