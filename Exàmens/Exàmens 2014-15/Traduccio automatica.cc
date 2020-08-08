#include <iostream>
#include <vector>
#include <map>
using namespace std;

using VI = vector<int>;
using VS = vector<string>;
using it = map<string, int>::iterator;

int n, m;
VS words;
VI perm, used;
VI translate;

void escriu() {
    for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << words[perm[translate[i]]];
    }
    cout << endl;
}

void backtrack(int i) {
    if (i == n) return escriu();
    
    for (int j = 0; j < n; j++) {
        if (not used[j]) {
            used[j] = true;
            perm[i] = j;
            backtrack(i+1);
            used[j] = false;
        }
    }
}

int main() {
    while (cin >> n) {
        map<string, int> dict;
        perm = VI(n);
        used = VI(n, false);
        words = VS(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        cin >> m;
        translate = VI(m);
        int k = 0; //index de l'element actual
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            bool cont = true;
            it iter = dict.find(s);
            if (iter == dict.end()) {
                dict[s] = k;
                translate[i] = k;
                k++;
            }
            else {
                translate[i] = iter->second;
            }
        }
        backtrack(0);
        cout << "----------" << endl;
    }
}
