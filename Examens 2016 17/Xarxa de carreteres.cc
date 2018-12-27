#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<pair<int, pair<int, int> > > VP;

int n, m;
VI pare;

int busca(int i) {
    if(pare[i] == i) return i;
    pare[i] = busca(pare[i]);
    return pare[i];
}

int uneix(int i, int j) {
    pare[busca(i)] = busca(j);
}

int main() {
    while(cin >> n >> m) {
        pare = VI(n);
        VP prescindibles;
        int cost = 0;
        for(int i = 0; i < n; ++i) pare[i] = i;
        for(int i = 0; i < m; ++i) {
            int x, y, c;
            char k;
            cin >> x >> y >> c >> k;
            if(k == 'I') {
                cost += c;
                uneix(x, y);
            }
            else prescindibles.push_back(make_pair(c, make_pair(x, y)));
        }
        sort(prescindibles.begin(), prescindibles.end());
        int m1 = prescindibles.size();
        for(int i = 0; i < m1; ++i) {
            int c = prescindibles[i].first;
            int x = prescindibles[i].second.first;
            int y = prescindibles[i].second.second;
            if(busca(x) != busca(y)){
                cost += c;
                uneix(x, y);
            }
        }
        cout << cost << endl;
    }
}
