#include <iostream>
#include <vector>

using namespace std;


int n;
vector<bool> VN;
vector<int> VE;


void escriu(){
    vector<int> cicle(n, VE[0]);
    for (int j = 1; j < n - 1; ++j) cicle[VE[j - 1] - 1] = VE[j];
    cicle[VE[n - 2] - 1] = 1;
    cout << '(' << cicle[0];
    for (int i = 1; i < n; ++i) {
        cout << ',' << cicle[i];
    }
    cout << ')' << endl;
}

void comb(int k) {
    if (k == n - 1) escriu();
    for (int i = 0; i < n - 1; ++i) {
        if(not VN[i]) {
            VN[i] = 1;
            VE[k] = i + 2;
            comb(k + 1);
            VN[i] = 0;
        }
    }
}

//buscarem les permutacions de (2,...,n) perquè estan en bijecció amb els n-cicles
int main(){
    cin >> n;
    VN = vector<bool>(n - 1, 0);
    VE = vector<int>(n - 1, 1);
    if (n == 1) cout << "(1)" << endl;
    else comb(0);
}
