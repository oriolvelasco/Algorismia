#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;

int n, v, x;
VC paraula;

void f(int i, int voc) {
    if(voc > v or i-voc > n-v) return; // no ens passem de vocals ni consonants
    if(n+voc-i-v > v-voc+1) return; // descartem paraules impossibles sense dues consonants consecutives
    if(i == n) {
        for (int j = 0; j < n; ++j) cout << paraula[j];
        cout << endl;
        return;
    }
    for(int j = 0; j < x; ++j) {
        paraula[i] = char('a'+j);
        if(j == 'a'-'a' or j == 'e'-'a' or j == 'i'-'a' or j == 'o'-'a' or j == 'u'-'a') f(i+1,voc+1);
        else if(i == 0 or paraula[i-1] == 'a' or paraula[i-1] == 'e' or paraula[i-1] == 'i' or paraula[i-1] == 'o' or paraula[i-1] == 'u') f(i+1, voc);
    }
}

int main() {
    cin >> n >> v >> x;
    paraula = VC(n);
    f(0,0);
}
