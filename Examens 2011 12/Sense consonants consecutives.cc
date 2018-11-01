#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<char> VC;
typedef vector<bool> VB;

int n;
int v;
VC paraula, lletres;
VB used;
int compt = 0;

void f(int i, int voc) {
    if(n+voc-i-v>v-voc+1) return;
    if(i == n) {
        for (int j = 0; j < n; ++j) cout << paraula[j];
        cout << endl;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if(not used[j]) {
            used[j] = true;
            paraula[i] = lletres[j];
            if(lletres[j] == 'a' or lletres[j] == 'e' or lletres[j] == 'i' or lletres[j] == 'o' or lletres[j] == 'u') f(i+1,voc+1);
            else if (i == 0 or paraula[i-1] == 'a' or paraula[i-1] == 'e' or paraula[i-1] == 'i' or paraula[i-1] == 'o' or paraula[i-1] == 'u') f(i+1,voc);
            used[j] = false;
        }
    }
}

int main() {
    while (cin >> n) {
        v = 0;
        paraula = lletres = VC(n);
        used = VB(n, false);
        for (int i = 0; i < n; ++i) {
            cin >> lletres[i];
            if(lletres[i] == 'a' or lletres[i] == 'e' or lletres[i] == 'i' or lletres[i] == 'o' or lletres[i] == 'u') ++v;
        }
        sort(lletres.begin(),lletres.end());
        f(0,0);
    }
}
