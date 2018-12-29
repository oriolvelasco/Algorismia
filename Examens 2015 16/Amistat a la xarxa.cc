#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

int n, q;
VI pare, numamics;

int busca(int i) {
    if(i == pare[i]) return i;
    pare[i] = busca(pare[i]);
    return pare[i];
}

int uneix(int i, int j) {
    pare[busca(i)]= busca(j);
}

int main() {
    while(cin >> n >> q) {
        pare = VI(n);
        numamics = VI(n);
        for(int i = 0; i < n; ++i) {
            pare[i] = i;
            numamics[i] = 1;
        }
        for(int i = 0; i < q; ++i){
            char c;
            cin >> c;
            if(c == 'c') {
                int x;
                cin >> x;
                cout << numamics[busca(x-1)] << endl;
            }
            else {
                int x, y;
                cin >> x >> y;
                if(busca(x-1) != busca(y-1)) {
                    numamics[busca(y-1)] += numamics[busca(x-1)];
                    uneix(x-1, y-1);
                }
            }
        }
        cout << "----------" << endl;
    }
}
