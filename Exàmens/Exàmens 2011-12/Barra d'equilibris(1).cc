#include <iostream>
#include <vector>
using namespace std;

void accio(vector<int>& salts, int i, int pos, int& m){
    if(pos > m/2 or pos < -(m/2)) return;
    if(i == salts.size()){
        cout << pos << endl;
        return;
    }
    accio(salts, i + 1, pos + salts[i], m);
    accio(salts, i + 1, pos - salts[i], m);
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> salts(n);
    for(int i = 0; i < n; ++i) cin >> salts[i];
    accio(salts, 0, 0, m);
}
