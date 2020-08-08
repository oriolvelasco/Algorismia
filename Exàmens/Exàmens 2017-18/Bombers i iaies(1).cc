#include <iostream>
#include <vector>
using namespace std;

void back(vector<int>& escoles, int anterior, int actual, int& g, int i, int& maxim, int maxactual, int gactual) {
    if (i == escoles.size() or g == gactual) {
        maxim = max (maxim, maxactual);
        return;
    }
    if (escoles.size()-i < g-gactual) return;

    back(escoles, actual, 0, g, i+1, maxim, maxactual, gactual);
    if(actual == 1) maxactual += escoles[i]/2;
    else maxactual += escoles[i];
    if(i+1 < escoles.size()) maxactual += escoles[i+1]/2;
    if(anterior != 2 and i > 0) maxactual += escoles[i-1]/2;
    back(escoles, 2, 1, g, i+1, maxim, maxactual, gactual+1);

    return;
}

int main() {
    int g, n;
    while (cin >> g >> n) {
        vector<int> escoles(n);
        for (int i = 0; i < n; ++i) cin >> escoles[i];
        int maxim = 0;
        back(escoles, 0, 0, g, 0, maxim, 0, 0);
        cout << maxim << endl;
    }
}
Jutge.org 
