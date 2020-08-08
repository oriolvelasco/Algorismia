#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI arriben;
VI longmax;


//retorna la longitud del camí de llargada maxima que acaba al node i
int dp(int i) {
    if(arriben[i].size() == 0) longmax[i] = 0;
    if(longmax[i] != -1) return longmax[i];
    int maxim = 0;
    for(int j = 0; j < arriben[i].size(); ++j) {
        maxim = max(maxim, dp(arriben[i][j]));
    }
    longmax[i] = maxim+1;
    return longmax[i];
}

int main() {
    int n, m;
    while(cin >> n >> m){
        longmax = VI(n, -1);
        arriben = VVI(n);
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            arriben[y].push_back(x);
        }
        int maxim = 0;
        for(int i = 0; i < n; ++i) maxim = max(maxim, dp(i));
        cout << maxim << endl;
    }
}
Jutge.org 
