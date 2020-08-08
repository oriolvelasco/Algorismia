#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef map<string, int> MSI;

VI pare;
VI amics;
MSI M;

int repre(int i) {
    if (pare[i] == i) return i;
    pare[i] = repre(pare[i]);
    return pare[i];
}

void uneix(int i, int j) {
    if (repre(i) != repre(j)) {
        amics[repre(j)] += amics[repre(i)];
        pare[repre(i)] = repre(j);
    }
}

int main() {
    char c;
    while (cin >> c) {
        if (c == 'Q') {
            string s;
            cin >> s;
            if (M.find(s) == M.end()) cout << s << ": error" << endl;
            else cout << s << ": " << amics[repre(M[s])] << endl;
        }
        else {
            int n;
            cin >> n;
            string s1;
            cin >> s1;
            if (M.find(s1) == M.end()) {
                int mida = pare.size();
                M[s1] = mida;
                pare.push_back(mida);
                amics.push_back(1);
            }
            for (int i = 1; i < n; ++i) {
                string s;
                cin >> s;
                if (M.find(s) == M.end()) {
                    int mida = pare.size();
                    M[s] = mida;
                    pare.push_back(mida);
                    amics.push_back(1);
                }
                uneix(M[s], M[s1]);
            }
        }
    }
}
