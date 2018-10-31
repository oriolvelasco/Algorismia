#include <iostream>
#include <vector>
using namespace std;

void DFS (vector<vector<int> >& tauler, int& num, int fil, int col, vector<int>& numcas) {
    int n = tauler.size();
    int m = tauler[0].size();
    tauler[fil][col] = num;
    ++numcas[num];
    if(fil > 0 and tauler[fil-1][col] == -2) DFS(tauler, num, fil-1, col, numcas);
    if(fil < n-1 and tauler[fil+1][col] == -2) DFS(tauler, num, fil+1, col, numcas);
    if(col > 0 and tauler[fil][col-1] == -2) DFS(tauler, num, fil, col-1, numcas);
    if(col < m-1 and tauler[fil][col+1] == -2) DFS(tauler, num, fil, col+1, numcas);
}

int main() {
    int f, c;
    cin >> f >> c;
    vector<vector<int> > tauler (f, vector<int> (c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j){
            char x;
            cin >> x;
            if(x == 'X') tauler[i][j] = -2;
            else tauler[i][j] = -1;
        }
    }
    int num = 0;
    vector<int> numcas;
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j){
            if(tauler[i][j] == -2) {
                numcas.push_back(0);
                DFS(tauler, num, i, j, numcas);
                ++num;
            }
        }
    }
    vector<vector<bool> > tocat(f, vector<bool> (c, false));
    int numenfonsats = 0;
    bool fi = false;
    bool repeated = false;
    int x, y;
    while (cin >> x >> y and fi == false) {
        cout << x << ' ' << y << ": ";
        --x;
        --y;
        if(tocat[x][y] == true) {
            cout << "REPEATED" << endl;
            fi = true;
            repeated = true;
        }
        else {
            tocat[x][y] = true;
            if(tauler[x][y] == -1) cout << "miss" << endl;
            else {
                --numcas[tauler[x][y]];
                if(numcas[tauler[x][y]] > 0) cout << "hit" << endl;
                else {
                    cout << "hit and sunk" << endl;
                    ++numenfonsats;
                    if(numenfonsats == num) {
                        fi = true;
                        cout << "VICTORY" << endl;
                    }
                }
            }
        }
    }
    if (not fi and not repeated) cout << "UNFINISHED" << endl;
}
