#include <iostream>
#include <vector>
using namespace std;

void accio(int f, vector<int> &v, vector<int> &t, int c) {
    if(f == 0) {
        for(int i = 0; i < v.size(); ++i) {
            for(int j = 0; j < c; ++j) {
                if(j == v[i]) cout << 'R';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    vector<int> T;
    for(int i = 0; i < t.size(); ++i) {
        for(int j = 0; j < t.size(); ++j) if(j != i) T.push_back(t[j]);
        v[v.size() - f] = t[i];
        accio(f - 1, v, T, c);
        for(int j = 0; j < t.size() - 1; ++j) T.pop_back();
    }
}

int main() {
    int f, c;
    while(cin >> f >> c) {
        vector<int> v(f);
        vector<int> t(c);
        for(int i = 0; i < c; ++i) t[i] = i;
        accio(f, v, t, c);
    }
}
