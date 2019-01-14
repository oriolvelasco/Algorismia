#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using P = pair<int, int>;
using PP = pair<int, P>;
using VI = vector<int>;
using VVI = vector<VI>;

int k_esim(int k, const VVI& V) {
    int n = V.size();
    priority_queue<PP> Q;
    for (int i = 0; i < n; i++) {
        if (V[i].size() > 0) {
            Q.push(PP(-V[i][0], P(i, 0)));
        }
    }
    for (int j = 1; true; j++) {
        PP a = Q.top(); Q.pop();
        int fila = a.second.first;
        int columna = a.second.second;
        int elem = -a.first;
        if (j == k) return elem;
        if (columna < V[fila].size()-1) {
            PP in(-V[fila][columna+1], P(fila, columna+1));
            Q.push(in);
        }
    }
}

int main() {
    int k;
    cin >> k;
    VVI V = {{1, 5000, 5001, 5002}, {2, 2001, 2002}, {100, 101}};
    cout << k_esim(k, V) << endl;
}
